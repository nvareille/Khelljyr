#include "MemoryManager.h"

static void		basic_ptr_cleaner(void *data)
{
  free(data);
}

static void		clean_ressource(Ressource *data)
{
  data->ptr(data->data);
  free(data);
}

static void		create_ressource(void *data, void (*ptr)(void *))
{
  Ressource		*ressource;

  ressource = malloc(sizeof(Ressource));
  ressource->data = data;
  ressource->ptr = ptr;
  ressource->next = MEMORYMANAGER_PTR->layers->ressources;
  MEMORYMANAGER_PTR->layers->ressources = ressource;
  ++MEMORYMANAGER_PTR->size;
}

void			create_ressource_layer()
{
  RessourceLayer	*layer;

  layer = malloc(sizeof(RessourceLayer));
  layer->ressources = NULL;
  layer->next = MEMORYMANAGER_PTR->layers;
  MEMORYMANAGER_PTR->layers = layer;
}

void			*ressource_handle(void *data, void (*ptr)(void *))
{
  create_ressource(data, ptr);
  return (data);
}

void			*custom_alloc(size_t size, void (*ptr)(void *))
{
  void			*data;

  data = malloc(size);
  create_ressource(data, ptr);
  return (data);
}

void			*alloc(size_t size)
{
  return (custom_alloc(size, basic_ptr_cleaner));
}

void			clean_ressource_layer()
{
  RessourceLayer	*layer;
  Ressource		*r[2];

  layer = MEMORYMANAGER_PTR->layers;
  MEMORYMANAGER_PTR->layers = layer->next;
  r[0] = layer->ressources;
  while (r[0])
    {
      r[1] = r[0];
      r[0] = r[0]->next;
      clean_ressource(r[1]);
    }
  free(layer);
}

void			clean(void *ptr)
{
  Ressource		*r;
  Ressource		**prev;
  RessourceLayer	*layer;

  layer = MEMORYMANAGER_PTR->layers;
  while (layer)
    {
      r = layer->ressources;
      prev = &layer->ressources;
      while (r)
	{
	  if (r->data == ptr)
	    {
	      *prev = r->next;
	      clean_ressource(r);
	      --MEMORYMANAGER_PTR->size;
	      return ;
	    }
	  prev = &r->next;
	  r = r->next;
	}
      layer = layer->next;
    }
}

void			clean_collector(MemoryManager *collector)
{
  while (MEMORYMANAGER_PTR->layers)
    clean_ressource_layer();
}
