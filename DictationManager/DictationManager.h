#ifndef DICTATION_MANAGER_H_
# define DICTATION_MANAGER_H_

# include <pebble.h>
# include "../Scopper/Scopper.h"
# include "../MemoryManager/MemoryManager.h"

# define SCOPPER_DICTATION_ID	5
# define DICTATION_OK		0
# define DICTATION_KO		1
# define DICTATION_APLITE	2

# ifdef PBL_PLATFORM_APLITE
typedef void * DictationSession;
typedef void * DictationSessionStatus;
typedef void * DictationSessionStatusCallback;
typedef void * DictationManager;
# else
typedef struct		DictationManager
{
  DictationSession	*dictation_session;
  void			(*callback)(DictationSession *, DictationSessionStatus, char *, void *);
  char			*buff;
}			DictationManager;
#endif

/**
 * Starts a new session of dictation
 */
void start_dictation();

/**
 * Stops a session of dictation
 */
void stop_dictation();

/**
 * Destroys the dictation resource
 */
void destroy_dictation();

/**
 * Sets the dictation callback
 * @param The new Callback to set
 */
void set_dictation_callback(DictationSessionStatusCallback callback);

/**
 * Creates a dictation resource in order to use the dictation API
 * @param size The buffer size of the received text
 * @param callback The callback used on dictation treatment
 * @param ctx A pointer of some data to use in the callback
 * @param confirm_message A boolean that tells or not to activate user's message verification
 * @param confirm_error A boolean that tells or not to activate user's error verification
 */
int create_dictation_session(uint32_t size, DictationSessionStatusCallback callback, void *ctx, bool confirm_message, bool confirm_error);
#endif
