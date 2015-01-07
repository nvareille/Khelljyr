#include "BasicScene.h"

static void	free_layer(void *data)
{
  layer_destroy(data);
}

void		create_basic_scene(void (*fct)(Layer *, GContext *), void (*load)(Window *), void (*unload)(Window *))
{
  GraphicStack	*stack = alloc(sizeof(GraphicStack));
  Window	*window = create_window(fct, load, unload);
  GRect		rect;

  graphic_stack_push(stack);
  stack->layer[WINDOW_LAYER] = window_get_root_layer(window);
  rect = layer_get_frame(stack->layer[WINDOW_LAYER]);
  stack->layer[LAYER] = ressource_handle(layer_create(rect), free_layer);
  layer_set_update_proc(stack->layer[LAYER], fct);
  layer_add_child(stack->layer[WINDOW_LAYER], stack->layer[LAYER]);
  window_stack_push(window, true);
}
