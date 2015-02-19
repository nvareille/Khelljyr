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

/**
 * Writes on screen text following the given callback format
 * @param size The size of the string the callback will receive
 * @param ptr The callback that will do the snprintf formating
 * @param data The data given to the callback
 * @param x The x coordinate to display text
 * @param y The y coordinate to display text
 * @param ctx The Graphical context of the window
 */
void	putstr_format(size_t size, void (*ptr)(void *, char *, size_t), void *data, int x, int y, GContext *ctx);

/**
 * Writes on screen text following the given callback format with custom font
 * @param size The size of the string the callback will receive
 * @param ptr The callback that will do the snprintf formating
 * @param data The data given to the callback
 * @param font The custom font to use
 * @param x The x coordinate to display text
 * @param y The y coordinate to display text
 * @param ctx The Graphical context of the window
 */
void	putstr_format_font(size_t size, void (*ptr)(void *, char *, size_t), void *data, const char *font, int x, int y, GContext *ctx);

#endif
