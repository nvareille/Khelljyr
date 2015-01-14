#ifndef GRAPHIC_H_
# define GRAPHIC_H_

# include "BasicWindow/BasicWindow.h"
# include "BasicScene/BasicScene.h"
# include "BasicMenuScene/BasicMenuScene.h"

# define WINDOW_LAYER 0
# define LAYER 1

typedef struct		s_GraphicStack
{
  Window		*window;
  void			*layer[2];
  struct s_GraphicStack	*next;
}			GraphicStack;

typedef struct		s_Graphic
{
  GraphicStack		*stack;
}			Graphic;

# define GRAPHIC_PTR ((Graphic *)scopper(NULL, 1))

void			graphic_stack_push(GraphicStack *);
void			graphic_stack_pop();
void			refresh();

#endif
