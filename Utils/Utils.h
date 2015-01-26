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
void	putstr(const char *str, int x, int y, GContext *ctx);

/**
 * This function print some text on the watch screen with selected font.
 * @param str The string to display.
 * @param font The selected font for the text.
 * @param x The x coordinate on screen.
 * @param y The y coordinate on screen.
 * @param ctx The Graphical Context of the screen.
 */
void	putstr_font(const char *str, const char *font, int x, int y, GContext *ctx);

/**
 * Draw a line on the screen
 * @param x The starting point on x
 * @param y The starting point on y
 * @param x2 The stopping point on x
 * @param y2 The stopping point on y
 * @param ctx The graphical context
 */
void	draw_line(int x, int y, int x2, int y2, GContext *ctx);

#endif
