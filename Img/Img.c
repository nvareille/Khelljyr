#include "Img.h"

static void		clean_image(void *data)
{
  gbitmap_destroy(((Img *)data)->image);
  free(data);
}

Img			*create_img_pos(uint32_t r, short x, short y)
{
  Img			*img;

  img = custom_alloc(sizeof(Img), clean_image);
  img->image = gbitmap_create_with_resource(r);
  img->blit.size = img->image->bounds.size;  
  img->blit.origin.x = x;
  img->blit.origin.y = y;
  return (img);
}

Img			*create_img(uint32_t r)
{
  return (create_img_pos(r, 0, 0));
}

void			draw_img(Img *img, GContext *ctx)
{
  graphics_draw_bitmap_in_rect(ctx, img->image, img->blit);
}

void			draw_img_pos(Img *img, int x, int y, GContext *ctx)
{
  GRect			p;

  p.size = img->image->bounds.size;
  p.origin.x = x;
  p.origin.y = y;
  graphics_draw_bitmap_in_rect(ctx, img->image, p);
}

void			set_img_pos(Img *img, int x, int y)
{
  img->blit.origin.x = x;
  img->blit.origin.y = y;
}

void			draw_img_effect(Img *img, GCompOp effect, GContext *ctx)
{
  graphics_context_set_compositing_mode(ctx, effect);
  draw_img(img, ctx);
  graphics_context_set_compositing_mode(ctx, GCompOpAssign);
}

void			draw_img_effect_pos(Img *img, GCompOp effect, int x, int y, GContext *ctx)
{
  graphics_context_set_compositing_mode(ctx, effect);
  draw_img_pos(img, x, y, ctx);
  graphics_context_set_compositing_mode(ctx, GCompOpAssign);
}
