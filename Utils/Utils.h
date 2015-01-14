#ifndef UTILS_H_
# define UTILS_H_

# include <pebble.h>

# define SIZE(ELEM) (sizeof(ELEM) / sizeof(*ELEM))

void	putstr(char *, int, int, GContext *);
void	putstr_font(char *, const char *, int, int, GContext *);

#endif
