#include "BasicWindow.h"

static void		destroy_window(Window *window)
{
  graphic_stack_pop();
}

static void		free_window(void *ptr)
{
  window_destroy(ptr);
}

Window			*create_window(void (*fct)(Layer *, GContext *), void (*load)(Window *), void (*unload)(Window *))
{
  Window		*window;
  Layer			*layer[2];
  WindowHandlers	handlers;

  create_ressource_layer();
  window = ressource_handle(window_create(), free_window);
  handlers.load = load;
  handlers.unload = unload ? unload : destroy_window;
  handlers.disappear = NULL;
  handlers.appear = NULL;
  window_set_window_handlers(window, handlers);
  return (window);
}
