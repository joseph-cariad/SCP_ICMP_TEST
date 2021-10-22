/* kern-erruni-TerminateApplication.c - kernel error database for STATUS=UNIVERSAL
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
static const os_errorentry_t OS_errtblTerminateApplication[7] =
{
  {
    OS_E_STATE,
    OS_ERROR_ApplicationNotAccessible,
    OS_ACTION_RETURN|OS_ACTION_ERRORHOOK_APP|OS_ACTION_ERRORHOOK
  },
  {
    OS_E_CORE,
    OS_ERROR_CoreIsDown,
    OS_ACTION_RETURN|OS_ACTION_ERRORHOOK
  },
  {
    OS_E_ACCESS,
    OS_ERROR_Permission,
    OS_ACTION_QUARANTINE|OS_ACTION_ERRORHOOK
  },
  {
    OS_E_CALLLEVEL,
    OS_ERROR_WrongContext,
    OS_ACTION_QUARANTINE|OS_ACTION_ERRORHOOK
  },
  {
    OS_E_INTDISABLE,
    OS_ERROR_InterruptDisabled,
    OS_ACTION_QUARANTINE|OS_ACTION_ERRORHOOK
  },
  {
    OS_E_ID,
    OS_ERROR_InvalidApplicationId,
    OS_ACTION_QUARANTINE|OS_ACTION_ERRORHOOK
  },
  {
    OS_E_VALUE,
    OS_ERROR_InvalidRestartOption,
    OS_ACTION_QUARANTINE|OS_ACTION_ERRORHOOK
  }
};

const os_serviceinfo_t OS_svc_TerminateApplication =
{
    OS_errtblTerminateApplication,
    OS_SID_TerminateApplication,
    7
};
#include <memmap/Os_mm_const_end.h>
