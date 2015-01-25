#ifndef BASICINVERTEDLAYER_H_
# define BASICINVERTEDLAYER_H_

# include <pebble.h>
# include "../../MemoryManager/MemoryManager.h"
# include "../Graphic.h"

typedef struct	s_InvertLayer
{
  Layer		*layer;
  InverterLayer	*inv;
}		InvertLayer;

/**
 * Creates an inverted layer on current window
 * @param x The x position of the layer
 * @param y The y position of the layer
 * @param width The width of the layer
 * @param height The height of the layer
 */
InvertLayer	*create_invert_layer(int x, int y, int width, int height);

/**
 * Sets the size of the layer
 * @param inv A pointer to the inverted layer
 * @param x The new layer's size on x
 * @param y The new layer's size on y
 */
void		invert_set_size(InvertLayer *inv, int x, int y);

/**
 * Sets the position of the layer
 * @param inv A pointer to the inverted layer
 * @param x The new layer's position on x
 * @param y The new layer's position on y
 */

void		invert_set_pos(InvertLayer *inv, int x, int y);

#endif
