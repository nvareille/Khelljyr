#ifndef KSTACK_H_
# define KSTACK_H_

# include "../../MemoryManager/MemoryManager.h"

/**
 * A container for the stack values
 */
typedef struct		s_KStackElem
{
  struct s_KStackElem	*next;
  void			*data;
}			KStackElem;

/**
 * A container for the stack
 */
typedef struct		s_KStack
{
  KStackElem		*elem;
  unsigned short	size;
}			KStack;

/**
 * Creates an empty stack
 * @return A ready to use KStack
 * @see KStack
 */
KStack			*create_kstack();

/**
 * Append a value on top of the stack
 * @param stack The KStack that must be modified
 * @param elem The value to be added
 */
void			kstack_push(KStack *stack, void *elem);

/**
 * Removes the value on the top of the stack
 * @param stack The stack that must be modified
 * @return The value that was on the stack
 */
void			*kstack_pop(KStack *stack);

/**
 * Empties the stack
 * @param stack The stack to be cleaned
 */
void			clean_kstack(KStack *stack);

/**
 * A convenience function to add values on the stack
 * @see kstack_push
 */
# define KSTACK_PUSH(STACK, ELEM) (kstack_push(STACK, (void *)ELEM))

#endif
