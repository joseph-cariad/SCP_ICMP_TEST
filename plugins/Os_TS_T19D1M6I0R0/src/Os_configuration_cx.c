/* Os_configuration_cx.c
 *
 * This file contains the architecture-independent kernel configuration data for core CX.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_configuration_cx.c 26302 2017-03-24 08:58:10Z ingi2575 $
*/

/* CHECK: NOPARSE */
#include <Os_tool.h>
#include <Os_configuration.h>
#include <Os_kernel.h>
#include <Os_configuration_decls.h>

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)
#include <Os_syscalls.h>
#include <board.h>
#include <Os_cpuload_kernel.h>
#include <Os_cpuload.h>
#include <Os_api.h>
#include <Os_taskqueue.h>
#include <Os_messagequeue.h>
#endif /* OS_KERNEL_TYPE != OS_MICROKERNEL */

#if (OS_KERNEL_TYPE == OS_MICROKERNEL)
#include <Mk_qmboard.h>
#endif /* OS_KERNEL_TYPE == OS_MICROKERNEL */



#if ((OS_PROPERTIES_COREX & OS_COREPROP_USED_BIT) != OS_COREPROP_USED_BIT)
#include <memmap/Os_mm_var_begin.h>
os_uint8_t OS_unused_configuration_cx;
#include <memmap/Os_mm_var_end.h>
#else

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)
/*!
 * OS_appDynamic_coreX
 *
 * Application state of applications on core CX.
*/
#include <memmap/Os_mm_var_begin.h>
#if (OS_NAPPS_COREX != 0)
OS_SECTION_PRAGMA(OS_appDynamic_coreX, .bss.coreX.appDynamic)
os_appdynamic_t
		OS_SECTION_ATTRIB_PRE(.bss.coreX.appDynamic)
		OS_appDynamic_coreX[OS_NAPPS_COREX]
		OS_SECTION_ATTRIB_POST(.bss.coreX.appDynamic);
#endif
#include <memmap/Os_mm_var_end.h>

/*!
 * OS_taskAccounting_coreX
 *
 * The accounting information for tasks, one entry per task that needs it.
 * They are only accessible via the pointer os_task_t::accounting.
*/
#if (OS_NTASKACCOUNTING != 0)
#include <memmap/Os_mm_var_begin.h>
#if (OS_NTASKACCOUNTING_COREX != 0)
OS_SECTION_PRAGMA(OS_taskAccounting_coreX, .bss.coreX.taskAccounting)
os_taskaccounting_t
		OS_SECTION_ATTRIB_PRE(.bss.coreX.taskAccounting)
		OS_taskAccounting_coreX[OS_NTASKACCOUNTING_COREX]
		OS_SECTION_ATTRIB_POST(.bss.coreX.taskAccounting);
#endif
#include <memmap/Os_mm_var_end.h>
#endif

/*!
 * OS_taskDynamic_coreX
 *
 * The dynamic status of tasks, one entry per task. Note: this is not the
 * context of the task, though it may contain it.
*/
#include <memmap/Os_mm_var_begin.h>
#if (OS_NTASKS_COREX != 0)
OS_SECTION_PRAGMA(OS_taskDynamic_coreX, .bss.coreX.taskDynamic)
os_taskdynamic_t
		OS_SECTION_ATTRIB_PRE(.bss.coreX.taskDynamic)
		OS_taskDynamic_coreX[OS_NTASKS_COREX]
		OS_SECTION_ATTRIB_POST(.bss.coreX.taskDynamic);
#endif
#include <memmap/Os_mm_var_end.h>


/*!
 * CLZ scheduling algorithm.
 */
#if (OS_SCHEDULING_ALGORITHM == OS_CLZ_QUEUE)

