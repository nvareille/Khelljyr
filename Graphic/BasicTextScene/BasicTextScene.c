#include "BasicTextScene.h"

static void	free_scroll_layer(void *data)
{
  scroll_layer_destroy(data);
}

static void	free_text_layer(void *data)
{
  text_layer_destroy(data);
}

void		create_basic_text_scene(char *str, void (*load)(Window *), void (*unload)(Window *))
{
  GraphicStack	*stack = create_window(NULL, load, unload);
  GRect		rect;

  stack->layer[WINDOW_LAYER] = window_get_root_layer(stack->window);
  rect = layer_get_frame(stack->layer[WINDOW_LAYER]);
  stack->layer[LAYER] = resource_handle(scroll_layer_create(rect), free_scroll_layer);
  layer_add_child(stack->layer[WINDOW_LAYER], stack->layer[LAYER]);
  layer_add_child(stack->layer[WINDOW_LAYER], scroll_layer_get_layer(stack->layer[LAYER]));
  scroll_layer_set_click_config_onto_window(stack->layer[LAYER], stack->window);
  GRect max_text_bounds = GRect(0, 0, rect.size.w, 2000);
  stack->layer[WINDOW_LAYER] = resource_handle(text_layer_create(max_text_bounds), free_text_layer);
  text_layer_set_text(stack->layer[WINDOW_LAYER], str);
  text_layer_set_font(stack->layer[WINDOW_LAYER], fonts_get_system_font(FONT_KEY_GOTHIC_14_BOLD));
  GSize max_size = text_layer_get_content_size(stack->layer[WINDOW_LAYER]);
  text_layer_set_size(stack->layer[WINDOW_LAYER], max_size);
  scroll_layer_set_content_size(stack->layer[LAYER], GSize(rect.size.w, max_size.h + 4));
  scroll_layer_add_child(stack->layer[LAYER], text_layer_get_layer(stack->layer[WINDOW_LAYER]));
  window_stack_push(stack->window, true);
}
