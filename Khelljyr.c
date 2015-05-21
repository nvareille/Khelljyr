#include <pebble.h>

void		 app_init(void *data, void (*fct)(void *))
{
  app_event_loop();
}
