#include "BasicWindow.h"

static void		destroy_window(Window *window)
{
  GraphicStack		*stack = GRAPHIC_PTR->stack;

  if (stack->unload)
    stack->unload(window);
  graphic_stack_pop();
}

static void		free_window(void *ptr)
{
  window_destroy(ptr);
}

GraphicStack		*create_window(void (*fct)(Layer *, GContext *), void (*load)(Window *), void (*unload)(Window *))
{
  GraphicStack		*stack = alloc(sizeof(GraphicStack));
  WindowHandlers	handlers;

  create_resource_layer();
  stack->window = resource_handle(window_create(), free_window);
  handlers.load = load;
  handlers.unload = destroy_window;
  handlers.disappear = NULL;
  handlers.appear = NULL;
  stack->unload = unload;
  window_set_window_handlers(stack->window, handlers);
  graphic_stack_push(stack);
  return (stack);
}
