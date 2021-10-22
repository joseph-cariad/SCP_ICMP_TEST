/* Os_configuration_c0.c
 *
 * This file contains the architecture-independent kernel configuration data for core C0.
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_configuration_c0.c 26302 2017-03-24 08:58:10Z ingi2575 $
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



#if ((OS_PROPERTIES_CORE0 & OS_COREPROP_USED_BIT) != OS_COREPROP_USED_BIT)
#include <memmap/Os_mm_var_begin.h>
os_uint8_t OS_unused_configuration_c0;
#include <memmap/Os_mm_var_end.h>
#else

#if (OS_KERNEL_TYPE != OS_MICROKERNEL)
/*!
 * OS_appDynamic_core0
 *
 * Application state of applications on core C0.
*/
#include <memmap/Os_mm_var_begin.h>
#if (OS_NAPPS_CORE0 != 0)
OS_SECTION_PRAGMA(OS_appDynamic_core0, .bss.core0.appDynamic)
os_appdynamic_t
		OS_SECTION_ATTRIB_PRE(.bss.core0.appDynamic)
		OS_appDynamic_core0[OS_NAPPS_CORE0]
		OS_SECTION_ATTRIB_POST(.bss.core0.appDynamic);
#endif
#include <memmap/Os_mm_var_end.h>

/*!
 * OS_taskAccounting_core0
 *
 * The accounting information for tasks, one entry per task that needs it.
 * They are only accessible via the pointer os_task_t::accounting.
*/
#if (OS_NTASKACCOUNTING != 0)
#include <memmap/Os_mm_var_begin.h>
#if (OS_NTASKACCOUNTING_CORE0 != 0)
OS_SECTION_PRAGMA(OS_taskAccounting_core0, .bss.core0.taskAccounting)
os_taskaccounting_t
		OS_SECTION_ATTRIB_PRE(.bss.core0.taskAccounting)
		OS_taskAccounting_core0[OS_NTASKACCOUNTING_CORE0]
		OS_SECTION_ATTRIB_POST(.bss.core0.taskAccounting);
#endif
#include <memmap/Os_mm_var_end.h>
#endif

/*!
 * OS_taskDynamic_core0
 *
 * The dynamic status of tasks, one entry per task. Note: this is not the
 * context of the task, though it may contain it.
*/
#include <memmap/Os_mm_var_begin.h>
#if (OS_NTASKS_CORE0 != 0)
OS_SECTION_PRAGMA(OS_taskDynamic_core0, .bss.core0.taskDynamic)
os_taskdynamic_t
		OS_SECTION_ATTRIB_PRE(.bss.core0.taskDynamic)
		OS_taskDynamic_core0[OS_NTASKS_CORE0]
		OS_SECTION_ATTRIB_POST(.bss.core0.taskDynamic);
#endif
#include <memmap/Os_mm_var_end.h>


/*!
 * CLZ scheduling algorithm.
 */
#if (OS_SCHEDULING_ALGORITHM == OS_CLZ_QUEUE)

#include <memmap/Os_mm_var_begin.h>
#if (OS_NSLAVEWORDS_CORE0 != 0)
OS_SECTION_PRAGMA(OS_SLAVEPRIOWORD_OBJ_CORE0, .bss.core0.slavePrioWord)
os_clzword_t
		OS_SECTION_ATTRIB_PRE(.bss.core0.slavePrioWord)
		OS_SLAVEPRIOWORD_OBJ_CORE0[OS_NSLAVEWORDS_CORE0]
		OS_SECTION_ATTRIB_POST(.bss.core0.slavePrioWord);
#else
#if (OS_N_CORES == 1)
OS_SECTION_PRAGMA(OS_SLAVEPRIOWORD_OBJ_CORE0, .bss.core0.slavePrioWord)
os_clzword_t
		OS_SECTION_ATTRIB_PRE(.bss.core0.slavePrioWord)
		OS_SLAVEPRIOWORD_OBJ_CORE0[1]
		OS_SECTION_ATTRIB_POST(.bss.core0.slavePrioWord);
#endif
#endif
#include <memmap/Os_mm_var_end.h>

