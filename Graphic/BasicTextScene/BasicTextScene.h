#ifndef BASICTEXTSCENE_H_
# define BASICTEXTSCENE_H_

# include <pebble.h>
# include "../Graphic.h"

/**
 * Create a scrolling text layer. The layer will destroy itself automaticaly. You may destroy it with window_stack_pop.
 * @param str The string to display on the layer
 * @param load The loading Callback
 * @param unlaod The unloading Callback
 */
void		create_basic_text_scene(char *str, void (*load)(Window *), void (*unload)(Window *));

#endif
