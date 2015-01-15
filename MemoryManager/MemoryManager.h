#ifndef GARBAGECOLLECTOR_H_
# define GARBAGECOLLECTOR_H_

# include <pebble.h>

# include "../Scopper/Scopper.h"

/**
 * A container for given pointers to keep them for cleaning by the MemoryManager
 * @see alloc
 * @see custom_alloc
 * @see resource_handle
 */
typedef struct			s_Resource
{
  void				*data;
  void				(*ptr)(void *);
  struct s_Resource		*next;
}				Resource;

/**
 * A container for the layers of memory that can be freed by the MemoryManager
 */
typedef struct			s_ResourceLayer
{
  Resource			*resources;
  struct s_ResourceLayer	*next;
}				ResourceLayer;

/**
 * A container for the MemoryManager
 */
typedef struct			s_MemoryManager
{
  unsigned short		size;
  ResourceLayer			*layers;
  ResourceLayer			*safe_layer;
}				MemoryManager;

/**
 * (Private Function)
 * Creates a new layer in the MemoryManager. This function is called on window creation.
 */
void			create_resource_layer();

/**
 * (Private Function)
 * Creates a new layer in the MemoryManager. This functions sets the safe_stack. I.E. the lowest layer on the stack. This function MUST NOT be called by the user.
 */
void			set_safe_resource_layer();

/**
 * Allocates some memory in the MemoryManager. This function is a REPLACEMENT for malloc() function that must not be called anymore
 * @param size The size in bytes that must be allocated
 * @return An allocated pointer of the given size
 * @see clean
 */
void			*alloc(size_t size);

/**
 * Allocate memory on the safe stack. The memory will be freed on clean() or program ending. 
 */
void			*safe_alloc(size_t size);

/**
 * Same as alloc but takes a function pointer to a custom free function. This function should be called when user wants to uninitialize some data by a specific method
 * @param size The size in bytes that must be allocated
 * @param ptr A custom function to free the pointer
 * @return An allocated pointer of the given size
 * @see clean 
 */
void			*custom_alloc(size_t size, void (*ptr)(void *));

/**
 * Takes a pointer in parameter and pass it to the MemoryManager. This function doesn't allocate memory but frees it with the custom pointer when it must be done.
 * @param data A pointer of allocated memory
 * @param ptr A custom function to free the pointer
 * @return data variable
 * @see clean 
 */
void			*resource_handle(void *data, void (*ptr)(void *));

/**
 * Free any pointer allocated within Khelljyr's allocation functions. This function is a REPLACEMENT for free() function that must not be called anymore
 * @param ptr The pointer to be freed
 * @see alloc
 * @see custom_alloc
 * @see resource_handle
 */
void			clean(void *ptr);

/**
 * (Private Function)
 * Cleans the upper stack of the MemoryManager. This function is called on each window destruction and must not be called by users.
 * @param stack_value The value on stack that must be cleaned
 */
void			clean_collector(MemoryManager *stack_value);

/**
 * (Private Function)
 * Cleans the MemoryManager, this function is called by Khelljyr on exit. It must not be called by users.
 */
void			clean_resource_layer();

/**
 * (Private Function)
 * A Macro that returns a pointer to the MemoryManager structure for the framework
 */
# define MEMORYMANAGER_PTR ((MemoryManager *)scopper(NULL, 0))

#endif