#include <memmap/Os_mm_var_begin.h>
#if (OS_NSLAVEWORDS_COREX != 0)
OS_SECTION_PRAGMA(OS_SLAVEPRIOWORD_OBJ_COREX, .bss.coreX.slavePrioWord)
os_clzword_t
		OS_SECTION_ATTRIB_PRE(.bss.coreX.slavePrioWord)
		OS_SLAVEPRIOWORD_OBJ_COREX[OS_NSLAVEWORDS_COREX]
		OS_SECTION_ATTRIB_POST(.bss.coreX.slavePrioWord);
#else
#if (OS_N_CORES == 1)
OS_SECTION_PRAGMA(OS_SLAVEPRIOWORD_OBJ_COREX, .bss.coreX.slavePrioWord)
os_clzword_t
		OS_SECTION_ATTRIB_PRE(.bss.coreX.slavePrioWord)
		OS_SLAVEPRIOWORD_OBJ_COREX[1]
		OS_SECTION_ATTRIB_POST(.bss.coreX.slavePrioWord);
#endif
#endif
#include <memmap/Os_mm_var_end.h>

#include <memmap/Os_mm_var_begin.h>
#if (OS_NPRIORITYQUEUEDYNAMICS_COREX != 0)
OS_SECTION_PRAGMA(OS_priorityQueueDynamic_coreX, .bss.coreX.priorityQueueDynamic)
static os_priorityqueuedynamic_t
		OS_SECTION_ATTRIB_PRE(.bss.coreX.priorityQueueDynamic)
		OS_priorityQueueDynamic_coreX[OS_NPRIORITYQUEUEDYNAMICS_COREX]
		OS_SECTION_ATTRIB_POST(.bss.coreX.priorityQueueDynamic);
#endif
#include <memmap/Os_mm_var_end.h>

#include <memmap/Os_mm_var_begin.h>
#if (OS_NPRIORITYSLOTS_COREX != 0)
OS_SECTION_PRAGMA(OS_PRIORITYSLOT_OBJ_COREX, .bss.coreX.prioritySlot)
os_priorityqueueentry_t
		OS_SECTION_ATTRIB_PRE(.bss.coreX.prioritySlot)
		OS_PRIORITYSLOT_OBJ_COREX[OS_NPRIORITYSLOTS_COREX]
		OS_SECTION_ATTRIB_POST(.bss.coreX.prioritySlot);
#else
#if (OS_N_CORES == 1)
OS_SECTION_PRAGMA(OS_PRIORITYSLOT_OBJ_COREX, .bss.coreX.prioritySlot)
os_priorityqueueentry_t
		OS_SECTION_ATTRIB_PRE(.bss.coreX.prioritySlot)
		OS_PRIORITYSLOT_OBJ_COREX[1]
		OS_SECTION_ATTRIB_POST(.bss.coreX.prioritySlot);
#endif
#endif
#include <memmap/Os_mm_var_end.h>

#include <memmap/Os_mm_const_begin.h>
#if (OS_NPRIORITIES_COREX != 0)
os_priorityqueue_t const OS_PRIORITYQUEUE_OBJ_COREX[OS_NPRIORITIES_COREX] = { OS_PRIORITYQUEUE_INIT_COREX };
#else
#if (OS_N_CORES == 1)
os_priorityqueue_t const OS_PRIORITYQUEUE_OBJ_COREX[1] = { {OS_NULL, OS_NULL, OS_NULL, 0, 0, 0} };
#endif
#endif
#include <memmap/Os_mm_const_end.h>

#endif /* OS_SCHEDULING_ALGORITHM == OS_CLZ_QUEUE */

/*!
 * Linked list scheduling algorithm.
 *
 * OS_taskActivations
 *
 * The links in the linked list of the task queue. Each slot contains the
 * index of the next slot in the queue. The corresponding (same index)
 * entry in OS_taskPtrs[] contains the address of the task that owns
 * the slot. There is always at least 1 entry in this array.
 * The first entry (index 0) is used to store the index of the current
 * activation of the currently running task or 0, if there is none.
 */
