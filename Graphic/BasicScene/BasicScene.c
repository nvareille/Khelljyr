#include "BasicScene.h"

# include "../../Debug/Debug.h"

static void	free_layer(void *data)
{
  layer_destroy(data);
}

static void	fct_basic_scene(void (*fct)(Layer *, GContext *), void (*load)(Window *), void (*unload)(Window *), void (*click)(), bool full)
{
  GraphicStack	*stack = alloc(sizeof(GraphicStack));
  Window	*window = create_window(fct, load, unload);
  GRect		rect;

  window_set_fullscreen(window, full);
  graphic_stack_push(stack);
  stack->window = window;
  stack->layer[WINDOW_LAYER] = window_get_root_layer(window);
  rect = layer_get_frame(stack->layer[WINDOW_LAYER]);
  stack->layer[LAYER] = resource_handle(layer_create(rect), free_layer);
  layer_set_update_proc(stack->layer[LAYER], fct);
  layer_add_child(stack->layer[WINDOW_LAYER], stack->layer[LAYER]);
  window_set_click_config_provider(window, click);
  window_stack_push(window, true);
}

void		create_basic_scene(void (*fct)(Layer *, GContext *), void (*load)(Window *), void (*unload)(Window *), void (*click)())
{
  fct_basic_scene(fct, load, unload, click, false);
}

void		create_basic_scene_fullscreen(void (*fct)(Layer *, GContext *), void (*load)(Window *), void (*unload)(Window *), void (*click)())
{
  fct_basic_scene(fct, load, unload, click, true);
}
