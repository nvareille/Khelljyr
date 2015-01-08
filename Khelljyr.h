#ifndef KHELLJYR_H_
# define KHELLJYR_H_

# include <pebble.h>

# include "MemoryManager/MemoryManager.h"
# include "Graphic/Graphic.h"
# include "Img/Img.h"
# include "Utils/Utils.h"
# include "Debug/Debug.h"

# define USER_PTR ((void *)scopper(NULL, 3))

typedef struct		s_khelljyr_app
{
  MemoryManager		collector;
  Graphic		graphic;
}			Khelljyr;

void		app_init(void *data, void (*fct)(void *));

#endif
