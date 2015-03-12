#include "MemoryManager.h"

static void		clean_resource(Resource *data)
{
  data->ptr(data->data);
  free(data);
}

static void		create_resource(void *data, void (*ptr)(void *))
{
  MemoryManager		*manager = MEMORYMANAGER_PTR;
  Resource		*resource;

  resource = malloc(sizeof(Resource));
  resource->data = data;
  resource->ptr = ptr;
  resource->next = manager->layers->resources;
  manager->layers->resources = resource;
}

void			create_resource_layer()
{
  MemoryManager		*manager = MEMORYMANAGER_PTR;
  ResourceLayer		*layer;

  layer = malloc(sizeof(ResourceLayer));
  layer->resources = NULL;
  layer->next = MEMORYMANAGER_PTR->layers;
  manager->layers = layer;
}

void			set_safe_resource_layer()
{
  MemoryManager		*manager = MEMORYMANAGER_PTR;

  manager->safe_layer = manager->layers;
}


void			*resource_handle(void *data, void (*ptr)(void *))
{
  create_resource(data, ptr);
  return (data);
}

void			*custom_alloc(size_t size, void (*ptr)(void *))
{
  void			*data;

  data = malloc(size);
  create_resource(data, ptr);
  return (data);
}

void			*alloc(size_t size)
{
  return (custom_alloc(size, free));
}

void			**array_alloc(size_t size, unsigned int nbr)
{
  void			*pos;
  void			**ptr;
  unsigned int		count = 0;

  pos = alloc(sizeof(void **) * nbr + size * nbr);
  ptr = pos;
  pos += (sizeof(void **) * nbr);
  while (count < nbr)
    {
      ptr[count] = pos;
      pos += size;
      ++count;
    }
  return (ptr);
}

void			*safe_alloc(size_t size, void (*ptr)(void *))
{
  MemoryManager		*manager = MEMORYMANAGER_PTR;
  Resource		*resource;

  resource = malloc(sizeof(Resource));
  resource->ptr = ptr;
  resource->data = malloc(size);
  resource->next = manager->safe_layer->resources;
  manager->safe_layer->resources = resource;
  return (resource->data);
}

void			clean_resource_layer()
{
  MemoryManager		*manager = MEMORYMANAGER_PTR;
  ResourceLayer		*layer;
  Resource		*r[2];

  layer = manager->layers;
  manager->layers = layer->next;
  r[0] = layer->resources;
  while (r[0])
    {
      r[1] = r[0];
      r[0] = r[0]->next;
      clean_resource(r[1]);
    }
  free(layer);
}

void			clean(void *ptr)
{
  MemoryManager		*manager = MEMORYMANAGER_PTR;
  Resource		*r;
  Resource		**prev;
  ResourceLayer		*layer;

  layer = manager->layers;
  while (layer)
    {
      r = layer->resources;
      prev = &layer->resources;
      while (r)
	{
	  if (r->data == ptr)
	    {
	      *prev = r->next;
	      clean_resource(r);
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
  MemoryManager		*manager = MEMORYMANAGER_PTR;

  while (manager->layers)
    clean_resource_layer();
}
