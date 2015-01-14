#include "Khelljyr.h"

static void	app_builder(Khelljyr *data, void *user)
{
  scopper(&data->collector, 0);
  scopper(&data->graphic, 1);
  scopper(&data->graphic.stack, 2);
  scopper(user, 3);
  create_resource_layer();
}

void		app_init(void *data, void (*fct)(void *))
{
  Khelljyr	*app;

  app = malloc(sizeof(Khelljyr));
  memset(app, 0, sizeof(Khelljyr));
  app_builder(app, data);
  if (fct)
    fct(data);
  app_event_loop();
  clean_collector(&app->collector);
  free(app);
}
