#ifndef KLIST_H_
# define KLIST_H_

# include "../../MemoryManager/MemoryManager.h"

/**
 * A container for the KList elements
 */
typedef struct		s_KListElem
{
  struct s_KListElem	*next;
  void			*data;
}			KListElem;

/**
 * A container for the Lists
 */
typedef struct		s_KList
{
  KListElem		*elem;
  KListElem		*last;
  unsigned short	size;	
}			KList;

/**
 * Creates a KList ready to be used
 * @return An empty list ready to be used
 */
KList			*create_klist();

/**
 * Append a value at the front of the list
 * @param list The list that must be modified
 * @param elem The value to add
 */
void			klist_push_front(KList *list, void *elem);

/**
 * Append a value at the back of the list
 * @param list The list that must be modified
 * @param elem The value to add
 */
void			klist_push_back(KList *list, void *elem);

/**
 * Removes a value in front of the list
 * @param list The list that must be modified
 * @return The data that was removed
 */
void			*klist_pop_front(KList *list);

/**
 * Removes a value in back of the list
 * @param list The list that must be modified
 * @return The data that was removed
 */
void			*klist_pop_back(KList *list);

/**
 * Empties the list.
 * @param list The list to empty
 */
void			clean_klist(KList *list);

/**
 * A convenience macro for appending a list. It casts the value automaticaly
 * @see klist_push_front
 */
# define KLIST_PUSH_FRONT(LIST, ELEM) (klist_push_front(LIST, (void *)ELEM))

/**
 * A convenience macro for appending a list. It casts the value automaticaly
 * @see klist_push_back
 */
# define KLIST_PUSH_BACK(LIST, ELEM) (klist_push_back(LIST, (void *)ELEM))

#endif
