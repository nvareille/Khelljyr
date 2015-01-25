#ifndef GRAPHIC_H_
# define GRAPHIC_H_

# include "BasicWindow/BasicWindow.h"
# include "BasicScene/BasicScene.h"
# include "BasicMenuScene/BasicMenuScene.h"
# include "BasicTextScene/BasicTextScene.h"
# include "BasicInvertedLayer/BasicInvertedLayer.h"

/**
 * The index number for the GraphicStack array windows layer
 */
# define WINDOW_LAYER 0

/**
 * The index number for the GraphicStack array writable layer
 */
# define LAYER 1

/**
 * The GraphicStack that is used to know which layer is the least used 
 */
typedef struct		s_GraphicStack
{
  Window		*window;
  void			*layer[2];
  struct s_GraphicStack	*next;
}			GraphicStack;

/**
 * Container for the GraphicStack and Graphic properties
 */
typedef struct		s_Graphic
{
  GraphicStack		*stack;
}			Graphic;

/**
 * (Private function)
 * A Macro that returns the Graphic container of the Framework into with a pointer.
 */
# define GRAPHIC_PTR ((Graphic *)scopper(NULL, 1))

/**
 * (Private function)
 * Push a WindowHandling into Khelljyr's GraphicStack
 * @param value The value to push
 * @see GraphicStack
 */
void			graphic_stack_push(GraphicStack *value);

/**
 * (Private function)
 * Pop a WindowHandling out of Khelljyr's GraphicStack
 * @see GraphicStack
 */
void			graphic_stack_pop();

/**
 * Refresh the layer of the actual window on the Khelljyr's GraphicStack
 * @see GraphicStack
 */
void			refresh();

#endif
