/* kern-sendstartscheduletablesynchron.c
 *
 * This file contains the OS_SendStartScheduleTableSynchron() function.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: kern-sendstartscheduletablesynchron.c 24025 2016-04-21 12:37:21Z mist9353 $
*/

#include <Os_kernel.h>
#include <Os_messagequeue.h>

#include <memmap/Os_mm_code_begin.h>

/*!
 * OS_SendStartScheduleTableSynchron
 *
 * Sends the StartScheduleTableSynchron() call to the core on which the schedule table 's' resides.
*/
os_errorresult_t OS_SendStartScheduleTableSynchron
(	os_scheduleid_t s,
	const os_schedule_t *ss
)
{
	os_paramtype_t msgParam[OS_MAXPARAM];

	msgParam[0] = (os_paramtype_t)s;

	return OS_SendMessageWait(OS_GetScheduleTableCoreId(ss), OS_XC_OP_StartScheduleTableSynchron, msgParam);
}

#include <memmap/Os_mm_code_end.h>

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
