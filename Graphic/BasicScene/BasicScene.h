#ifndef BASICSCENE_H_
# define BASICSCENE_H_

# include <pebble.h>

# include "../BasicWindow/BasicWindow.h"
# include "../Graphic.h"

void	create_basic_scene(void (*)(Layer *, GContext *), void (*)(Window *), void (*)(Window *));

#endif
