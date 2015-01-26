#include "Utils.h"

void	putstr_font(const char *str, const char *key, int x, int y, GContext *ctx)
{
  graphics_context_set_text_color(ctx, GColorBlack);
  graphics_draw_text(ctx, str,
		     fonts_get_system_font(key),
		     GRect(x, y - 3, 144 - x, 168 - y),
		     GTextOverflowModeWordWrap,
		     GTextAlignmentLeft,
		     NULL);
}

void	putstr(const char *str, int x, int y, GContext *ctx)
{
  putstr_font(str, FONT_KEY_GOTHIC_14, x, y, ctx);
}
