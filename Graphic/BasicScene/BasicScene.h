#ifndef BASICSCENE_H_
# define BASICSCENE_H_

# include <pebble.h>

# include "../BasicWindow/BasicWindow.h"
# include "../Graphic.h"

/**
 * Creates a blank screen where we can display anything
 * @param graphic_callback The callback that must be called to display something on screen
 * @param load The loading window_handler for the window
 * @param unload The unloading window_handler for the window
 * @param click_provider The function that contains click_providers
 */
void	create_basic_scene(void (*graphic_callback)(Layer *, GContext *), void (*load)(Window *), void (*unload)(Window *), void (*click_provider)());

/**
 * Creates a blank fullscreen where we can display anything
 * @param graphic_callback The callback that must be called to display something on screen
 * @param load The loading window_handler for the window
 * @param unload The unloading window_handler for the window
 * @param click_provider The function that contains click_providers
 */
void	create_basic_scene_fullscreen(void (*graphic_callback)(Layer *, GContext *), void (*load)(Window *), void (*unload)(Window *), void (*click_provider)());

#endif
