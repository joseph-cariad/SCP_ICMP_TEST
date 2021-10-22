/* kern-errext-ActivateTask.c - kernel error database for STATUS=EXTENDED
 *
 * This is a generated file - DO NOT EDIT
 *
 * Generated by errdb-to-c.pl on 2020-03-03 16:30
 *
 * (c) 2020 Elektrobit Automotive GmbH
*/

#include <Os_kernel.h>
#include <Os_error.h>

#include <memmap/Os_mm_const_begin.h>
static const os_errorentry_t OS_errtblActivateTask[9] =
{
  {
    OS_E_ACCESS,
    OS_ERROR_ApplicationNotAccessible,
    OS_ACTION_RETURN|OS_ACTION_ERRORHOOK_APP|OS_ACTION_ERRORHOOK
  },
  {
    OS_E_CORE,
    OS_ERROR_CoreIsDown,
    OS_ACTION_RETURN|OS_ACTION_ERRORHOOK_APP|OS_ACTION_ERRORHOOK
  },
  {
    OS_E_CALLLEVEL,
    OS_ERROR_WrongContext,
    OS_ACTION_RETURN|OS_ACTION_ERRORHOOK_APP|OS_ACTION_ERRORHOOK
  },
  {
    OS_E_INTDISABLE,
    OS_ERROR_InterruptDisabled,
    OS_ACTION_RETURN|OS_ACTION_ERRORHOOK_APP|OS_ACTION_ERRORHOOK
  },
  {
    OS_E_ID,
    OS_ERROR_InvalidTaskId,
    OS_ACTION_RETURN|OS_ACTION_ERRORHOOK_APP|OS_ACTION_ERRORHOOK
  },
  {
    OS_E_DENIED,
    OS_ERROR_Quarantined,
    OS_ACTION_RETURN|OS_ACTION_ERRORHOOK_APP|OS_ACTION_ERRORHOOK
  },
  {
    OS_E_LIMIT,
    OS_ERROR_MaxActivations,
    OS_ACTION_RETURN|OS_ACTION_ERRORHOOK_APP|OS_ACTION_ERRORHOOK
  },
  {
    OS_E_RATEPROT,
    OS_ERROR_RateLimitExceeded,
    OS_ACTION_RETURN|OS_ACTION_PROTECTIONHOOK
  },
  {
    OS_E_ACCESS,
    OS_ERROR_Permission,
    OS_ACTION_RETURN|OS_ACTION_ERRORHOOK_APP|OS_ACTION_ERRORHOOK
  }
};

const os_serviceinfo_t OS_svc_ActivateTask =
{
    OS_errtblActivateTask,
    OS_SID_ActivateTask,
    9
};
#include <memmap/Os_mm_const_end.h>
