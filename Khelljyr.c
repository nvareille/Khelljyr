#include "Khelljyr.h"

static void	app_builder(Khelljyr *data)
{
  scopper(&data->collector, 0);
}

void		app_init(void *data, void (*fct)(void *))
{
  Khelljyr	*app;

  app = malloc(sizeof(Khelljyr));
  memset(app, 0, sizeof(Khelljyr));
  app_builder(app);
  if (fct)
    fct(data);
  app_event_loop();
  clean_collector(&app->collector);
  free(app);
}