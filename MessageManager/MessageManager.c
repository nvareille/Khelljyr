#include <stdarg.h>
#include "MessageManager.h"

void			message_add_int(int key, int value, DictionaryIterator *it)
{
  Tuplet		t = TupletInteger(key, value);
  
  dict_write_tuplet(it, &t);
}

void			message_add_string(int key, char *value, DictionaryIterator *it)
{
  Tuplet                t = TupletCString(key, value);

  dict_write_tuplet(it, &t);
}

static void		message_add_time(void (*ptr)(DictionaryIterator *, void *), void *data, void (*success)(void *), void (*fail)(void *), int time)
{
  MessageManager	*manager = MESSAGEMANAGER_PTR;
  Message		*message = safe_alloc(sizeof(Message), free);

  message->ptr = ptr;
  message->data = data;
  message->success = success;
  message->fail = fail;
  message->last = time;
  message->next = NULL;
  if (manager->last)
    {
      manager->last->next = message;
      manager->last = message;
    }
  else
    {
      manager->queue = message;
      manager->last = message;
    }
}

void			message_format(int key, const char *format, DictionaryIterator *it, ...)
{
  va_list		list;
  int			count = 0;

  message_add_int(0, key, it);
  va_start(list, it);
  while (*format)
    {
      if (*format == 's')
	message_add_string(++count, va_arg(list, char *), it);
      if (*format == 'd')
	message_add_int(++count, va_arg(list, int), it);
      ++format;
    }
}

static bool		push_message(void *m, Timer *t)
{
  MessageManager	*manager = m;
  DictionaryIterator    *it;

  if (manager->processing)
    {
      if (manager->processing && manager->processing->last > 0)
	{
	  --manager->processing->last;
	  app_message_outbox_begin(&it);
	  manager->processing->ptr(it, manager->processing->data);
	  dict_write_end(it);
	  if (app_message_outbox_send() == APP_MSG_BUSY)
	    create_timer(100, push_message, manager);
	}
      else
	{
	  if (manager->processing->fail)
	    manager->processing->fail(manager->processing->data);
	  clean(manager->processing);
	  manager->processing = NULL;
	}
    }
  return (false);
}

void			message_process()
{
  MessageManager	*manager = MESSAGEMANAGER_PTR;

  if (manager->queue)
    {
      manager->processing = manager->queue;
      manager->queue = manager->processing->next;
      if (manager->queue == NULL)
	manager->last = NULL;
      push_message(manager, NULL);
    }
}

void			message_add(void (*ptr)(DictionaryIterator *, void *), void *data, void (*success)(void *), void (*fail)(void *))
{
  message_add_time(ptr, data, success, fail, 10);
}

static void		success_send(DictionaryIterator *iterator, void *context)
{
  MessageManager	*manager = MESSAGEMANAGER_PTR;

  if (manager && manager->processing && manager->processing->success)
    manager->processing->success(manager->processing->data);
  clean(manager->processing);
  manager->processing = NULL;
  message_process();
}

static void		fail_send(DictionaryIterator *iterator, AppMessageResult reason, void *context)
{
  push_message(MESSAGEMANAGER_PTR, NULL);
}

static void		message_receive(DictionaryIterator *it, void *ctx)
{
  Tuple			*tuple = dict_read_first(it);
  MessageManager	*manager = MESSAGEMANAGER_PTR;

  if (tuple && tuple->value->int32 >= 0)
    manager->ptr[tuple->value->int32](it, ctx);
}

void			message_init(int in, int out, void *ctx, void (**ptr)(DictionaryIterator *, void *))
{
  MESSAGEMANAGER_PTR->ptr = ptr;
  app_message_register_outbox_sent(success_send);
  app_message_register_outbox_failed(fail_send);
  app_message_register_inbox_received(message_receive);
  app_message_set_context(ctx);
  app_message_open(in, out);  
}
