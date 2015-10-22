#include "BasicMenuScene.h"

static void	free_simple_menu_layer(void *data)
{
  simple_menu_layer_destroy(data);
}

void		create_basic_menu_scene(const SimpleMenuSection *sections, void (*load)(Window *), void (*unload)(Window *), int32_t size)
{
  GraphicStack	*stack = create_window(NULL, load, unload);
  GRect		rect;

  #ifdef PBL_PLATFORM_APLITE
  window_set_fullscreen(stack->window, true);
  #endif
  stack->layer[WINDOW_LAYER] = window_get_root_layer(stack->window);
  rect = layer_get_frame(stack->layer[WINDOW_LAYER]);
  stack->layer[LAYER] = resource_handle(simple_menu_layer_create(rect, stack->window, sections, size, NULL), free_simple_menu_layer);
  layer_add_child(stack->layer[WINDOW_LAYER], simple_menu_layer_get_layer(stack->layer[LAYER]));
  window_stack_push(stack->window, true);
}
