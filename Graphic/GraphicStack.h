#ifndef GRAPHICSTACK_H_
# define GRAPHICSTACK_H_

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
  void			*stack_ptr;
  void			(*unload)(Window *);
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

/**
 * Get the user data from window stack
 * @return The previously stored user data
 */
void			*get_window_data();

/**
 * Stores a data in the curent window
 * @param data The user data to store
 */
void			set_window_data(void *data);

/**
 * Removes the upper window of the stack from the stack. It acts the same as window_stack_pop but calls the unload callback of the window
 */
void			window_pop();

#endif
