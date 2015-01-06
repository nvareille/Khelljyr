#include "GarbageCollector.h"
#include "../Debug/Debug.h"

static void	basic_ptr_cleaner(void *data)
{
  free(data);
}

static void	clean_ressource(Ressource *data)
{
  data->ptr(data->data);
  free(data);
}

void		*custom_alloc(size_t size, void (*ptr)(void *))
{
  Ressource	*ressource;

  ressource = malloc(sizeof(Ressource));
  ressource->data = malloc(size);
  ressource->ptr = ptr;
  ressource->next = GARBAGECOLLECTOR_PTR->ressources;
  GARBAGECOLLECTOR_PTR->ressources = ressource;
  ++GARBAGECOLLECTOR_PTR->size;
  return (ressource->data);
}

void		*alloc(size_t size)
{
  return (custom_alloc(size, basic_ptr_cleaner));
}

void		clean(void *ptr)
{
  Ressource	*r;
  Ressource	**prev;

  r = GARBAGECOLLECTOR_PTR->ressources;
  prev = &GARBAGECOLLECTOR_PTR->ressources;
  if (!r)
    return ;
  while (r)
    {
      if (r->data == ptr)
	{
	  *prev = r->next;
	  clean_ressource(r);
	  --GARBAGECOLLECTOR_PTR->size;
	  return ;
	}
      prev = &r->next;
      r = r->next;
    }
  DUMP("Khelljyr: Bad Pointer Cleaning (%p)", ptr);
}

void		clean_collector(GarbageCollector *collector)
{
  Ressource	*r[2];

  r[0] = collector->ressources;
  while (r[0])
    {
      r[1] = r[0];
      r[0] = r[0]->next;
      clean_ressource(r[1]);
    }
}
