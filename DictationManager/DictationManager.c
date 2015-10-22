#include "DictationManager.h"

static void dictation_session_call(DictationSession *session, DictationSessionStatus status, char *str, void *ctx)
{
#ifndef PBL_PLATFORM_APLITE
  DictationManager *manager = scopper(NULL, SCOPPER_DICTATION_ID);

  strcpy(manager->buff, str);
  manager->callback(session, status, manager->buff, ctx);
#endif
}

void start_dictation()
{
#ifndef PBL_PLATFORM_APLITE
  DictationManager *manager = scopper(NULL, SCOPPER_DICTATION_ID);

  dictation_session_start(manager->dictation_session);
#endif
}

void stop_dictation()
{
#ifndef PBL_PLATFORM_APLITE
  DictationManager *manager = scopper(NULL, SCOPPER_DICTATION_ID);

  dictation_session_stop(manager->dictation_session);
#endif
}

void set_dictation_callback(DictationSessionStatusCallback callback)
{
#ifndef PBL_PLATFORM_APLITE
  DictationManager *manager = scopper(NULL, SCOPPER_DICTATION_ID);

  manager->callback = callback;
#endif
}

void destroy_dictation()
{
#ifndef PBL_PLATFORM_APLITE
  DictationManager *manager = scopper(NULL, SCOPPER_DICTATION_ID);
  
  if (manager->dictation_session != NULL)
    dictation_session_destroy(manager->dictation_session);
#endif
}

int create_dictation_session(uint32_t size, DictationSessionStatusCallback callback, void *ctx, bool confirm_message, bool confirm_error)
{
#ifndef PBL_PLATFORM_APLITE
  DictationManager *manager = scopper(NULL, SCOPPER_DICTATION_ID);

  if ((manager->dictation_session = dictation_session_create(size, dictation_session_call, ctx)) != NULL)
    {
  manager->callback = callback;
  manager->buff = safe_alloc(size, free);
  dictation_session_enable_confirmation(manager->dictation_session, confirm_message);
  dictation_session_enable_error_dialogs(manager->dictation_session, confirm_error);
  return (DICTATION_OK);
}
  else
    return (DICTATION_KO);
#else
  return (DICTATION_APLITE);
#endif
}