#include <memmap/Os_mm_var_begin.h>
#if (OS_NPRIORITYQUEUEDYNAMICS_CORE0 != 0)
OS_SECTION_PRAGMA(OS_priorityQueueDynamic_core0, .bss.core0.priorityQueueDynamic)
static os_priorityqueuedynamic_t
		OS_SECTION_ATTRIB_PRE(.bss.core0.priorityQueueDynamic)
		OS_priorityQueueDynamic_core0[OS_NPRIORITYQUEUEDYNAMICS_CORE0]
		OS_SECTION_ATTRIB_POST(.bss.core0.priorityQueueDynamic);
#endif
#include <memmap/Os_mm_var_end.h>

#include <memmap/Os_mm_var_begin.h>
#if (OS_NPRIORITYSLOTS_CORE0 != 0)
OS_SECTION_PRAGMA(OS_PRIORITYSLOT_OBJ_CORE0, .bss.core0.prioritySlot)
os_priorityqueueentry_t
		OS_SECTION_ATTRIB_PRE(.bss.core0.prioritySlot)
		OS_PRIORITYSLOT_OBJ_CORE0[OS_NPRIORITYSLOTS_CORE0]
		OS_SECTION_ATTRIB_POST(.bss.core0.prioritySlot);
#else
#if (OS_N_CORES == 1)
OS_SECTION_PRAGMA(OS_PRIORITYSLOT_OBJ_CORE0, .bss.core0.prioritySlot)
os_priorityqueueentry_t
		OS_SECTION_ATTRIB_PRE(.bss.core0.prioritySlot)
		OS_PRIORITYSLOT_OBJ_CORE0[1]
		OS_SECTION_ATTRIB_POST(.bss.core0.prioritySlot);
#endif
#endif
#include <memmap/Os_mm_var_end.h>

#include <memmap/Os_mm_const_begin.h>
#if (OS_NPRIORITIES_CORE0 != 0)
os_priorityqueue_t const OS_PRIORITYQUEUE_OBJ_CORE0[OS_NPRIORITIES_CORE0] = { OS_PRIORITYQUEUE_INIT_CORE0 };
#else
#if (OS_N_CORES == 1)
os_priorityqueue_t const OS_PRIORITYQUEUE_OBJ_CORE0[1] = { {OS_NULL, OS_NULL, OS_NULL, 0, 0, 0} };
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
#if ((OS_NTASKACTIVATIONS_CORE0 != 0) || (OS_N_CORES == 1))
const os_task_t * const OS_TASKPTRS_OBJ_CORE0[OS_NTASKACTIVATIONS_CORE0 + 1] = { OS_TASKACT_CORE0 };
#endif
#include <memmap/Os_mm_const_end.h>

#include <memmap/Os_mm_var_begin.h>
#if ((OS_NTASKACTIVATIONS_CORE0 != 0) || (OS_N_CORES == 1))
OS_SECTION_PRAGMA(OS_TASKACTIVATIONS_OBJ_CORE0, .bss.core0.taskActivations)
os_tasklink_t
		OS_SECTION_ATTRIB_PRE(.bss.core0.taskActivations)
		OS_TASKACTIVATIONS_OBJ_CORE0[OS_NTASKACTIVATIONS_CORE0 + 1]
		OS_SECTION_ATTRIB_POST(.bss.core0.taskActivations);
#endif
#include <memmap/Os_mm_var_end.h>

#endif /* OS_SCHEDULING_ALGORITHM == OS_LINKED_LIST */

/*!
 * Resources
*/
#include <memmap/Os_mm_var_begin.h>
#if (OS_NRESOURCES_CORE0 != 0)
OS_SECTION_PRAGMA(OS_resourceDynamic_core0, .bss.core0.resourceDynamic)
os_resourcedynamic_t
		OS_SECTION_ATTRIB_PRE(.bss.core0.resourceDynamic)
		OS_resourceDynamic_core0[OS_NRESOURCES_CORE0]
		OS_SECTION_ATTRIB_POST(.bss.core0.resourceDynamic);
#endif
#include <memmap/Os_mm_var_end.h>

/*!
 * OS_isrAccounting_core0
 *
 * The accounting information for ISRs, one entry per ISR that needs it.
 * It's accessible via the pointer os_isr_t::accounting.
*/
#if (OS_NISRACCOUNTING != 0)
#include <memmap/Os_mm_var_begin.h>
#if (OS_NISRACCOUNTING_CORE0 != 0)
OS_SECTION_PRAGMA(OS_isrAccounting_core0, .bss.core0.isrAccounting)
os_israccounting_t
		OS_SECTION_ATTRIB_PRE(.bss.core0.isrAccounting)
		OS_isrAccounting_core0[OS_NISRACCOUNTING_CORE0]
		OS_SECTION_ATTRIB_POST(.bss.core0.isrAccounting);
