/**
 * \file
 *
 * \brief AUTOSAR CanSM
 *
 * This file contains the implementation of the AUTOSAR
 * module CanSM.
 *
 * \version 3.7.5
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* tasking Deviation List
 *
 * TASKING-1) Deviated Rule: W549
 * W549: condition is always true violated
 *
 * Reason:
 * False-positive from the Tasking v5.0r2 compiler (TCVX-41885)
 */

/*==================[inclusions]============================================*/

#include <CanSM_Trace.h>
#include <TSAutosar.h>              /* EB specific standard types */
#include <ComStack_Types.h>         /* AUTOSAR communication stack types */

#include <CanSM_SchM.h>             /* Module SchM API */
#include <CanSM_Internal.h>         /* Module private API */

#if ( CANSM_PROD_ERR_HANDLING_BUS_OFF == TS_PROD_ERR_REP_TO_DEM )
#include <Dem.h>                    /* Diagnostic Event Manager */
#endif /* CANSM_PROD_ERR_HANDLING_BUS_OFF == TS_PROD_ERR_REP_TO_DEM */
#if ( ( CANSM_PROD_ERR_HANDLING_BUS_OFF == TS_PROD_ERR_REP_TO_DET ) && \
      ( CANSM_DEV_ERROR_DETECT == STD_ON ) )
#include <Det.h>                    /* Development Error Tracer */
#endif

/*==================[version check]=========================================*/

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[internal function declarations]========================*/

/*==================[internal constants]====================================*/

/*==================[internal data]=========================================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

/*==================[external function definitions]=========================*/

#define CANSM_START_SEC_CODE
#include <CanSM_MemMap.h>

FUNC(void, CANSM_CODE) CanSM_MainFunction (
  void
)
{
  CanSM_NetworkIndexType nw;

  DBG_CANSM_MAINFUNCTION_ENTRY();

  /* !LINKSTO CanSM.EB.Api.CanSM_MainFunction.Uninitialized,1 */
  if (CanSM_GlobalInit == CANSM_GLOBAL_INIT)
  {
    /* Deviation TASKING-1 */
    for ( nw=0U; nw<CANSM_NETWORKS_NUM; nw++ )
    {
      CanSM_MainFunctionInternal(nw);
    } /* loop over networks */
  } /* else of ( CanSM_GlobalInit == CANSM_GLOBAL_UNINIT ) */

  DBG_CANSM_MAINFUNCTION_EXIT();
}

#define CANSM_STOP_SEC_CODE
#include <CanSM_MemMap.h>

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/

