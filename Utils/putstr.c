#include "Utils.h"

void	putstr(char *str, int x, int y, GContext *ctx)
{
  graphics_context_set_text_color(ctx, GColorBlack);
  graphics_draw_text(ctx, str,
		     fonts_get_system_font(FONT_KEY_GOTHIC_14),
		     GRect(x, y, 144 - x, 168 - y),
		     GTextOverflowModeWordWrap,
		     GTextAlignmentLeft,
		     NULL);
}
