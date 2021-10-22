/**
 * \file
 *
 * \brief AUTOSAR Dlt
 *
 * This file contains the implementation of the AUTOSAR
 * module Dlt.
 *
 * \version 1.8.6
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 8.3 (Required)
 *    "All declarations of an object or function shall use the same names and type qualifiers."
 *
 *    Reason:
 *    The function declaration is generated by the RTE with another parameter name.
 *
 **/
/*==[Includes]================================================================*/

#if (defined DLT_INTERNAL_USAGE)
#error DLT_INTERNAL_USAGE is already defined
#endif
#define DLT_INTERNAL_USAGE

#include <Dlt_BSW.h>

#if (DLT_INCLUDE_RTE == STD_ON)
#define RTE_PTR2ARRAYTYPE_PASSING
#include <Rte_Dlt.h>
#endif

/*==[Definition of functions with internal linkage]==========================*/

#if (DLT_INCLUDE_RTE == STD_ON)

#define Dlt_START_SEC_CODE
#include <Dlt_MemMap.h>

#if ( (DLT_MESSAGE_SERVICE_PORT == STD_ON) || (DLT_DEFAULT_ASR_RETVAL != AUTOSAR_431) )

FUNC(Dlt_ReturnType, DLT_CODE) Dlt_Rte_SendLogMessage(
    Dlt_SessionIDType session_id,
    P2CONST(Dlt_MessageLogInfoType, AUTOMATIC, DLT_APPL_CONST) log_info,
    P2CONST(uint8, AUTOMATIC, DLT_APPL_CONST) log_data,
    uint16 log_data_length)
{
  return Dlt_ASR43_SendLogMessage(session_id, log_info, log_data, log_data_length);
}

FUNC(Dlt_ReturnType, DLT_CODE) Dlt_Rte_SendTraceMessage(
    Dlt_SessionIDType session_id,
    P2CONST(Dlt_MessageTraceInfoType, AUTOMATIC, DLT_APPL_CONST) trace_info,
    P2CONST(uint8, AUTOMATIC, DLT_APPL_CONST) trace_data,
    uint16 trace_data_length)
{
  return Dlt_ASR43_SendTraceMessage(session_id, trace_info, trace_data, trace_data_length);
}

#endif /* #if ( (DLT_MESSAGE_SERVICE_PORT == STD_ON) || (DLT_DEFAULT_ASR_RETVAL != AUTOSAR_431) ) */

#if (DLT_MESSAGE_SERVICE_PORT == STD_ON)

FUNC(Dlt_ReturnType, DLT_CODE) Dlt_Rte_RegisterContext(
    Dlt_SessionIDType session_id,
    P2CONST(Dlt_ApplicationIDType, AUTOMATIC, DLT_APPL_CONST) app_id,
    P2CONST(Dlt_ContextIDType, AUTOMATIC, DLT_APPL_CONST) context_id,
    P2CONST(uint8, AUTOMATIC, DLT_APPL_CONST) app_description,
    uint8 len_app_description,
    P2CONST(uint8, AUTOMATIC, DLT_APPL_CONST) context_description,
    uint8 len_context_description)
{
  return Dlt_ASR43_RegisterContext(session_id,
                                   app_id,
                                   context_id,
                                   app_description,
                                   len_app_description,
                                   context_description,
                                   len_context_description);
}

FUNC(Dlt_ReturnType, DLT_CODE) Dlt_Rte_UnregisterContext(
    Dlt_SessionIDType sessionId,
    P2CONST(Dlt_ApplicationIDType, AUTOMATIC, DLT_APPL_CONST) appId,
    P2CONST(Dlt_ContextIDType, AUTOMATIC, DLT_APPL_CONST) contextId)
{
  return Dlt_ASR43_UnregisterContext(sessionId,
                                     appId,
                                     contextId);
}

#endif /* #if (DLT_MESSAGE_SERVICE_PORT == STD_ON) */

