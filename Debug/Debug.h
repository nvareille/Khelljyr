#ifndef DEBUG_H_
# define DEBUG_H_

# include <pebble.h>

/**
 * This function displays a formated log (like printf) when user logs the pebble.
 * @param STR The formating string
 * @param ARGS the data to be displayed
 */
# define DUMP(STR, ARGS...) (APP_LOG(APP_LOG_LEVEL_DEBUG, STR, ARGS))

/**
 * This function displays a string when user logs the pebble
 * @param STR The string to be displayed
 */
# define PRINT(STR) (APP_LOG(APP_LOG_LEVEL_DEBUG, STR))

#endif
