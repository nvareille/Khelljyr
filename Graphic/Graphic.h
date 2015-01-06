#ifndef GRAPHIC_H_
# define GRAPHIC_H_

# include "BasicWindow/BasicWindow.h"

typedef struct		s_GraphicStack
{
  Window		*window;
  Layer			*layer;
  struct s_GraphicStack	*next;
}			GraphicStack;

typedef struct		s_Graphic
{
  GraphicStack		stack;
}			Graphic;

#endif
