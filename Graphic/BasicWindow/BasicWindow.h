#ifndef BASICWINDOW_H_
# define BASICWINDOW_H_

# include <pebble.h>

# include "../../GarbageCollector/GarbageCollector.h"

Window		*create_window(void (*)(Layer *, GContext *));

#endif
