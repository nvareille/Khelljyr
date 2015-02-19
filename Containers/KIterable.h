#ifndef KITERABLE_H_
# define KITERABLE_H_

# include "Containers.h"

/**
 * A container used for casts purpose. The start signature of the stackElem and listElem are like this.
 */
typedef struct	s_KIterable
{
  void		*next;
  void		*data;
}		KIterable;

/**
 * A container used for casts purpose. The start signature of the stack and list are like this.
 */
typedef struct	s_KContainer
{
  void		*elem;
}		KContainer;

/**
 * A callback used for iterations with foreach
 * @param data The value that is being processed.
 * @param custom_ptr A custom pointer given by the foreach function
 * @return FOREACH_CONTINUE that tells foreach to continue or FOREACH_BREAK that stops the loop
 * @see foreach FOREACH_CONTINUE FOREACH_BREAK
 */
typedef		bool (*KIterableCallback)(void *data, void *custom_ptr);

/**
 * A function that iterate on every values of a Khelljyr container.
 * @param it A KIterable value. Use KITERABLE macro to convert a container to it
 * @param ptr A callback that receive the value that is being iterated and a given pointer
 * @param custom_ptr A pointer on custom data that will be given to ptr
 * @see KITERABLE
 * @see KIterableCallback
 */
void		foreach(KIterable *it, KIterableCallback ptr, void *custom_ptr);

/**
 * Transform a Khelljyr container into a KIterable * ready to be used by foreach
 * @see KList KStack
 */
# define KITERABLE(CONTAINER) ((KIterable *)((KContainer *)CONTAINER)->elem)

/**
 * A return value to use in the KIterableCallback that tells the foreach to continue
 */
# define FOREACH_CONTINUE	false

/**
 * A return value to use in the KIterableCallback that tells the foreach to stop
 */
# define FOREACH_BREAK		true

#endif