#if (OS_SCHEDULING_ALGORITHM == OS_LINKED_LIST)

#include <memmap/Os_mm_const_begin.h>
#if ((OS_NTASKACTIVATIONS_COREX != 0) || (OS_N_CORES == 1))
const os_task_t * const OS_TASKPTRS_OBJ_COREX[OS_NTASKACTIVATIONS_COREX + 1] = { OS_TASKACT_COREX };
#endif
#include <memmap/Os_mm_const_end.h>

#include <memmap/Os_mm_var_begin.h>
#if ((OS_NTASKACTIVATIONS_COREX != 0) || (OS_N_CORES == 1))
OS_SECTION_PRAGMA(OS_TASKACTIVATIONS_OBJ_COREX, .bss.coreX.taskActivations)
os_tasklink_t
		OS_SECTION_ATTRIB_PRE(.bss.coreX.taskActivations)
		OS_TASKACTIVATIONS_OBJ_COREX[OS_NTASKACTIVATIONS_COREX + 1]
		OS_SECTION_ATTRIB_POST(.bss.coreX.taskActivations);
#endif
#include <memmap/Os_mm_var_end.h>

#endif /* OS_SCHEDULING_ALGORITHM == OS_LINKED_LIST */

/*!
 * Resources
*/
#include <memmap/Os_mm_var_begin.h>
#if (OS_NRESOURCES_COREX != 0)
OS_SECTION_PRAGMA(OS_resourceDynamic_coreX, .bss.coreX.resourceDynamic)
os_resourcedynamic_t
		OS_SECTION_ATTRIB_PRE(.bss.coreX.resourceDynamic)
		OS_resourceDynamic_coreX[OS_NRESOURCES_COREX]
		OS_SECTION_ATTRIB_POST(.bss.coreX.resourceDynamic);
#endif
#include <memmap/Os_mm_var_end.h>

/*!
 * OS_isrAccounting_coreX
 *
 * The accounting information for ISRs, one entry per ISR that needs it.
 * It's accessible via the pointer os_isr_t::accounting.
*/
#if (OS_NISRACCOUNTING != 0)
#include <memmap/Os_mm_var_begin.h>
#if (OS_NISRACCOUNTING_COREX != 0)
OS_SECTION_PRAGMA(OS_isrAccounting_coreX, .bss.coreX.isrAccounting)
os_israccounting_t
		OS_SECTION_ATTRIB_PRE(.bss.coreX.isrAccounting)
		OS_isrAccounting_coreX[OS_NISRACCOUNTING_COREX]
		OS_SECTION_ATTRIB_POST(.bss.coreX.isrAccounting);
#endif
#include <memmap/Os_mm_var_end.h>
#endif /* OS_NISRACCOUNTING!=0 */

/*!
 * Interrupts
 */
#include <memmap/Os_mm_var_begin.h>
#if (OS_NINTERRUPTS_COREX != 0)
OS_SECTION_PRAGMA(OS_isrDynamic_coreX, .bss.coreX.isrDynamic)
os_isrdynamic_t
		OS_SECTION_ATTRIB_PRE(.bss.coreX.isrDynamic)
		OS_isrDynamic_coreX[OS_NINTERRUPTS_COREX]
		OS_SECTION_ATTRIB_POST(.bss.coreX.isrDynamic);
#endif
#include <memmap/Os_mm_var_end.h>

/*!
 * OS_rateIndex_coreX
 * OS_rateTimer_coreX
 *
 * The dynamic state of all rate-monitors. The index array (one per
 * rate-monitor) is the index into the rate-monitor's own ring buffer.
 * The timer array is the aggregated ring buffer array, COUNTLIMIT
 * entries per rate-monitor.
*/
#if (OS_NRATEMONS != 0)
#include <memmap/Os_mm_var_begin.h>
#if (OS_NRATEMONS_COREX != 0)
OS_SECTION_PRAGMA(OS_rateIndex_coreX, .bss.coreX.rateIndex)
os_rateindex_t
		OS_SECTION_ATTRIB_PRE(.bss.coreX.rateIndex)
		OS_rateIndex_coreX[OS_NRATEMONS_COREX]
		OS_SECTION_ATTRIB_POST(.bss.coreX.rateIndex);
