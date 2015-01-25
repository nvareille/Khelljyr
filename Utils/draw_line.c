#include "Utils.h"

void		draw_line(int x, int y, int x1, int y1, GContext *ctx)
{
  GPoint	p[2];

  p[0].x = x;
  p[0].y = y;
  p[1].x = x1;
  p[1].y = y1;
  graphics_draw_line(ctx, p[0], p[1]);
}
