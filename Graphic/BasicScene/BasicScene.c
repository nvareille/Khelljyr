#include "BasicScene.h"

# include "../../Debug/Debug.h"

static void	free_layer(void *data)
{
  layer_destroy(data);
}

static void	fct_basic_scene(void (*fct)(Layer *, GContext *), void (*load)(Window *), void (*unload)(Window *), void (*click)(), bool full)
{
  GraphicStack	*stack = create_window(fct, load, unload);
  GRect		rect;

  #ifdef PBL_PLATFORM_APLITE
  window_set_fullscreen(stack->window, full);
  #endif
  stack->layer[WINDOW_LAYER] = window_get_root_layer(stack->window);
  rect = layer_get_frame(stack->layer[WINDOW_LAYER]);
  stack->layer[LAYER] = resource_handle(layer_create(rect), free_layer);
  layer_set_update_proc(stack->layer[LAYER], fct);
  layer_add_child(stack->layer[WINDOW_LAYER], stack->layer[LAYER]);
  window_set_click_config_provider(stack->window, click);
  window_stack_push(stack->window, true);
}

void		create_basic_scene(void (*fct)(Layer *, GContext *), void (*load)(Window *), void (*unload)(Window *), void (*click)())
{
  fct_basic_scene(fct, load, unload, click, false);
}

void		create_basic_scene_fullscreen(void (*fct)(Layer *, GContext *), void (*load)(Window *), void (*unload)(Window *), void (*click)())
{
  fct_basic_scene(fct, load, unload, click, true);
}