#endif
#if (OS_NRATETIMERS_COREX != 0)
OS_SECTION_PRAGMA(OS_rateTimer_coreX, .bss.coreX.rateTimer)
os_timestamp_t
		OS_SECTION_ATTRIB_PRE(.bss.coreX.rateTimer)
		OS_rateTimer_coreX[OS_NRATETIMERS_COREX]
		OS_SECTION_ATTRIB_POST(.bss.coreX.rateTimer);
#endif
#include <memmap/Os_mm_var_end.h>
#endif /* OS_NRATEMONS != 0 */

/*!
 * Configuration for CPU load measurement
 *
 * We define a default if the generator has not already defined one.
 * The default defines a dummy configuration that is internally consistent, in case any function
 * gets called (avoiding possible divide-by-zero problems, null-pointer accesses etc.)
 * Naturally, calling the APIs with the feature unconfigured will result in garbage answers.
 * The system-call version of the API is turned off.
*/

#ifndef OS_EXCLUDE_CPULOAD

/*!
 * OS_coreCpuLoad_coreX
 *
 * CPU load measurement data structures. Access to CPU load measurement
 * data is possible via OS_GetKernelData()->cpuLoad.
 */
#include <memmap/Os_mm_var_begin.h>
static
OS_SECTION_PRAGMA(OS_cpuLoad_coreX, .bss.coreX.cpuLoad)
os_cpuload_t
		OS_SECTION_ATTRIB_PRE(.bss.coreX.cpuLoad)
		OS_cpuLoad_coreX
		OS_SECTION_ATTRIB_POST(.bss.coreX.cpuLoad);
#include <memmap/Os_mm_var_end.h>

/*!
 * OS_cpuLoadBusyBuffer_coreX
 *
 * Each of these arrays creates ring buffer used for storing the interval busy-times.
 * Each is pointed to by OS_GetKernelData()->cpuLoad->busyBuffer respectively, because
 * the function OS_InitMeasureCpuLoad() put that pointer there.
 */
#include <memmap/Os_mm_var_begin.h>
OS_SECTION_PRAGMA(OS_cpuLoadBusyBuffer_coreX, .bss.coreX.cpuLoadBusyBuffer)
os_tick_t
		OS_SECTION_ATTRIB_PRE(.bss.coreX.cpuLoadBusyBuffer)
		OS_cpuLoadBusyBuffer_coreX[OS_CPULOADCFG_NINTERVALS]
		OS_SECTION_ATTRIB_POST(.bss.coreX.cpuLoadBusyBuffer);
#include <memmap/Os_mm_var_end.h>

#endif /* OS_EXCLUDE_CPULOAD */

/*!
 * OS_crosscoreMessageQueue_ptr
 *
 * Inter-core message queues.
 */
#if (OS_N_CORES > 1)
#include <memmap/Os_mm_var_begin.h>
OS_SECTION_PRAGMA(OS_messageQueue_coreX, .bss.shared.coreX.messageQueue)
os_messagequeue_t
		OS_SECTION_ATTRIB_PRE(.bss.shared.coreX.messageQueue)
		OS_messageQueue_coreX
		OS_SECTION_ATTRIB_POST(.bss.shared.coreX.messageQueue);
#include <memmap/Os_mm_var_end.h>
#endif /* OS_N_CORES > 1 */

/*!
 * OS kernel data.
 *
 * OS kernel data local to each core. Hence, each core has its own instance,
 * which needs not to be synchronized with the ones of the other cores (if any).
 */
