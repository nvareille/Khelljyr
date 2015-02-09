#ifndef TIMER_H_
# define TIMER_H_

# include <pebble.h>

# include "../MemoryManager/MemoryManager.h"

/**
 * A container for callbacks
 */
typedef struct	s_Timer
{
  AppTimer	*timer;
  bool		(*fct)(void *, struct s_Timer *);
  void		*data;
  uint32_t	ms;
}		Timer;

/**
 * Creates a timer. The timer will repeat infinitly unless you set active = false in the timer variable in the callback. You may also call clean() to break it
 * @param ms The interval in milliseconds.
 * @param fct The callback function to be called.
 * @param data A pointer to a user data received in the callback.
 * @return A timer structure containing the timer data.
 */
Timer		*create_timer(uint32_t ms, bool (*fct)(void *, Timer *), void *data);

/**
 * Reschedule a timer.
 * @param timer The timer to reschedule
 * @param ms The new interval to set. This will become the new interval each time it downs to 0.
 */
bool		timer_reschedule(Timer *timer, uint32_t ms);

#endif
