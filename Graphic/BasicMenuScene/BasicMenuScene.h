#ifndef BASICMENUSCENE_H_
# define BASICMENUSCENE_H_

# include <pebble.h>

# include "../Graphic.h"

void	create_basic_menu_scene(SimpleMenuSection *, void (*)(Window *), void (*)(Window *), int32_t);

#endif
