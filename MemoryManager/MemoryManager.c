#include "MemoryManager.h"

static void		basic_ptr_cleaner(void *data)
{
  free(data);
}

static void		clean_resource(Resource *data)
{
  data->ptr(data->data);
  free(data);
}

static void		create_resource(void *data, void (*ptr)(void *))
{
  Resource		*resource;

  resource = malloc(sizeof(Resource));
  resource->data = data;
  resource->ptr = ptr;
  resource->next = MEMORYMANAGER_PTR->layers->resources;
  MEMORYMANAGER_PTR->layers->resources = resource;
  ++MEMORYMANAGER_PTR->size;
}

void			create_resource_layer()
{
  ResourceLayer		*layer;

  layer = malloc(sizeof(ResourceLayer));
  layer->resources = NULL;
  layer->next = MEMORYMANAGER_PTR->layers;
  MEMORYMANAGER_PTR->layers = layer;
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
  return (custom_alloc(size, basic_ptr_cleaner));
}

void			clean_resource_layer()
{
  ResourceLayer	*layer;
  Resource		*r[2];

  layer = MEMORYMANAGER_PTR->layers;
  MEMORYMANAGER_PTR->layers = layer->next;
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
  Resource		*r;
  Resource		**prev;
  ResourceLayer		*layer;

  layer = MEMORYMANAGER_PTR->layers;
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
    clean_resource_layer();
}
