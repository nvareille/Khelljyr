#include "BasicInvertLayer.h"

#ifdef PBL_PLATFORM_APLITE
static void		free_layer(void *data)
{
  InvertLayer		*layer = data;

  inverter_layer_destroy(layer->inv);
  free(layer);
}
#endif

InvertLayer		*create_invert_layer(int x, int y, int width, int height)
{
  #ifdef PBL_PLATFORM_APLITE
  InvertLayer		*layer = custom_alloc(sizeof(InvertLayer), free_layer);
  GRect			rect;

  rect.origin.x = x;
  rect.origin.y = y;
  rect.size.w = width;
  rect.size.h = height;
  layer->inv = inverter_layer_create(rect);
  layer->layer = inverter_layer_get_layer(layer->inv); 
  layer_add_child(GRAPHIC_PTR->stack->layer[WINDOW_LAYER], layer->layer);
  return (layer);
  #else
  return (NULL);
  #endif
}

void			invert_set_size(InvertLayer *inv, int x, int y)
{
  GRect			rect;

  rect = layer_get_frame(inv->layer);
  rect.size.w = x;
  rect.size.h = y;
  layer_set_frame(inv->layer, rect);
}

void			invert_set_pos(InvertLayer *inv, int x, int y)
{
  GRect			rect;

  rect = layer_get_frame(inv->layer);
  rect.origin.x = x;
  rect.origin.y = y;
  layer_set_frame(inv->layer, rect);
}