#include <memmap/Os_mm_var_begin.h>
OS_SECTION_PRAGMA(OS_KERNELDATA_OBJ_COREX, .data.coreX.kernelData)
os_kerneldata_t
		OS_SECTION_ATTRIB_PRE(.data.coreX.kernelData)
		OS_KERNELDATA_OBJ_COREX
		OS_SECTION_ATTRIB_POST(.data.coreX.kernelData) = { OS_KERNELDATA_INIT_COREX };
#include <memmap/Os_mm_var_end.h>

#endif /* OS_KERNEL_TYPE != OS_MICROKERNEL */

/*!
 * Counters
*/
#include <memmap/Os_mm_var_begin.h>
#if (OS_NCOUNTERS_COREX != 0)
OS_SECTION_PRAGMA(OS_counterDynamic_coreX, .bss.coreX.counterDynamic)
os_counterdynamic_t
		OS_SECTION_ATTRIB_PRE(.bss.coreX.counterDynamic)
		OS_counterDynamic_coreX[OS_NCOUNTERS_COREX]
		OS_SECTION_ATTRIB_POST(.bss.coreX.counterDynamic);
#endif
#include <memmap/Os_mm_var_end.h>

/*!
 * Alarms
*/
#include <memmap/Os_mm_var_begin.h>
#if (OS_TOTALALARMS_COREX != 0)
OS_SECTION_PRAGMA(OS_alarmDynamic_coreX, .bss.coreX.alarmDynamic)
os_alarmdynamic_t
		OS_SECTION_ATTRIB_PRE(.bss.coreX.alarmDynamic)
		OS_alarmDynamic_coreX[OS_TOTALALARMS_COREX]
		OS_SECTION_ATTRIB_POST(.bss.coreX.alarmDynamic);
#endif
#include <memmap/Os_mm_var_end.h>

/*!
 * ScheduleTables
*/
#include <memmap/Os_mm_var_begin.h>
#if (OS_NSCHEDULES_COREX != 0)
OS_SECTION_PRAGMA(OS_scheduleDynamic_coreX, .bss.coreX.scheduleDynamic)
os_scheduledynamic_t
		OS_SECTION_ATTRIB_PRE(.bss.coreX.scheduleDynamic)
		OS_scheduleDynamic_coreX[OS_NSCHEDULES_COREX]
		OS_SECTION_ATTRIB_POST(.bss.coreX.scheduleDynamic);
#endif
#include <memmap/Os_mm_var_end.h>

/*!
 * HardwareTimers
 *
 * OS_hwtLastValue: An array of values associated timers had the last time they were updated.
*/
#if (OS_NHWTIMERS_COREX != 0)
#include <memmap/Os_mm_var_begin.h>
OS_SECTION_PRAGMA(OS_hwtLastValue_coreX, .bss.coreX.hwtLastValue)
os_timervalue_t
		OS_SECTION_ATTRIB_PRE(.bss.coreX.hwtLastValue)
		OS_hwtLastValue_coreX[OS_NHWTIMERS_COREX]
		OS_SECTION_ATTRIB_POST(.bss.coreX.hwtLastValue);
#include <memmap/Os_mm_var_end.h>
#endif


/*!
 * QM-OS specific core-local variables.
*/
#if (OS_KERNEL_TYPE == OS_MICROKERNEL)

#include <memmap/Os_mm_var_begin.h>
OS_SECTION_PRAGMA(OS_panicCode_coreX, .bss.coreX.panicCode)
volatile os_panic_t
		OS_SECTION_ATTRIB_PRE(.bss.coreX.panicCode)
		OS_panicCode_coreX
		OS_SECTION_ATTRIB_POST(.bss.coreX.panicCode);
#include <memmap/Os_mm_var_end.h>


#endif /* OS_KERNEL_TYPE == OS_MICROKERNEL */


#endif /* USED */
/* CHECK: PARSE */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
