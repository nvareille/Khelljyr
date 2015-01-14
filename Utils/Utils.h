#ifndef UTILS_H_
# define UTILS_H_

# include <pebble.h>

/**
 * This macro returns the size of an element in memory. It must be a pointer to work
 * @return size in bytes of an element
 */
# define SIZE(ELEM) (sizeof(ELEM) / sizeof(*ELEM))

/**
 * This function print some text on the watch screen.
 * @param str The string to display.
 * @param x The x coordinate on screen.
 * @param y The y coordinate on screen.
 * @param ctx The Graphical Context of the screen.
 */
void	putstr(char *str, int x, int y, GContext *ctx);

/**
 * This function print some text on the watch screen with selected font.
 * @param str The string to display.
 * @param font The selected font for the text.
 * @param x The x coordinate on screen.
 * @param y The y coordinate on screen.
 * @param ctx The Graphical Context of the screen.
 */
void	putstr_font(char *str, const char *font, int x, int y, GContext *ctx);

#endif
