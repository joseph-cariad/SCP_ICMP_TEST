/**
 * \file
 *
 * \brief AUTOSAR E2ESM
 *
 * This file contains the implementation of the AUTOSAR
 * module E2ESM.
 *
 * \version 1.1.10
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef E2E_SM_H
#define E2E_SM_H

/*==================[inclusions]=============================================*/

#include <E2E.h>                      /* AUTOSAR E2E library */
#include <E2EXf_Cfg.h>                /* Configuration parameters generated by the E2EXf MCG */

/*==================[macros]=================================================*/

/*------------------[AUTOSAR vendor identification]-------------------------*/

#if (defined E2ESM_VENDOR_ID) /* to prevent double declaration */
#error E2ESM_VENDOR_ID is already defined
#endif
/** \brief AUTOSAR vendor identification: Elektrobit Automotive GmbH */
#define E2ESM_VENDOR_ID         1U

/*------------------[AUTOSAR release version identification]----------------*/

#if (defined E2ESM_AR_RELEASE_MAJOR_VERSION) /* to prevent double declaration */
#error E2ESM_AR_RELEASE_MAJOR_VERSION already defined
#endif
/** \brief AUTOSAR release major version */
#define E2ESM_AR_RELEASE_MAJOR_VERSION  4U

#if (defined E2ESM_AR_RELEASE_MINOR_VERSION) /* to prevent double declaration */
#error E2ESM_AR_RELEASE_MINOR_VERSION already defined
#endif
/** \brief AUTOSAR release minor version */
#define E2ESM_AR_RELEASE_MINOR_VERSION  2U

#if (defined E2ESM_AR_RELEASE_REVISION_VERSION) /* to prevent double declaration */
#error E2ESM_AR_RELEASE_REVISION_VERSION already defined
#endif
/** \brief AUTOSAR release revision version */
#define E2ESM_AR_RELEASE_REVISION_VERSION  1U

/*------------------[AUTOSAR module version identification]------------------*/

#if (defined E2ESM_SW_MAJOR_VERSION) /* to prevent double declaration */
#error E2ESM_SW_MAJOR_VERSION already defined
#endif
/** \brief AUTOSAR module major version */
#define E2ESM_SW_MAJOR_VERSION  1U

#if (defined E2ESM_SW_MINOR_VERSION) /* to prevent double declaration */
#error E2ESM_SW_MINOR_VERSION already defined
#endif
/** \brief AUTOSAR module minor version */
#define E2ESM_SW_MINOR_VERSION  1U

#if (defined E2ESM_SW_PATCH_VERSION) /* to prevent double declaration */
#error E2ESM_SW_PATCH_VERSION already defined
#endif
/** \brief AUTOSAR module patch version */
#define E2ESM_SW_PATCH_VERSION  10U


/* individual states for E2E_SMStateType */

#if (defined E2E_SM_VALID) /* to prevent double declaration */
#error E2E_SM_VALID already defined
#endif
/** \brief Communication functioning properly according to E2E. */
#define E2E_SM_VALID 0U

#if (defined E2E_SM_DEINIT) /* to prevent double declaration */
#error E2E_SM_DEINIT already defined
#endif
/** \brief State before E2E_SMCheckInit() is invoked. */
#define E2E_SM_DEINIT 1U

#if (defined E2E_SM_NODATA) /* to prevent double declaration */
#error E2E_SM_NODATA already defined
#endif
/** \brief No data is available since the initialization.
 * This means there is no communication and there is no E2E-valid default value available. */
#define E2E_SM_NODATA 2U

#if (defined E2E_SM_INIT) /* to prevent double declaration */
#error E2E_SM_INIT already defined
#endif
/** \brief There has been yet no communication since the initialization. */
#define E2E_SM_INIT 3U

#if (defined E2E_SM_INVALID) /* to prevent double declaration */
#error E2E_SM_INVALID already defined
#endif
/** \brief There has been some communication since startup,
 * but not enough to switch to VALID. */
#define E2E_SM_INVALID 4U

/*==================[type definitions]=======================================*/

/**
 * \brief Definition of E2E State Machine communication channel configuration type.
 *
 * Configuration of a communication channel for exchanging Data.
 */
