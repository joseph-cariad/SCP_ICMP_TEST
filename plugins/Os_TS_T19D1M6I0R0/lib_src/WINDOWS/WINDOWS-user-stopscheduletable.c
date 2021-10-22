/* WINDOWS-user-stopscheduletable.c
 *
 * This file contains the system function OS_UserStopScheduleTable().
 * Generated by the makesc.pl script.
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
*/

/* MISRA-C:2004 Deviation List
 *
 * MISRA-1) Deviated Rule: 8.8 (required)
 * An external object or function shall be declared in one and only one file.
 *
 * Reason:
 * Declaration is necessary, because of header structure in OS.
 */
#include <Os_types.h>
#include <Os_syscalls.h>
#include <Os_tool.h>


#if (OS_TOOL == OS_gnu)
#if OS_GccVersionIsAtLeast(4,6,4)
#pragma GCC diagnostic push
/* All system calls end in OS_WINLINSyscall(), which must provide a generic prototype.
 * This means, that type casts must be used for its arguments, what leads to compiler warnings.
 * These warnings shall be suppressed herewith.
 */
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
#endif
#endif


/* Deviation MISRA-1 */
extern os_winlinresult_t OS_WINLINSyscall(
    os_serviceid_t syscallId,
    os_paramtype_t p1,
    os_paramtype_t p2,
    os_paramtype_t p3,
    os_paramtype_t p4);


os_int_t OS_UserStopScheduleTable(os_int_t p1);


os_int_t OS_UserStopScheduleTable(os_int_t p1)
{
	return (os_int_t) OS_WINLINSyscall(OS_SC_StopScheduleTable, (os_paramtype_t)p1, (os_paramtype_t)-1, (os_paramtype_t)-1, (os_paramtype_t)-1);
}

#if (OS_TOOL == OS_gnu)
#if OS_GccVersionIsAtLeast(4,6,4)
#pragma GCC diagnostic pop
#endif
#endif
