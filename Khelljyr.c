#include "Khelljyr.h"

static void	app_builder(Khelljyr *data, void *user)
{
  scopper(&data->manager, 0);
  scopper(&data->graphic, 1);
  scopper(&data->graphic.stack, 2);
  scopper(user, 3);
  scopper(&data->message, 4);
  #ifndef PBL_PLATFORM_APLITE
  scopper(&data->dictation_manager, 5);
  #endif
  create_resource_layer();
  set_safe_resource_layer();
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
#ifndef PBL_PLATFORM_APLITE
  destroy_dictation();
#endif
  clean_collector(&app->manager);
  free(app);
}
