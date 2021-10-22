/**
 * \file
 *
 * \brief AUTOSAR E2EP05
 *
 * This file contains the implementation of the AUTOSAR
 * module E2EP05.
 *
 * \version 1.0.11
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*
 * MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 20.10 (advisory)
 * The # and ## preprocessor operators should not be used.
 *
 * Reason:
 * ## operator is used for code generation via pre-processor.
 */

#ifndef E2E_P05_E2EXF_H
#define E2E_P05_E2EXF_H

/*==================[inclusions]============================================*/

#include <E2E_E2EXf_Stc.h>      /* Static definitions of constants and types */

#if (E2EXF_IN_USE == STD_ON)

#include <E2E_P05.h>            /* E2E Profile P05 */
#include <E2E_SM.h>             /* E2E State Machine */

/*==================[macros]================================================*/

/* Deviation MISRAC2012-1 <START> */

#if (defined E2EXF_DEF_XFSTATEVAR_XF_P05_INPLACE) /* to prevent double declaration */
#error E2EXF_DEF_XFSTATEVAR_XF_P05_INPLACE already defined
#endif /* if (defined E2EXF_DEF_XFSTATEVAR_XF_P05_INPLACE) */
/** \brief Define internal state variable of E2E in-place protect-transformer for E2E Profile P05 */
#define E2EXF_DEF_XFSTATEVAR_XF_P05_INPLACE(XfrmName) \
    static VAR(E2E_P05ProtectStateType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectState_##XfrmName

#if (defined E2EXF_DEF_XFSTATEVAR_XF_P05_OUTOFPLACE) /* to prevent double declaration */
#error E2EXF_DEF_XFSTATEVAR_XF_P05_OUTOFPLACE already defined
#endif /* if (defined E2EXF_DEF_XFSTATEVAR_XF_P05_OUTOFPLACE) */
/** \brief Define internal state variable of E2E out-of-place protect-transformer for
 *  E2E Profile P05 */
#define E2EXF_DEF_XFSTATEVAR_XF_P05_OUTOFPLACE(XfrmName) \
    E2EXF_DEF_XFSTATEVAR_XF_P05_INPLACE(XfrmName)

#if (defined E2EXF_DEF_XFSTATEVAR_INVXF_P05_INPLACE) /* to prevent double declaration */
#error E2EXF_DEF_XFSTATEVAR_INVXF_P05_INPLACE already defined
#endif /* if (defined E2EXF_DEF_XFSTATEVAR_INVXF_P05_INPLACE) */
/** \brief Define internal state variable of E2E in-place check-transformer for E2E Profile P05 */
#define E2EXF_DEF_XFSTATEVAR_INVXF_P05_INPLACE(XfrmName) \
    static VAR(E2EXf_P05CheckStatesType, E2EXF_VAR_CLEARED) E2EXf_P05CheckStates_##XfrmName

#if (defined E2EXF_DEF_XFSTATEVAR_INVXF_P05_OUTOFPLACE) /* to prevent double declaration */
#error E2EXF_DEF_XFSTATEVAR_INVXF_P05_OUTOFPLACE already defined
#endif /* if (defined E2EXF_DEF_XFSTATEVAR_INVXF_P05_OUTOFPLACE) */
/** \brief Define internal state variable of E2E out-of-place check-transformer for
 *  E2E Profile P05 */
#define E2EXF_DEF_XFSTATEVAR_INVXF_P05_OUTOFPLACE(XfrmName) \
    E2EXF_DEF_XFSTATEVAR_INVXF_P05_INPLACE(XfrmName)

#if (defined E2EXF_DEF_CFG_XF_P05_INPLACE) /* to prevent double declaration */
#error E2EXF_DEF_CFG_XF_P05_INPLACE already defined
#endif /* if (defined E2EXF_DEF_CFG_XF_P05_INPLACE) */
/** \brief Define configuration data of E2E in-place protect-transformer for E2E Profile P05*/
#define E2EXF_DEF_CFG_XF_P05_INPLACE(XfrmName) \
    static CONST(E2EXf_P05ProtectCfgType, E2EXF_VAR_CLEARED) E2EXf_P05ProtectCfg_##XfrmName

#if (defined E2EXF_DEF_CFG_XF_P05_OUTOFPLACE) /* to prevent double declaration */
#error E2EXF_DEF_CFG_XF_P05_OUTOFPLACE already defined
#endif /* if (defined E2EXF_DEF_CFG_XF_P05_OUTOFPLACE) */
/** \brief Define configuration data of E2E out-of-place protect-transformer for
 *  E2E Profile P05*/
#define E2EXF_DEF_CFG_XF_P05_OUTOFPLACE(XfrmName) \
    E2EXF_DEF_CFG_XF_P05_INPLACE(XfrmName)

#if (defined E2EXF_DEF_CFG_INVXF_P05_INPLACE) /* to prevent double declaration */
#error E2EXF_DEF_CFG_INVXF_P05_INPLACE already defined
#endif /* if (defined E2EXF_DEF_CFG_INVXF_P05_INPLACE) */
/** \brief Define configuration data of E2E in-place check-transformer for E2E Profile P05 */
#define E2EXF_DEF_CFG_INVXF_P05_INPLACE(XfrmName) \
    static CONST(E2EXf_P05CheckCfgType, E2EXF_VAR_CLEARED) E2EXf_P05CheckCfg_##XfrmName

#if (defined E2EXF_DEF_CFG_INVXF_P05_OUTOFPLACE) /* to prevent double declaration */
#error E2EXF_DEF_CFG_INVXF_P05_OUTOFPLACE already defined
#endif /* if (defined E2EXF_DEF_CFG_INVXF_P05_OUTOFPLACE) */
/** \brief Define configuration data of E2E out-of-place check-transformer for
 *  E2E Profile P05 */
#define E2EXF_DEF_CFG_INVXF_P05_OUTOFPLACE(XfrmName) \
    E2EXF_DEF_CFG_INVXF_P05_INPLACE(XfrmName)

#if (defined E2EXF_INIT_XFSTATEVAR_XF_P05_INPLACE) /* to prevent double declaration */
#error E2EXF_INIT_XFSTATEVAR_XF_P05_INPLACE already defined
#endif /* if (defined E2EXF_INIT_XFSTATEVAR_XF_P05_INPLACE) */
/** \brief Initialize E2E in-place protect-transformer for E2E Profile P05 */
#define E2EXF_INIT_XFSTATEVAR_XF_P05_INPLACE(XfrmName) \
    RetVal |= E2E_P05ProtectInit(&(E2EXf_P05ProtectState_##XfrmName))

#if (defined E2EXF_INIT_XFSTATEVAR_XF_P05_OUTOFPLACE) /* to prevent double declaration */
#error E2EXF_INIT_XFSTATEVAR_XF_P05_OUTOFPLACE already defined
#endif /* if (defined E2EXF_INIT_XFSTATEVAR_XF_P05_OUTOFPLACE) */
/** \brief Initialize E2E out-of-place protect-transformer for E2E Profile P05 */
#define E2EXF_INIT_XFSTATEVAR_XF_P05_OUTOFPLACE(XfrmName) \
    E2EXF_INIT_XFSTATEVAR_XF_P05_INPLACE(XfrmName)

#if (defined E2EXF_INIT_XFSTATEVAR_INVXF_P05_INPLACE) /* to prevent double declaration */
#error E2EXF_INIT_XFSTATEVAR_INVXF_P05_INPLACE already defined
#endif /* if (defined E2EXF_INIT_XFSTATEVAR_INVXF_P05_INPLACE) */
/** \brief Initialize E2E in-place check-transformer for E2E Profile P05 */
#define E2EXF_INIT_XFSTATEVAR_INVXF_P05_INPLACE(XfrmName) \
    do { \
        RetVal |= E2E_P05CheckInit(&(E2EXf_P05CheckStates_##XfrmName.P05CheckState)); \
        RetVal |= E2E_SMCheckInit(&(E2EXf_P05CheckStates_##XfrmName.SMCheckState), \
                 &(E2EXf_P05CheckCfg_##XfrmName.SMConfig)); \
    } while(0)

#if (defined E2EXF_INIT_XFSTATEVAR_INVXF_P05_OUTOFPLACE) /* to prevent double declaration */
#error E2EXF_INIT_XFSTATEVAR_INVXF_P05_OUTOFPLACE already defined
#endif /* if (defined E2EXF_INIT_XFSTATEVAR_INVXF_P05_OUTOFPLACE) */
/** \brief Initialize E2E out-of-place check-transformer for E2E Profile P05 */
#define E2EXF_INIT_XFSTATEVAR_INVXF_P05_OUTOFPLACE(XfrmName) \
    E2EXF_INIT_XFSTATEVAR_INVXF_P05_INPLACE(XfrmName)

#if (defined E2EXF_DEF_FUNC_XF_P05_INPLACE) /* to prevent double declaration */
#error E2EXF_DEF_FUNC_XF_P05_INPLACE already defined
#endif /* if (defined E2EXF_DEF_FUNC_XF_P05_INPLACE) */
/** \brief Define E2E in-place protect-transformer function for E2E Profile P05 */
#define E2EXF_DEF_FUNC_XF_P05_INPLACE(XfrmName) \
    FUNC(uint8, E2EXF_CODE) XfrmName \
    ( \
        P2VAR(uint8, AUTOMATIC, E2EXF_APPL_DATA) BufferPtr, \
        P2VAR(E2EXF_XFRMBUFFERLENGTH_TYPE, AUTOMATIC, E2EXF_APPL_DATA) BufferLengthPtr, \
        E2EXF_XFRMBUFFERLENGTH_TYPE InputBufferLength \
    ) \
    { \
       return E2EXf_P05InPlace_Transformer(BufferPtr, \
                BufferLengthPtr, \
                InputBufferLength, \
                &(E2EXf_P05ProtectState_##XfrmName), \
                &(E2EXf_P05ProtectCfg_##XfrmName), \
                E2EXF_EB_PARTITIONINITSTATEVAR_NAME); \
    }

#if (defined E2EXF_DEF_FUNC_INVXF_P05_INPLACE) /* to prevent double declaration */
#error E2EXF_DEF_FUNC_INVXF_P05_INPLACE already defined
#endif /* if (defined E2EXF_DEF_FUNC_INVXF_P05_INPLACE) */
/** \brief Define E2E in-place check-transformer function for E2E Profile P05 */
#define E2EXF_DEF_FUNC_INVXF_P05_INPLACE(XfrmName) \
    FUNC(uint8, E2EXF_CODE) XfrmName \
    ( \
        P2VAR(uint8, AUTOMATIC, E2EXF_APPL_DATA) BufferPtr, \
        P2VAR(E2EXF_XFRMBUFFERLENGTH_TYPE, AUTOMATIC, E2EXF_APPL_DATA) BufferLengthPtr, \
        E2EXF_XFRMBUFFERLENGTH_TYPE InputBufferLength \
    ) \
    { \
        return E2EXf_Inv_P05InPlace_Transformer(BufferPtr, \
                 BufferLengthPtr, \
                 InputBufferLength, \
                 &(E2EXf_P05CheckStates_##XfrmName), \
                 &(E2EXf_P05CheckCfg_##XfrmName), \
                 E2EXF_EB_PARTITIONINITSTATEVAR_NAME); \
    }

#if (defined E2EXF_DEF_FUNC_XF_P05_OUTOFPLACE) /* to prevent double declaration */
#error E2EXF_DEF_FUNC_XF_P05_OUTOFPLACE already defined
#endif /* if (defined E2EXF_DEF_FUNC_XF_P05_OUTOFPLACE) */
/** \brief Define E2E out-of-place protect-transformer function for E2E Profile P05 */
#define E2EXF_DEF_FUNC_XF_P05_OUTOFPLACE(XfrmName) \
    FUNC(uint8, E2EXF_CODE) XfrmName \
    ( \
        P2VAR(uint8, AUTOMATIC, E2EXF_APPL_DATA) BufferPtr, \
        P2VAR(E2EXF_XFRMBUFFERLENGTH_TYPE, AUTOMATIC, E2EXF_APPL_DATA) BufferLengthPtr, \
        P2CONST(uint8, AUTOMATIC, E2EXF_APPL_DATA) InputBufferPtr, \
        E2EXF_XFRMBUFFERLENGTH_TYPE InputBufferLength \
    ) \
    { \
       return E2EXf_P05OutOfPlace_Transformer(BufferPtr, \
                BufferLengthPtr, \
                InputBufferPtr, \
                InputBufferLength, \
                &(E2EXf_P05ProtectState_##XfrmName), \
                &(E2EXf_P05ProtectCfg_##XfrmName), \
                E2EXF_EB_PARTITIONINITSTATEVAR_NAME); \
    }

#if (defined E2EXF_DEF_FUNC_INVXF_P05_OUTOFPLACE) /* to prevent double declaration */
#error E2EXF_DEF_FUNC_INVXF_P05_OUTOFPLACE already defined
#endif /* if (defined E2EXF_DEF_FUNC_INVXF_P05_OUTOFPLACE) */
/** \brief Define E2E out-of-place check-transformer function for E2E Profile P05 */
#define E2EXF_DEF_FUNC_INVXF_P05_OUTOFPLACE(XfrmName) \
    FUNC(uint8, E2EXF_CODE) XfrmName \
    ( \
        P2VAR(uint8, AUTOMATIC, E2EXF_APPL_DATA) BufferPtr, \
        P2VAR(E2EXF_XFRMBUFFERLENGTH_TYPE, AUTOMATIC, E2EXF_APPL_DATA) BufferLengthPtr, \
        P2CONST(uint8, AUTOMATIC, E2EXF_APPL_DATA) InputBufferPtr, \
        E2EXF_XFRMBUFFERLENGTH_TYPE InputBufferLength \
    ) \
    { \
        return E2EXf_Inv_P05OutOfPlace_Transformer(BufferPtr, \
                 BufferLengthPtr, \
                 InputBufferPtr, \
                 InputBufferLength, \
                 &(E2EXf_P05CheckStates_##XfrmName), \
                 &(E2EXf_P05CheckCfg_##XfrmName), \
                 E2EXF_EB_PARTITIONINITSTATEVAR_NAME); \
    }

/* Deviation MISRAC2012-1 <STOP> */

/*==================[macro checks]==========================================*/

/*==================[type definitions]======================================*/

/* E2E protect-transformer configuration data of E2E Profile P05 */
typedef struct
{
    E2E_P05ConfigType P05Config;
    E2EXf_PXXConfigType PXXConfig;
} E2EXf_P05ProtectCfgType;

/* E2E check-transformer configuration data of E2E Profile P05 */
typedef struct
{
    E2E_P05ConfigType P05Config;
    E2E_SMConfigType SMConfig;
    E2EXf_PXXConfigType PXXConfig;
} E2EXf_P05CheckCfgType;

/* Wrap E2E check-transformer states of E2E Profile P05 */
typedef struct
{
    E2E_P05CheckStateType P05CheckState;
    E2E_SMCheckStateType SMCheckState;
} E2EXf_P05CheckStatesType;

/*==================[external function declarations]========================*/

#define E2E_START_SEC_CODE
#include <E2E_MemMap.h>

/** \brief Declare E2E in-place (protect-)transformer for E2E Profile P05 */
extern FUNC(uint8, E2E_CODE) E2EXf_P05InPlace_Transformer
(
    P2VAR(uint8, AUTOMATIC, E2E_APPL_DATA) BufferPtr,
    P2VAR(E2EXF_XFRMBUFFERLENGTH_TYPE, AUTOMATIC, E2E_APPL_DATA) BufferLengthPtr,
    E2EXF_XFRMBUFFERLENGTH_TYPE InputBufferLength,
    P2VAR(E2E_P05ProtectStateType, AUTOMATIC, E2E_VAR_CLEARED) ProtectStatePtr,
    P2CONST(E2EXf_P05ProtectCfgType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
    E2EXf_StateType E2EXf_PartitionInitState
);

/** \brief Declare E2E out-of-place (protect-)transformer for E2E Profile P05 */
extern FUNC(uint8, E2E_CODE) E2EXf_P05OutOfPlace_Transformer
(
    P2VAR(uint8, AUTOMATIC, E2E_APPL_DATA) BufferPtr,
    P2VAR(E2EXF_XFRMBUFFERLENGTH_TYPE, AUTOMATIC, E2E_APPL_DATA) BufferLengthPtr,
    P2CONST(uint8, AUTOMATIC, E2E_APPL_DATA) InputBufferPtr,
    E2EXF_XFRMBUFFERLENGTH_TYPE InputBufferLength,
    P2VAR(E2E_P05ProtectStateType, AUTOMATIC, E2E_VAR_CLEARED) ProtectStatePtr,
    P2CONST(E2EXf_P05ProtectCfgType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
    E2EXf_StateType E2EXf_PartitionInitState
);

/** \brief Declare E2E in-place inverted (check-)transformer for E2E Profile P05 */
extern FUNC(uint8, E2E_CODE) E2EXf_Inv_P05InPlace_Transformer
(
    P2VAR(uint8, AUTOMATIC, E2E_APPL_DATA) BufferPtr,
    P2VAR(E2EXF_XFRMBUFFERLENGTH_TYPE, AUTOMATIC, E2E_APPL_DATA) BufferLengthPtr,
    E2EXF_XFRMBUFFERLENGTH_TYPE InputBufferLength,
    P2VAR(E2EXf_P05CheckStatesType, AUTOMATIC, E2E_VAR_CLEARED) CheckStatesPtr,
    P2CONST(E2EXf_P05CheckCfgType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
    E2EXf_StateType E2EXf_PartitionInitState
);

/** \brief Declare E2E out-of-place inverted (check-)transformer for E2E Profile P05 */
extern FUNC(uint8, E2E_CODE) E2EXf_Inv_P05OutOfPlace_Transformer
(
    P2VAR(uint8, AUTOMATIC, E2E_APPL_DATA) BufferPtr,
    P2VAR(E2EXF_XFRMBUFFERLENGTH_TYPE, AUTOMATIC, E2E_APPL_DATA) BufferLengthPtr,
    P2CONST(uint8, AUTOMATIC, E2E_APPL_DATA) InputBufferPtr,
    E2EXF_XFRMBUFFERLENGTH_TYPE InputBufferLength,
    P2VAR(E2EXf_P05CheckStatesType, AUTOMATIC, E2E_VAR_CLEARED) CheckStatesPtr,
    P2CONST(E2EXf_P05CheckCfgType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
    E2EXf_StateType E2EXf_PartitionInitState
);

#define E2E_STOP_SEC_CODE
#include <E2E_MemMap.h>

#endif /* (E2EXF_IN_USE == STD_ON) */

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef E2E_P05_E2EXF_H */
/*==================[end of file]===========================================*/
