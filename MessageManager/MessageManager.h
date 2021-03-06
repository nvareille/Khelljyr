#ifndef MESSAGE_H_
# define MESSAGE_H_

# include <pebble.h>

# include "../Scopper/Scopper.h"
# include "../MemoryManager/MemoryManager.h"
# include "../Timer/Timer.h"

/**
 * A container for our messages. It contains the callbacks and all the data.
 */
typedef struct		s_Message
{
  void			(*ptr)(DictionaryIterator *, void *);
  void			*data;
  char			last;
  void			(*success)(void *);
  void			(*fail)(void *);
  struct s_Message	*next;
}			Message;

/**
 * A container for the MessageManager. It's basically a big list of messages.
 */
typedef struct		s_MessageManager
{
  Message		*queue;
  Message		*last;
  Message		*processing;
  void			(**ptr)(DictionaryIterator *, void *);
}			MessageManager;

/**
 * Initialize the messages in the Framework. Sets the inbounds and outbounds of the Message memory and the callbacks
 * @param in The size of the memory for receiving data
 * @param out The size of the memory for sending data
 * @param ctx A data that will be given in the callbacks for this message
 * @param callbacks An array of function pointers to the callbacks when the watch receives data
 */
void			message_init(int in, int out, void *ctx, void (*callbacks[])(DictionaryIterator *, void *));

/**
 * Add a message in the queue to be sent.
 * @param writing_callback A function that will be called on message creation. Use it to set the tuples.
 * @param data A pointer to user data that will be given for writing_callback variable
 * @param success_callback A callback that will be called on successful message sending
 * @param failure_callback A callback that will be called on failed message sending
 */
void			message_add(void (*writing_callback)(DictionaryIterator *, void *), void *data, void (*success_callback)(void *), void (*failure_callback)(void *));

/**
 * Process our messages queue. This is when the writing_callbacks of message_add will be called.
 * If a message sending fails, it will try again 10 times before dropping it.
 * @see message_add
 */
void			message_process();

/**
 * Writes a message, following the given pattern. For example if format is "ssi" the function will take 2 strings and 1 int as parameters and will write them.
 * @param key The action id to perform in the JavaScript
 * @param format The format to write, the parameters must follow the parttern
 * @param it The iterator on the message's Dictionary
 */
void			message_format(int key, const char *format, DictionaryIterator *it, ...);

/**
 * Writes an int in the message. this function is made for the writing_callbacks of message_add.
 * @param key The key in the array when received.
 * @param value The value to put in the array
 * @param it The DictionaryIterator to use
 */
void			message_add_int(int key, int value, DictionaryIterator *it);

/**
 * Writes a string in the message. this function is made for the writing_callbacks of message_add.
 * @param key The key in the array when received.
 * @param value The value to put in the array
 * @param it The DictionaryIterator to use
 */
void			message_add_string(int key, char *value, DictionaryIterator *it);

/**
 * (Private Function)
 * A macro that returns a pointer to the MessageManager
 * @return a pointer to the MessageManager
 */
# define MESSAGEMANAGER_PTR ((MessageManager *)scopper(NULL, 4))

/**
 * The action id to retrieve a save with Khelljyr's javascript framework
 */
# define GET_SAVE	0

/**
 * The action id to set a save with Khelljyr's javascript framework
 */
# define SET_SAVE	1

/**
 * The action id to retrieve a content from a URL with Khelljyr's javascript framework. The content must be json formated
 */
# define GET_URL	2

/**
 * The action id to delete a save with Khelljyr's javascript framework
 */
# define DELETE_SAVE	3

#endif
