#ifndef GARBAGECOLLECTOR_H_
# define GARBAGECOLLECTOR_H_

# include <pebble.h>

# include "../Scopper/Scopper.h"

typedef struct		s_Ressource
{
  void			*data;
  void			(*ptr)(void *);
  struct s_Ressource	*next;
}			Ressource;

typedef struct		s_GarbageCollector
{
  unsigned short	size;
  Ressource		*ressources;
}			GarbageCollector;

void			app_init(void *, void (*)(void *));
void			*alloc(size_t);
void			*custom_alloc(size_t, void (*)(void *));
void			clean(void *);
void			clean_collector(GarbageCollector *);

# define GARBAGECOLLECTOR_PTR ((GarbageCollector *)scopper(NULL, 0))

#endif