#if (DLT_DEFAULT_ASR_RETVAL != AUTOSAR_431)

FUNC(Dlt_ReturnType, DLT_CODE) Dlt_Rte_RegisterContext(
    Dlt_SessionIDType session_id,
    Dlt_ApplicationIDType app_id,
    Dlt_ContextIDType context_id,
    P2CONST(uint8, AUTOMATIC, DLT_APPL_CONST) app_description,
    uint8 len_app_description,
    P2CONST(uint8, AUTOMATIC, DLT_APPL_CONST) context_description,
    uint8 len_context_description)
{
  return Dlt_ASR43_RegisterContext(session_id,
                                   app_id,
                                   context_id,
                                   app_description,
                                   len_app_description,
                                   context_description,
                                   len_context_description);
}

#endif /* #if (DLT_DEFAULT_ASR_RETVAL != AUTOSAR_431) */

#if ( (DLT_DEFAULT_ASR_RETVAL != AUTOSAR_431) && (DLT_IMPLEMENT_NV_RAM_STORAGE == STD_ON) )
/* Deviation MISRAC2012-1 */
FUNC(Dlt_ReturnType, DLT_CODE) Dlt_Rte_StorePersistent(Dlt_SessionIDType session_id)
{
  return Dlt_StorePersistent(session_id);
}
#endif /* #if ( (DLT_DEFAULT_ASR_RETVAL != AUTOSAR_431) && (DLT_IMPLEMENT_NV_RAM_STORAGE == STD_ON) ) */

#if (DLT_CONTROL_SERVICE_PORT == STD_ON)
FUNC(Dlt_ReturnType, DLT_CODE) Dlt_Rte_SetLogChannelAssignment(
    P2CONST(Dlt_ApplicationIDType, AUTOMATIC, DLT_APPL_CONST) appId,
    P2CONST(Dlt_ContextIDType, AUTOMATIC, DLT_APPL_CONST) contextId,
    P2CONST(Dlt_LogChannelNameType, AUTOMATIC, DLT_APPL_CONST) logChannelName,
    Dlt_AssignmentOperationType addRemoveOp)
{
  /* !LINKSTO Dlt.EB_Req_DltControlService_SetLogChannelAssignment_Error, 1 */
  Dlt_ReturnType retVal = DLT_E_ERROR;

  if (E_OK == Dlt_ASR43_SetLogChannelAssignment(appId, contextId, logChannelName, addRemoveOp))
  {
    retVal = DLT_E_OK;
  }

  return retVal;
}

FUNC(Dlt_ReturnType, DLT_CODE) Dlt_Rte_GetLogChannelNames(
    P2VAR(uint8, AUTOMATIC, DLT_APPL_DATA) numberOfLogChannels,
    P2VAR(Dlt_LogChannelNameArrayType, AUTOMATIC, DLT_APPL_DATA) logChannelNames)
{
  /* !LINKSTO Dlt.EB_Req_DltControlService_GetLogChannelNames_Error, 1 */
  Dlt_ReturnType retVal = DLT_E_ERROR;

  if (E_OK == Dlt_ASR43_GetLogChannelNames(numberOfLogChannels, logChannelNames))
  {
    retVal = DLT_E_OK;
  }

  return retVal;
}

FUNC(Dlt_ReturnType, DLT_CODE) Dlt_Rte_SetLogChannelThreshold(
    P2CONST(Dlt_LogChannelNameType, AUTOMATIC, DLT_APPL_CONST) logChannelName,
    Dlt_MessageLogLevelType newThreshold,
    boolean newTraceStatus)
{
  /* !LINKSTO Dlt.EB_Req_DltControlService_SetLogChannelThreshold_Error, 1 */
  Dlt_ReturnType retVal = DLT_E_ERROR;

  if (E_OK == Dlt_ASR43_SetLogChannelThreshold(logChannelName, newThreshold, newTraceStatus))
  {
    retVal = DLT_E_OK;
  }

  return retVal;
}

