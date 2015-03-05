#ifndef IMG_H_
# define IMG_H_

# include <pebble.h>
# include "../MemoryManager/MemoryManager.h"

/**
 * This structure describes an Image. It contains it's position and data.
 */
typedef struct	s_Img
{
  GBitmap	*image;
  GRect		blit;
}		Img;

/**
 * Creates an Image based on the RESOURCE_ID passed in parameter
 * @param resource_id the picture id to load
 * @return a pointer to Img that have been loaded
 */
Img		*create_img(uint32_t resource_id);

/**
 * Creates an Image based on the RESOURCE_ID passed in parameter and sets its position
 * @param resource_id the picture id to load
 * @param x the x position of the picture
 * @param y the y position of the picture
 * @return a pointer to Img that have been loaded
 */
Img		*create_img_pos(uint32_t resource_id, short x, short y);

/**
 * Draw the picture on the pebble screen to its previoulsy set position
 * @param Image the image to be displayed
 * @param ctx The graphical context
 */
void		draw_img(Img *Image, GContext *ctx);

/**
 * Draw the picture on the pebble screen to the given position
 * @param Image the image to be displayed
 * @param x the x position of the picture
 * @param y the y position of the picture
 * @param ctx The graphical context
 */
void		draw_img_pos(Img *Image, int x, int y, GContext *ctx);

/**
 * Sets the picture position on screen
 * @param Image The picture to treat
 * @param x the position in x to set
 * @param y the position in y to set
 */
void		set_img_pos(Img *Image, int x, int y);

/**
 * Draw the picture with an effect on it
 * @param Image the image to be displayed
 * @param Effect The effect to be used on picture
 * @param ctx The graphical context
 */
void		draw_img_effect(Img *Image, GCompOp Effect, GContext *ctx);

/**
 * Draw the picture with an effect on it at given coordinates
 * @param Image the image to be displayed
 * @param Effect The effect to be used on picture
 * @param x the x position of the picture
 * @param y the y position of the picture
 * @param ctx The graphical context
 */
void		draw_img_effect_pos(Img *Image, GCompOp Effect, int x, int y, GContext *ctx);

#endif
