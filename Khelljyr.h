#ifndef KHELLJYR_H_
# define KHELLJYR_H_

# include <pebble.h>

# include "GarbageCollector/GarbageCollector.h"
# include "Graphic/Graphic.h"

typedef struct		s_khelljyr_app
{
  GarbageCollector	collector;
  Graphic		graphic;
}			Khelljyr;

#endif