FUNC(Dlt_ReturnType, DLT_CODE) Dlt_Rte_GetLogChannelThreshold(
    P2CONST(Dlt_LogChannelNameType, AUTOMATIC, DLT_APPL_CONST) logChannelName,
    P2VAR(Dlt_MessageLogLevelType, AUTOMATIC, DLT_APPL_DATA) logChannelThreshold,
    P2VAR(boolean, AUTOMATIC, DLT_APPL_DATA) traceStatus)
{
  /* !LINKSTO Dlt.EB_Req_DltControlService_GetLogChannelThreshold_Error, 1 */
  Dlt_ReturnType retVal = DLT_E_ERROR;

  if (E_OK == Dlt_ASR43_GetLogChannelThreshold(logChannelName, logChannelThreshold, traceStatus))
  {
    retVal = DLT_E_OK;
  }

  return retVal;
}

FUNC(Dlt_ReturnType, DLT_CODE) Dlt_Rte_SetLogLevel(
    P2CONST(Dlt_ApplicationIDType, AUTOMATIC, DLT_APPL_CONST) appId,
    P2CONST(Dlt_ContextIDType, AUTOMATIC, DLT_APPL_CONST) contextId,
    Dlt_MessageLogLevelType newLogLevel)
{
  /* !LINKSTO Dlt.EB_Req_DltControlService_SetLogLevel_Error, 1 */
  Dlt_ReturnType retVal = DLT_E_ERROR;

  if (E_OK == Dlt_ASR43_SetLogLevel(appId, contextId, newLogLevel))
  {
    retVal = DLT_E_OK;
  }

  return retVal;
}

FUNC(Dlt_ReturnType, DLT_CODE) Dlt_Rte_SetTraceStatus(
    P2CONST(Dlt_ApplicationIDType, AUTOMATIC, DLT_APPL_CONST) appId,
    P2CONST(Dlt_ContextIDType, AUTOMATIC, DLT_APPL_CONST) contextId,
    boolean newTraceStatus)
{
  /* !LINKSTO Dlt.EB_Req_DltControlService_SetTraceStatus_Error, 1 */
  Dlt_ReturnType retVal = DLT_E_ERROR;

  if (E_OK == Dlt_ASR43_SetTraceStatus(appId, contextId, newTraceStatus))
  {
    retVal = DLT_E_OK;
  }

  return retVal;
}

FUNC(Dlt_ReturnType, DLT_CODE) Dlt_Rte_GetTraceStatus(
    P2CONST(Dlt_ApplicationIDType, AUTOMATIC, DLT_APPL_CONST) appId,
    P2CONST(Dlt_ContextIDType, AUTOMATIC, DLT_APPL_CONST) contextId,
    P2VAR(boolean, AUTOMATIC, DLT_APPL_DATA) traceStatus)
{
  /* !LINKSTO Dlt.EB_Req_DltControlService_GetTraceStatus_Error, 1 */
  Dlt_ReturnType retVal = DLT_E_ERROR;

  if (E_OK == Dlt_ASR43_GetTraceStatus(appId, contextId, traceStatus))
  {
    retVal = DLT_E_OK;
  }

  return retVal;
}

FUNC(Dlt_ReturnType, DLT_CODE) Dlt_Rte_GetLogInfo(
    uint8 options,
    P2CONST(Dlt_ApplicationIDType, AUTOMATIC, DLT_APPL_CONST) appId,
    P2CONST(Dlt_ContextIDType, AUTOMATIC, DLT_APPL_CONST) contextId,
    P2VAR(uint8, AUTOMATIC, DLT_APPL_DATA) status,
    P2VAR(uint8, AUTOMATIC, DLT_APPL_DATA) logInfo)
{
  /* !LINKSTO Dlt.EB_Req_DltControlService_GetLogInfo_Error, 1 */
  Dlt_ReturnType retVal = DLT_E_ERROR;

  if (E_OK == Dlt_ASR43_GetLogInfo(options, appId, contextId, status, logInfo))
  {
    retVal = DLT_E_OK;
  }

  return retVal;
}

