#include "BasicWindow.h"

static void	free_window(void *ptr)
{
  window_destroy(ptr);
}

static void	free_layer(void *ptr)
{
  layer_destroy(ptr);
}

Window		*create_window(void (*fct)(Layer *, GContext *))
{
  Window	*window;
  Layer		*layer[2];
  GRect		rect;
  
  window = ressource_handle(window_create(), free_window);
  layer[0] = window_get_root_layer(window);
  rect = layer_get_frame(layer[0]);
  layer[1] = ressource_handle(layer_create(rect), free_layer);
  layer_set_update_proc(layer[0], fct);
  layer_add_child(layer[0], layer[1]);
  return (window);
}
