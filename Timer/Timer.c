#include "Timer.h"

# include "../Debug/Debug.h"

bool		timer_reschedule(Timer *timer, uint32_t ms)
{
  timer->ms = ms;
  return (app_timer_reschedule(timer->timer, ms));
}

static void	destroy_timer(void *data)
{
  Timer		*timer = data;

  if (timer->active)
    app_timer_cancel(timer->timer);
  free(timer);
}

static void	call_callback(void *data)
{
  Timer		*timer = data;

  timer->fct(timer->data, timer);
  if (timer->active)
    timer->timer = app_timer_register(timer->ms, call_callback, timer);
  else
    clean(timer);
}

Timer		*create_timer(uint32_t ms, void (*fct)(void *, Timer *), void *data)
{
  Timer		*timer = safe_alloc(sizeof(Timer), destroy_timer);

  timer->ms = ms;
  timer->data = data;
  timer->fct = fct;
  timer->active = true;
  timer->timer = app_timer_register(ms, call_callback, timer);
  return (timer);
}
