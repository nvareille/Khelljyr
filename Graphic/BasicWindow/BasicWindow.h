#ifndef BASICWINDOW_H_
# define BASICWINDOW_H_

# include <pebble.h>

# include "../../MemoryManager/MemoryManager.h"
# include "../Graphic.h"

/**
 * Create a window that is handled by the MemoryManager
 * @param graphic_callback The callback that is called for displaying something on pebble screen
 * @param load The loading callback for the window
 * @param unload The unloading callback for the window
 */
Window		*create_window(void (*graphic_callback)(Layer *, GContext *), void (*load)(Window *), void (*unload)(Window *));

#endif
