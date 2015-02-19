#include "KStack.h"

KStack		*create_kstack()
{
  KStack	*stack = alloc(sizeof(KStack));

  stack->elem = NULL;
  stack->size = 0;
  return (stack);
}

void		kstack_push(KStack *stack, void *data)
{
  KStackElem	*elem = alloc(sizeof(KStackElem));

  elem->next = stack->elem;
  stack->elem = elem;
  elem->data = data;
  ++stack->size;
}

void		*kstack_pop(KStack *stack)
{
  KStackElem	*elem = stack->elem;
  void		*data = elem->data;

  stack->elem = elem->next;
  clean(elem);
  --stack->size;
  return (data);
}

void		clean_kstack(KStack *stack)
{
  KStackElem	*elem[2];

  elem[0] = stack->elem;
  while (elem[0])
    {
      elem[1] = elem[0];
      elem[0] = elem[0]->next;
      clean(elem[1]);
    }
  stack->size = 0;
  stack->elem = NULL;
}
