#include "Graphic.h"

void		graphic_stack_push(GraphicStack *s)
{
  s->next = GRAPHIC_PTR->stack;
  GRAPHIC_PTR->stack = s;
}

void		graphic_stack_pop()
{
  GraphicStack	*s;

  s = GRAPHIC_PTR->stack;
  if (s)
    GRAPHIC_PTR->stack = s->next;
  clean_resource_layer();
}

void		refresh()
{
  GraphicStack	*s;

  s = GRAPHIC_PTR->stack;
  if (s)
    layer_mark_dirty(GRAPHIC_PTR->stack->layer[LAYER]);
}
