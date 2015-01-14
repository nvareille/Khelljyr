#ifndef BASICMENUSCENE_H_
# define BASICMENUSCENE_H_

# include <pebble.h>

# include "../Graphic.h"

/**
 * Creates a basic menu and push it on the graphic stack
 * @param sections The section structure array that must be displayed
 * @param load The initialization callback to be handled by the window
 * @param unload The uninitialization callback to be handled by the window
 * @param section_size The number of elements in the sections array
 */
void	create_basic_menu_scene(SimpleMenuSection *sections, void (*load)(Window *), void (*unload)(Window *), int32_t section_size);

#endif
