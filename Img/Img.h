#ifndef IMG_H_
# define IMG_H_

# include "../MemoryManager/MemoryManager.h"

typedef struct	s_Img
{
  GBitmap	*image;
  GRect		blit;
}		Img;

Img		*create_img(uint32_t);
void		draw_image(Img *, GContext *);
void		draw_image_pos(Img *, int, int, GContext *);
void		set_img_pos(Img *, int x, int y);
void		draw_image_effect(Img *, GCompOp, GContext *);
void		draw_image_effect_pos(Img *, GCompOp, int, int, GContext *);

#endif
