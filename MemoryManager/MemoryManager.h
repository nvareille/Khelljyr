#ifndef GARBAGECOLLECTOR_H_
# define GARBAGECOLLECTOR_H_

# include <pebble.h>

# include "../Scopper/Scopper.h"

typedef struct			s_Resource
{
  void				*data;
  void				(*ptr)(void *);
  struct s_Resource		*next;
}				Resource;

typedef struct			s_ResourceLayer
{
  Resource			*resources;
  struct s_ResourceLayer	*next;
}				ResourceLayer;

typedef struct			s_MemoryManager
{
  unsigned short		size;
  ResourceLayer			*layers;
}				MemoryManager;

void			create_resource_layer();

void			*alloc(size_t);
void			*custom_alloc(size_t, void (*)(void *));
void			*resource_handle(void *, void (*)(void *));

void			clean(void *);
void			clean_collector(MemoryManager *);
void			clean_resource_layer();

# define MEMORYMANAGER_PTR ((MemoryManager *)scopper(NULL, 0))

#endif
