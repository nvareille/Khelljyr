#include "KList.h"

KList		*create_klist()
{
  KList		*list = alloc(sizeof(KList));

  list->elem = NULL;
  list->last = NULL;
  list->size = 0;
  return (list);
}

void		klist_push_front(KList *list, void *data)
{
  KListElem	*elem = alloc(sizeof(KListElem));

  elem->data = data;
  elem->next = list->elem;
  list->elem = elem;
  if (!list->last)
    list->last = elem;
  ++list->size;
}

void		klist_push_back(KList *list, void *data)
{
  KListElem	*elem = alloc(sizeof(KListElem));

  if (list->last)
    {
      elem->next = NULL;
      elem->data = data;
      list->last->next = elem;
      list->last = elem;
      ++list->size;
    }
  else
    klist_push_front(list, data);
}

void		*klist_pop_front(KList *list)
{
  KListElem	*elem;
  void		*data;

  elem = list->elem;
  data = elem->data;
  list->elem = elem->next;
  if (!list->elem)
    list->last = NULL;
  --list->size;
  clean(elem);
  return (data);
}

void		*klist_pop_back(KList *list)
{
  KListElem	*actual[2];
  void		*data; 

  if (list->size == 1)
    {
      data = list->elem->data;
      clean_klist(list);
    }
  else
    {
      actual[0] = list->elem;
      actual[1] = actual[0]->next;
      while (actual[1]->next)
	{
	  actual[0] = actual[1];
	  actual[1] = actual[1]->next;
	}
      data = actual[1]->data;
      actual[0]->next = NULL;
      list->last = actual[0];
      clean(actual[1]);
      --list->size;
    }
  return (data);
}

void		clean_klist(KList *list)
{
  KListElem	*elem[2];

  elem[0] = list->elem;
  while (elem[0])
    {
      elem[1] = elem[0];
      elem[0] = elem[0]->next;
      clean(elem[1]);
    }
  list->elem = NULL;
  list->last = NULL;
  list->size = 0;
}
