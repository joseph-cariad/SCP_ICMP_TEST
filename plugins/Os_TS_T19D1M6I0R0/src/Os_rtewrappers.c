/* Os_rtewrappers.c
 *
 * This file contains the OS function wrappers used from the RTE.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_rtewrappers.c 23286 2015-12-22 12:05:22Z tojo2507 $
*/

#include <Os_configuration.h> /* for OS_INCLUDE_RTE */
#include <Os_api.h> /* for API functions */

#if (OS_INCLUDE_RTE == 1) /* only needed when RTE is used */

#include <Rte_Os.h> /* prototypes generated by RTE */

#include <memmap/Os_mm_code_begin.h>

/*
 * When using the OS SWC interface, the RTE can't directly use the OS API
 * calls as the OS macro definitions don't match the function prototypes
 * generated by the RTE.
 * So in case the OS is used by SWCs using its SWC interface, we provide
 * wrapper functions for the API exported to the RTE SWCs. This has the
 * additional benefit that compiler or MISRA-C checker might complain if
 * there's something wrong (implicit casts, mismatching prototypes).
 *
 * Note: The types and signatures are defined by the SWC description. Hence
 * the public signatures should use the types defined in the generated RTE
 * header. The actual calls must use OS types and call OS functionality.
*/

/*
 * GetCounterValue
*/
StatusType Os_RteGetCounterValue(CounterType c, TickRefType tr)
{
	return GetCounterValue((CounterType)c, tr);
}

/*
 * GetElapsedCounterValue/GetElapsedValue
*/
StatusType Os_RteGetElapsedCounterValue(CounterType c, TickRefType prev, TickRefType tr)
{
	return GetElapsedCounterValue((CounterType)c, prev, tr);
}

#include <memmap/Os_mm_code_end.h>

#endif /* OS_INCLUDE_RTE */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
