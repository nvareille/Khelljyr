#ifndef GARBAGECOLLECTOR_H_
# define GARBAGECOLLECTOR_H_

# include <pebble.h>

# include "../Scopper/Scopper.h"

typedef struct			s_Ressource
{
  void				*data;
  void				(*ptr)(void *);
  struct s_Ressource		*next;
}				Ressource;

typedef struct			s_RessourceLayer
{
  Ressource			*ressources;
  struct s_RessourceLayer	*next;
}				RessourceLayer;

typedef struct			s_MemoryManager
{
  unsigned short		size;
  RessourceLayer		*layers;
}				MemoryManager;

void			create_ressource_layer();

void			*alloc(size_t);
void			*custom_alloc(size_t, void (*)(void *));
void			*ressource_handle(void *, void (*)(void *));

void			clean(void *);
void			clean_collector(MemoryManager *);
void			clean_ressource_layer();

# define MEMORYMANAGER_PTR ((MemoryManager *)scopper(NULL, 0))

#endif
