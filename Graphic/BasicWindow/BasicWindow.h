#ifndef BASICWINDOW_H_
# define BASICWINDOW_H_

# include <pebble.h>

# include "../../MemoryManager/MemoryManager.h"
# include "../Graphic.h"

Window		*create_window(void (*)(Layer *, GContext *), void (*)(Window *), void (*)(Window *));

#endif
