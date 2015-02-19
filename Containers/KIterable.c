#include "KIterable.h"

void		foreach(KIterable *it, KIterableCallback ptr, void *data)
{
  while (it)
    {
      if (ptr(it->data, data))
	return ;
      it = it->next;
    }
}