#endif
#include <memmap/Os_mm_var_end.h>
#endif /* OS_NISRACCOUNTING!=0 */

/*!
 * Interrupts
 */
#include <memmap/Os_mm_var_begin.h>
#if (OS_NINTERRUPTS_CORE0 != 0)
OS_SECTION_PRAGMA(OS_isrDynamic_core0, .bss.core0.isrDynamic)
os_isrdynamic_t
		OS_SECTION_ATTRIB_PRE(.bss.core0.isrDynamic)
		OS_isrDynamic_core0[OS_NINTERRUPTS_CORE0]
		OS_SECTION_ATTRIB_POST(.bss.core0.isrDynamic);
#endif
#include <memmap/Os_mm_var_end.h>

/*!
 * OS_rateIndex_core0
 * OS_rateTimer_core0
 *
 * The dynamic state of all rate-monitors. The index array (one per
 * rate-monitor) is the index into the rate-monitor's own ring buffer.
 * The timer array is the aggregated ring buffer array, COUNTLIMIT
 * entries per rate-monitor.
*/
#if (OS_NRATEMONS != 0)
#include <memmap/Os_mm_var_begin.h>
#if (OS_NRATEMONS_CORE0 != 0)
OS_SECTION_PRAGMA(OS_rateIndex_core0, .bss.core0.rateIndex)
os_rateindex_t
		OS_SECTION_ATTRIB_PRE(.bss.core0.rateIndex)
		OS_rateIndex_core0[OS_NRATEMONS_CORE0]
		OS_SECTION_ATTRIB_POST(.bss.core0.rateIndex);
#endif
#if (OS_NRATETIMERS_CORE0 != 0)
OS_SECTION_PRAGMA(OS_rateTimer_core0, .bss.core0.rateTimer)
os_timestamp_t
		OS_SECTION_ATTRIB_PRE(.bss.core0.rateTimer)
		OS_rateTimer_core0[OS_NRATETIMERS_CORE0]
		OS_SECTION_ATTRIB_POST(.bss.core0.rateTimer);
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
 * OS_coreCpuLoad_core0
 *
 * CPU load measurement data structures. Access to CPU load measurement
 * data is possible via OS_GetKernelData()->cpuLoad.
 */
#include <memmap/Os_mm_var_begin.h>
static
OS_SECTION_PRAGMA(OS_cpuLoad_core0, .bss.core0.cpuLoad)
os_cpuload_t
		OS_SECTION_ATTRIB_PRE(.bss.core0.cpuLoad)
		OS_cpuLoad_core0
		OS_SECTION_ATTRIB_POST(.bss.core0.cpuLoad);
#include <memmap/Os_mm_var_end.h>

/*!
 * OS_cpuLoadBusyBuffer_core0
 *
 * Each of these arrays creates ring buffer used for storing the interval busy-times.
 * Each is pointed to by OS_GetKernelData()->cpuLoad->busyBuffer respectively, because
 * the function OS_InitMeasureCpuLoad() put that pointer there.
 */
#include <memmap/Os_mm_var_begin.h>
OS_SECTION_PRAGMA(OS_cpuLoadBusyBuffer_core0, .bss.core0.cpuLoadBusyBuffer)
os_tick_t
		OS_SECTION_ATTRIB_PRE(.bss.core0.cpuLoadBusyBuffer)
		OS_cpuLoadBusyBuffer_core0[OS_CPULOADCFG_NINTERVALS]
		OS_SECTION_ATTRIB_POST(.bss.core0.cpuLoadBusyBuffer);
#include <memmap/Os_mm_var_end.h>

#endif /* OS_EXCLUDE_CPULOAD */

/*!
 * OS_crosscoreMessageQueue_ptr
 *
 * Inter-core message queues.
 */
#if (OS_N_CORES > 1)
#include <memmap/Os_mm_var_begin.h>
OS_SECTION_PRAGMA(OS_messageQueue_core0, .bss.shared.core0.messageQueue)
os_messagequeue_t
		OS_SECTION_ATTRIB_PRE(.bss.shared.core0.messageQueue)
		OS_messageQueue_core0
		OS_SECTION_ATTRIB_POST(.bss.shared.core0.messageQueue);
