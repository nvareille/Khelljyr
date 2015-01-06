#ifndef DEBUG_H_
# define DEBUG_H_

# include <pebble.h>

# define DUMP(STR, ARGS...) (APP_LOG(APP_LOG_LEVEL_DEBUG, STR, ARGS))
# define PRINT(STR) (APP_LOG(APP_LOG_LEVEL_DEBUG, STR))

#endif