FUNC(Dlt_ReturnType, DLT_CODE) Dlt_Rte_GetDefaultLogLevel(
    P2VAR(Dlt_MessageLogLevelType, AUTOMATIC, DLT_APPL_DATA) defaultLogLevel)
{
  /* !LINKSTO Dlt.EB_Req_DltControlService_GetDefaultLogLevel_Error, 1 */
  Dlt_ReturnType retVal = DLT_E_ERROR;

  if (E_OK == Dlt_ASR43_GetDefaultLogLevel(defaultLogLevel))
  {
    retVal = DLT_E_OK;
  }

  return retVal;
}

FUNC(Dlt_ReturnType, DLT_CODE) Dlt_Rte_SetDefaultLogLevel(Dlt_MessageLogLevelType newLogLevel)
{
  /* !LINKSTO Dlt.EB_Req_DltControlService_SetDefaultLogLevel_Error, 1 */
  Dlt_ReturnType retVal = DLT_E_ERROR;

  if (E_OK == Dlt_ASR43_SetDefaultLogLevel(newLogLevel))
  {
    retVal = DLT_E_OK;
  }

  return retVal;
}

FUNC(Dlt_ReturnType, DLT_CODE) Dlt_Rte_GetDefaultTraceStatus(
    P2VAR(boolean, AUTOMATIC, DLT_APPL_DATA) traceStatus)
{
  /* !LINKSTO Dlt.EB_Req_DltControlService_GetDefaultTraceStatus_Error, 1 */
  Dlt_ReturnType retVal = DLT_E_ERROR;

  if (E_OK == Dlt_ASR43_GetDefaultTraceStatus(traceStatus))
  {
    retVal = DLT_E_OK;
  }

  return retVal;
}

FUNC(Dlt_ReturnType, DLT_CODE) Dlt_Rte_SetDefaultTraceStatus(boolean newTraceStatus)
{
  /* !LINKSTO Dlt.EB_Req_DltControlService_SetDefaultTraceStatus_Error, 1 */
  Dlt_ReturnType retVal = DLT_E_ERROR;

  if (E_OK == Dlt_ASR43_SetDefaultTraceStatus(newTraceStatus))
  {
    retVal = DLT_E_OK;
  }

  return retVal;
}

FUNC(Dlt_ReturnType, DLT_CODE) Dlt_Rte_SetMessageFiltering(boolean status)
{
  /* !LINKSTO Dlt.EB_Req_DltControlService_SetMessageFiltering_Error, 1 */
  Dlt_ReturnType retVal = DLT_E_ERROR;

  if (E_OK == Dlt_ASR43_SetMessageFiltering(status))
  {
    retVal = DLT_E_OK;
  }

  return retVal;
}

FUNC(Dlt_ReturnType, DLT_CODE) Dlt_Rte_ResetToFactoryDefault(void)
{
  /* !LINKSTO Dlt.EB_Req_DltControlService_ResetToFactoryDefault_Error, 1 */
  Dlt_ReturnType retVal = DLT_E_ERROR;

  if (E_OK == Dlt_ASR43_ResetToFactoryDefault())
  {
    retVal = DLT_E_OK;
  }

  return retVal;
}

FUNC(Dlt_ReturnType, DLT_CODE) Dlt_Rte_StoreConfiguration(void)
{
  /* !LINKSTO Dlt.EB_Req_DltControlService_StoreConfiguration_Error, 1 */
  Dlt_ReturnType retVal = DLT_E_ERROR;

  if (E_OK == Dlt_ASR43_StoreConfiguration())
  {
    retVal = DLT_E_OK;
  }

  return retVal;
}
#endif /* #if (DLT_CONTROL_SERVICE_PORT == STD_ON) */

#define Dlt_STOP_SEC_CODE
#include <Dlt_MemMap.h>

#endif /* #if (DLT_RTE_USAGE == STD_ON) */