#include <memmap/Os_mm_var_end.h>
#endif /* OS_N_CORES > 1 */

/*!
 * OS kernel data.
 *
 * OS kernel data local to each core. Hence, each core has its own instance,
 * which needs not to be synchronized with the ones of the other cores (if any).
 */
#include <memmap/Os_mm_var_begin.h>
OS_SECTION_PRAGMA(OS_KERNELDATA_OBJ_CORE0, .data.core0.kernelData)
os_kerneldata_t
		OS_SECTION_ATTRIB_PRE(.data.core0.kernelData)
		OS_KERNELDATA_OBJ_CORE0
		OS_SECTION_ATTRIB_POST(.data.core0.kernelData) = { OS_KERNELDATA_INIT_CORE0 };
#include <memmap/Os_mm_var_end.h>

#endif /* OS_KERNEL_TYPE != OS_MICROKERNEL */

/*!
 * Counters
*/
#include <memmap/Os_mm_var_begin.h>
#if (OS_NCOUNTERS_CORE0 != 0)
OS_SECTION_PRAGMA(OS_counterDynamic_core0, .bss.core0.counterDynamic)
os_counterdynamic_t
		OS_SECTION_ATTRIB_PRE(.bss.core0.counterDynamic)
		OS_counterDynamic_core0[OS_NCOUNTERS_CORE0]
		OS_SECTION_ATTRIB_POST(.bss.core0.counterDynamic);
#endif
#include <memmap/Os_mm_var_end.h>

/*!
 * Alarms
*/
#include <memmap/Os_mm_var_begin.h>
#if (OS_TOTALALARMS_CORE0 != 0)
OS_SECTION_PRAGMA(OS_alarmDynamic_core0, .bss.core0.alarmDynamic)
os_alarmdynamic_t
		OS_SECTION_ATTRIB_PRE(.bss.core0.alarmDynamic)
		OS_alarmDynamic_core0[OS_TOTALALARMS_CORE0]
		OS_SECTION_ATTRIB_POST(.bss.core0.alarmDynamic);
#endif
#include <memmap/Os_mm_var_end.h>

/*!
 * ScheduleTables
*/
#include <memmap/Os_mm_var_begin.h>
#if (OS_NSCHEDULES_CORE0 != 0)
OS_SECTION_PRAGMA(OS_scheduleDynamic_core0, .bss.core0.scheduleDynamic)
os_scheduledynamic_t
		OS_SECTION_ATTRIB_PRE(.bss.core0.scheduleDynamic)
		OS_scheduleDynamic_core0[OS_NSCHEDULES_CORE0]
		OS_SECTION_ATTRIB_POST(.bss.core0.scheduleDynamic);
#endif
#include <memmap/Os_mm_var_end.h>

/*!
 * HardwareTimers
 *
 * OS_hwtLastValue: An array of values associated timers had the last time they were updated.
*/
#if (OS_NHWTIMERS_CORE0 != 0)
#include <memmap/Os_mm_var_begin.h>
OS_SECTION_PRAGMA(OS_hwtLastValue_core0, .bss.core0.hwtLastValue)
os_timervalue_t
		OS_SECTION_ATTRIB_PRE(.bss.core0.hwtLastValue)
		OS_hwtLastValue_core0[OS_NHWTIMERS_CORE0]
		OS_SECTION_ATTRIB_POST(.bss.core0.hwtLastValue);
#include <memmap/Os_mm_var_end.h>
#endif


/*!
 * QM-OS specific core-local variables.
*/
#if (OS_KERNEL_TYPE == OS_MICROKERNEL)

#include <memmap/Os_mm_var_begin.h>
OS_SECTION_PRAGMA(OS_panicCode_core0, .bss.core0.panicCode)
volatile os_panic_t
		OS_SECTION_ATTRIB_PRE(.bss.core0.panicCode)
		OS_panicCode_core0
		OS_SECTION_ATTRIB_POST(.bss.core0.panicCode);
#include <memmap/Os_mm_var_end.h>


#endif /* OS_KERNEL_TYPE == OS_MICROKERNEL */


#endif /* USED */
/* CHECK: PARSE */

/* Editor settings; DO NOT DELETE
 * vi:set ts=4:
*/