typedef struct
{
  uint8 WindowSize;
  /**< Size of the monitoring window for the state machine. */
  uint8 MinOkStateInit;
  /**< Minimal number of checks in which ProfileStatus equal to E2E_P_OK was
   *   determined within the last WindowSize checks (for the state E2E_SM_INIT)
   *   required to change to state E2E_SM_VALID. */
  uint8 MaxErrorStateInit;
  /**< Maximal number of checks in which ProfileStatus equal to E2E_P_ERROR was
   *   determined within the last WindowSize checks (for the state E2E_SM_INIT). */
  uint8 MinOkStateValid;
  /**< Minimal number of checks in which ProfileStatus equal to E2E_P_OK was
   *   determined within the last WindowSize checks (for the state E2E_SM_VALID)
   *   required to keep in state E2E_SM_VALID. */
  uint8 MaxErrorStateValid;
  /**< Maximal number of checks in which ProfileStatus equal to E2E_P_ERROR was
   *   determined, within the last WindowSize checks (for the state E2E_SM_VALID). */
  uint8 MinOkStateInvalid;
  /**< Minimum number of checks in which ProfileStatus equal to E2E_P_OK was
   *   determined within the last WindowSize checks (for the state E2E_SM_INVALID)
   *   required to change to state E2E_SM_VALID. */
  uint8 MaxErrorStateInvalid;
  /**< Maximal number of checks in which ProfileStatus equal to E2E_P_ERROR was
   *   determined within the last WindowSize checks (for the state E2E_SM_INVALID). */
} E2E_SMConfigType;

/**
 * \brief Definition of E2E State Machine state type.
 *
 * Status of the communication channel exchanging the data.
 * If the status is OK, then the data may be used.
 */
typedef uint8 E2E_SMStateType;

/**
 * \brief Definition of E2E State Machine check state type.
 *
 * State of the protection of a communication channel.
 */
typedef struct {
    uint8 ProfileStatusWindowArray[E2ESM_MAX_WINDOW_SIZE];
    /**< Array in which the ProfileStatus of the last
     *   E2E-checks are stored. The array size is fixed with E2ESM_MAX_WINDOW_SIZE. */
    uint8 WindowTopIndex;
    /**< Index in the array at which the next ProfileStatus is to be written. */
    uint8 OkCount;
    /**< Count of checks in which ProfileStatus equal to E2E_P_OK was determined
     *   within the last WindowSize checks. */
    uint8 ErrorCount;
    /**< Count of checks in which ProfileStatus equal to E2E_P_ERROR was determined
     *   within the last WindowSize checks. */
    E2E_SMStateType SMState;
    /**< The current state in the state machine. */
} E2E_SMCheckStateType;

/*==================[external constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[external function declarations]=========================*/

#define E2E_START_SEC_CODE
#include <E2E_MemMap.h>

/**
 * \brief Check the received Data using the E2E State Machine.
 *
 * Checks the communication channel. It determines if the data can be used for
 * safety-related application, based on history of checks performed by a
 * corresponding E2E_P0XCheck() function.
 *
 * \param[in]     ProfileStatus Profile-independent status of the reception on one single
 *                              Data in one cycle
 * \param[in]     ConfigPtr     Pointer to static configuration.
 * \param[in,out] StatePtr      Pointer to port/data communication state.
 *
 * \return Function execution success status
 * \retval E2E_E_INPUTERR_NULL At least one pointer parameter is a NULL pointer.
 * \retval E2E_E_INPUTERR_WRONG At least one input parameter is erroneous.
 * \retval E2E_E_INTERR At least one input parameter is erroneous.
 * \retval E2E_E_WRONGSTATE Function executed in wrong state.
 * \retval E2E_E_OK Function completed successfully.
 *
 * \pre Check state variable \a State has to be initialized before first call
 * \pre Parameter ConfigPtr is a valid Pointer
 * \pre Parameter StatePtr is a valid Pointer
 *
 * \ServiceID{0x30}
 * \Reentrancy{Reentrant for different check states}
 * \Synchronicity{Synchronous}
 */
extern FUNC(Std_ReturnType, E2E_CODE) E2E_SMCheck
(
    E2E_PCheckStatusType ProfileStatus,
    P2CONST(E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr,
    P2VAR(E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr
);

/**
 * \brief Initializes the E2E state machine.
 *
 * \param[in]     ConfigPtr     Pointer to static configuration.
 * \param[in,out] StatePtr      Pointer to port/data communication state.
 *
 * \return Function execution success status
 * \retval E2E_E_INPUTERR_NULL At least one pointer parameter is a NULL pointer.
 * \retval E2E_E_INPUTERR_WRONG At least one input parameter is erroneous.
 * \retval E2E_E_OK Function completed successfully.
 *
 * \pre Parameter ConfigPtr is a valid Pointer
 * \pre Parameter StatePtr is a valid Pointer
 *
 * \ServiceID{0x31}
 * \Reentrancy{Reentrant for different check states}
 * \Synchronicity{Synchronous}
 */
extern FUNC(Std_ReturnType, E2E_CODE) E2E_SMCheckInit
(
    P2VAR(E2E_SMCheckStateType, AUTOMATIC, E2E_APPL_DATA) StatePtr,
    P2CONST(E2E_SMConfigType, AUTOMATIC, E2E_APPL_CONST) ConfigPtr
);

#define E2E_STOP_SEC_CODE
#include <E2E_MemMap.h>

#endif /* ifndef E2E_SM_H */
/*==================[end of file]============================================*/
