#ifndef KHELLJYR_H_
# define KHELLJYR_H_

# include <pebble.h>

# include "MemoryManager/MemoryManager.h"
# include "Graphic/Graphic.h"
# include "Img/Img.h"
# include "Utils/Utils.h"
# include "Debug/Debug.h"
# include "MessageManager/MessageManager.h"

/**
 * A macro returning the user data given in app_init.
 * @return User data
 * @see app_init
 */
# define USER_PTR ((void *)scopper(NULL, 3))

/**
 * A data structure to the Framework. It contains the MemoryManager and Graphic structures.
 * This part must be private to the user, all operations must be out.
 * @see MemoryManager
 * @see Graphic
 */
typedef struct		s_khelljyr_app
{
  MemoryManager		manager;
  Graphic		graphic;
  MessageManager	message;
}			Khelljyr;

/**
 * The entry point of the framework. This is the function an user must call.
 * @param data a pointer to a user data.
 * @param fct a function pointer to be called by the Framework to start. The received parameter will be the user data
 * @see USER_PTR
 */
void		app_init(void *data, void (*fct)(void *));

#endif
