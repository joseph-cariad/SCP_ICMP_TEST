/**
 * \file
 *
 * \brief AUTOSAR EcuM
 *
 * This file contains the implementation of the AUTOSAR
 * module EcuM.
 *
 * \version 5.15.7
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/* !LINKSTO EcuM2993,1 */
#ifndef ECUM_CFG_H
#define ECUM_CFG_H

/*==================[includes]==============================================*/

#include <Os.h>                 /* OS AppMode */
#include <Std_Types.h>          /* AUTOSAR standard types */
#include <EcuM_PbCfgTypes.h>

/*==================[macros]================================================*/

/* !LINKSTO EcuM.Impl.PBVariant.Hash,1 */
#if (defined ECUM_CFG_SIGNATURE)
#error ECUM_CFG_SIGNATURE already defined
#endif
#define ECUM_CFG_SIGNATURE [!"asc:getConfigSignature(as:modconf('EcuM')[1]//*[not(child::*) and (node:configclass() = 'PreCompile') ])"!]U /* Compile time verification value */

#if (defined ECUM_PUBLIC_INFO_SIGNATURE)
#error ECUM_PUBLIC_INFO_SIGNATURE already defined
#endif
#define ECUM_PUBLIC_INFO_SIGNATURE [!"asc:getConfigSignature(node:difference(as:modconf('EcuM')[1]/CommonPublishedInformation//*[not(child::*) and (node:configclass() = 'PublishedInformation') ], as:modconf('EcuM')[1]/CommonPublishedInformation/Release))"!]U /* PublicInfoSignature */

/*  Pre-processor switch to enable/diable relocateable postbuild config */
/* !LINKSTO EcuM.Impl.PBVariant.Relocatable,1 */
#if (defined ECUM_RELOCATABLE_CFG_ENABLE)
#error ECUM_RELOCATABLE_CFG_ENABLE already defined
#endif
#define ECUM_RELOCATABLE_CFG_ENABLE [!IF "as:modconf('EcuM')[1]/EcuMGeneral/EcuMRelocatablePbcfgEnable = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

/*------------------[EcuM Multi-Core implementation macros]-----------------------*/

[!VAR "MULTICORE_ENABLED" = "node:exists(as:modconf('Os')[1]/OsOS/OsNumberOfCores) and node:value(as:modconf('Os')/OsOS/OsNumberOfCores) > 1 and node:value(as:modconf('EcuM')/EcuMGeneral/EcuMEnableMulticore) = 'true'"!]

#if (defined ECUM_MULTICORE_ENABLED)
#error ECUM_MULTICORE_ENABLED already defined
#endif
/** \brief Preprocessor macro verifying if the multicore functionality is enabled. */
#define ECUM_MULTICORE_ENABLED [!IF "$MULTICORE_ENABLED"!]TRUE[!ELSE!]FALSE[!ENDIF!]

#if (defined RTE_CONFIG_PRESENT)
#error RTE_CONFIG_PRESENT already defined
#endif
/** \brief Macro for preventing redundant declarations of EcuM_MainFunction(),
since the function prototype is also generated by the SchM or Rte. **/
#define RTE_CONFIG_PRESENT [!IF "node:exists(as:modconf('Rte'))"!]TRUE[!ELSE!]FALSE[!ENDIF!]

#if (defined ECUM_EB_SERVICE_API_NONE)
#error ECUM_EB_SERVICE_API_NONE already defined
#endif
/** \brief Definition that no service API is set as default **/
#define ECUM_EB_SERVICE_API_NONE 0U

#if (defined ECUM_EB_SERVICE_API_ASR32)
#error ECUM_EB_SERVICE_API_ASR32 already defined
#endif
/** \brief Definition that AUTOSAR 3.2 service API is set as default **/
#define ECUM_EB_SERVICE_API_ASR32 32U

#if (defined ECUM_EB_SERVICE_API_ASR40)
#error ECUM_EB_SERVICE_API_ASR40 already defined
#endif
/** \brief Definition that AUTOSAR 4.0 service API is set as default **/
#define ECUM_EB_SERVICE_API_ASR40 40U

#if (defined ECUM_EB_ENABLE_ASR32_SERVICE_API)
#error ECUM_EB_ENABLE_ASR32_SERVICE_API already defined
#endif
/** \brief Definition whether AUTOSAR 3.2 service API for EcuM is enabled **/
#define ECUM_EB_ENABLE_ASR32_SERVICE_API                   [!//
[!IF "EcuMGeneral/EcuMServiceAPI/EcuMEnableASR32ServiceAPI = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

#if (defined ECUM_EB_ENABLE_ASR40_SERVICE_API)
#error ECUM_EB_ENABLE_ASR40_SERVICE_API already defined
#endif
/** \brief Definition whether AUTOSAR 4.0 service API for EcuM is enabled **/
#define ECUM_EB_ENABLE_ASR40_SERVICE_API                   [!//
[!IF "EcuMGeneral/EcuMServiceAPI/EcuMEnableASR40ServiceAPI = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

#if (defined ECUM_EB_DEFAULT_ASR_SERVICE_API)
#error ECUM_EB_DEFAULT_ASR_SERVICE_API already defined
#endif
/** \brief Definition of default service API **/
#define ECUM_EB_DEFAULT_ASR_SERVICE_API                    [!//
[!IF "EcuMGeneral/EcuMServiceAPI/EcuMDefaultASRServiceAPI = 'AUTOSAR_32'"!]ECUM_EB_SERVICE_API_ASR32
[!ELSEIF "EcuMGeneral/EcuMServiceAPI/EcuMDefaultASRServiceAPI = 'AUTOSAR_40'"!]ECUM_EB_SERVICE_API_ASR40
[!ELSE!]ECUM_EB_SERVICE_API_NONE
[!ENDIF!]

/** \brief Switch for DET usage */
/* !LINKSTO EcuM2983,1 */
#define ECUM_DEV_ERROR_DETECT      [!//
[!IF "EcuMGeneral/EcuMDevErrorDetect = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

#if (defined ECUM_INCLUDE_DET)
#error ECUM_INCLUDE_DET already defined
#endif
/** \brief Initialize Det module at startup **/
#define ECUM_INCLUDE_DET           [!//
[!IF "EcuMGeneral/EcuMIncludeDet = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

#if (defined ECUM_INCLUDE_DEM)
#error ECUM_INCLUDE_DEM already defined
#endif
/** \brief Initialize Dem module at startup **/
#define ECUM_INCLUDE_DEM           [!//
[!IF "EcuMGeneral/EcuMIncludeDem = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

#if (defined ECUM_INCLUDE_RTE)
#error ECUM_INCLUDE_RTE already defined
#endif
/** \brief Check if Rte is used in EcuM **/
#define ECUM_INCLUDE_RTE           [!//
[!IF "EcuMGeneral/EcuMRteUsage = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

#if (defined ECUM_USE_BOOTTARGET_SEC)
#error ECUM_USE_BOOTTARGET_SEC already defined
#endif
/** \brief Use special memory section for EcuM_BootTarget */
#define ECUM_USE_BOOTTARGET_SEC    [!//
[!IF "EcuMGeneral/EcuMUseBoottargetSec = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

#if (defined ECUM_VERSION_INFO_API)
#error ECUM_VERSION_INFO_API already defined
#endif
/** \brief Provide EcuM_GetVersionInfo() API !*/
#define ECUM_VERSION_INFO_API      [!//
[!IF "EcuMGeneral/EcuMVersionInfoApi = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

#if (defined ECUM_PROVIDE_SHUTDOWN_HOOK)
#error ECUM_PROVIDE_SHUTDOWN_HOOK already defined
#endif
/** \brief Provide minimalistic ShutdownHook() implementation */
#define ECUM_PROVIDE_SHUTDOWN_HOOK [!//
[!IF "EcuMGeneral/EcuMProvideShutdownHook = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

#define ECUM_ECUM_FIXED_SUPPORT    [!//
[!IF "node:exists(EcuMConfiguration/*[1]/EcuMFixedConfiguration) = 'true'"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

/*------------------[DEM/DET error configuration]---------------------------*/

#if (defined ECUM_PROD_ERR_RAM_CHECK_FAILURE)
#error ECUM_PROD_ERR_RAM_CHECK_FAILURE already defined
#endif
/** \brief Switch for DEM to DET reporting Ram Check Failure */
#define ECUM_PROD_ERR_RAM_CHECK_FAILURE                 [!//
[!IF "ReportToDem/EcuMRamChkFailedReportToDem = 'DEM'"!][!//
TS_PROD_ERR_REP_TO_DEM
[!ELSEIF "ReportToDem/EcuMRamChkFailedReportToDem = 'DET'"!][!//
TS_PROD_ERR_REP_TO_DET
[!ELSE!][!//
TS_PROD_ERR_DISABLE
[!ENDIF!][!//

#if (defined ECUM_PROD_ERR_CFG_DATA_INCONSISTENT)
#error ECUM_PROD_ERR_CFG_DATA_INCONSISTENT already defined
#endif
/** \brief Switch for DEM to DET reporting Configuration Data Inconsistent
 **
 ** This preprocessor macro belongs to a feature which is not supported by the
 ** current implementation. It is available for completeness reasons only. */
#define ECUM_PROD_ERR_CFG_DATA_INCONSISTENT             [!//
[!IF "ReportToDem/EcuMCfgDataInconsistentReportToDem = 'DEM'"!][!//
TS_PROD_ERR_REP_TO_DEM
[!ELSEIF "ReportToDem/EcuMCfgDataInconsistentReportToDem = 'DET'"!][!//
TS_PROD_ERR_REP_TO_DET
[!ELSE!][!//
TS_PROD_ERR_DISABLE
[!ENDIF!][!//

[!IF "ReportToDem/EcuMRamChkFailedReportToDem = 'DET'"!][!//
/** \brief DET error Id for Ram check failure */
#define ECUM_E_DEMTODET_RAM_CHECK_FAILED                [!//
[!"ReportToDem/EcuMRamChkFailedReportToDemDetErrorId"!]U

[!ENDIF!][!//
[!//
[!IF "ReportToDem/EcuMCfgDataInconsistentReportToDem = 'DET'"!][!//
/** \brief DET error Id for Inconsistent Configuration Data */
#define ECUM_E_DEMTODET_CONFIGURATION_DATA_INCONSISTENT [!//
[!"ReportToDem/EcuMCfgDataInconsistentReportToDemDetErrorId"!]U
[!ENDIF!][!//

#if (defined ECUM_PROD_ERR_ALL_RUN_REQUESTS_KILLED)
#error ECUM_PROD_ERR_ALL_RUN_REQUESTS_KILLED already defined
#endif
/** \brief Switch for DEM reporting of all run requests killed */
#define ECUM_PROD_ERR_ALL_RUN_REQUESTS_KILLED [!//
[!IF "node:exists(as:modconf('EcuM')[1]/EcuMConfiguration/*[1]/EcuMCommonConfiguration/EcuMDemEventParameterRefs/ECUM_E_ALL_RUN_REQUESTS_KILLED)"!][!//
TS_PROD_ERR_REP_TO_DEM
[!ELSE!][!//
TS_PROD_ERR_DISABLE
[!ENDIF!][!//

/*------------------[User defined initialization switches]------------------*/
[!SELECT "EcuMConfiguration/*[1]/EcuMCommonConfiguration"!][!//

/** \brief Switch for usage of EcuM_Al_DriverInitZero */
#define ECUM_INITLIST_ZERO      [!//
[!IF "node:exists(EcuMDriverInitListZero)"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

/** \brief Switch for usage of EcuM_Al_DriverInitOne */
#define ECUM_INITLIST_ONE       [!//
[!IF "node:exists(EcuMDriverInitListOne)"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

/** \brief Switch for usage of EcuM_Al_DriverRestart */
#define ECUM_INITLIST_RESTART   [!//
[!IF "node:exists(EcuMDriverRestartList)"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

/*------------------[EcuM Flex User Config]--------------------------------------*/

/* Symbolic names which can be used for all function argument of type
 * EcuM_UserType */
[!LOOP "../EcuMFlexConfiguration/EcuMFlexUserConfig/*"!][!//
#if (defined EcuMConf_[!"name(..)"!]_[!"name(.)"!])
#error EcuMConf_[!"name(..)"!]_[!"name(.)"!] already defined
#endif
/** \brief Identifier for the EcuM user "[!"name(.)"!]" */
#define EcuMConf_[!"name(..)"!]_[!"name(.)"!]   [!"EcuMFlexUser"!]U

#if (defined ECUM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined EcuM_[!"name(.)"!])
#error EcuM_[!"name(.)"!] already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define EcuM_[!"name(.)"!]   [!"EcuMFlexUser"!]U
#endif /* ECUM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

[!ENDLOOP!][!//

#define ECUM_FIXED_NUM_FIXED_USERS [!"num:i(count(../EcuMFixedConfiguration/EcuMFixedUserConfig/*))"!]U
/*------------------[Wakeup Sources]----------------------------------------*/

#if (defined ECUM_COMM_CHANNELS_NUMBER)
#error ECUM_COMM_CHANNELS_NUMBER already defined
#endif
/** \brief Number of individual chanels configured in EcuM */ 
#define ECUM_COMM_CHANNELS_NUMBER [!"num:i(count(node:refs(as:modconf('EcuM')[1]/EcuMConfiguration/*[1]/EcuMCommonConfiguration/EcuMWakeupSource/*/EcuMComMChannelRef)))"!]U

#if (defined ECUM_COMM_PNC_NUMBER)
#error ECUM_COMM_PNC_NUMBER already defined
#endif
/** \brief Number of individual Pncs configured in EcuM */ 
#define ECUM_COMM_PNC_NUMBER [!"num:i(count(node:refs(as:modconf('EcuM')[1]/EcuMConfiguration/*[1]/EcuMCommonConfiguration/EcuMWakeupSource/*/EcuMComMPNCRef)))"!]U

#if (defined ECUM_COMM_NUM_CHANNELS_BYTES)
#error ECUM_COMM_NUM_CHANNELS_BYTES already defined
#endif
/** \brief Number of bytes needed by ComM channels (each bit represents an individual ComM channel) */ 
[!IF "num:i(count(node:refs(as:modconf('EcuM')[1]/EcuMConfiguration/*[1]/EcuMCommonConfiguration/EcuMWakeupSource/*/EcuMComMChannelRef))) > 0"!][!//
#define ECUM_COMM_NUM_CHANNELS_BYTES (((ECUM_COMM_CHANNELS_NUMBER - 1U) / 8U) + 1U)
[!ELSE!][!//
#define ECUM_COMM_NUM_CHANNELS_BYTES 0U
[!ENDIF!]

#if (defined ECUM_COMM_NUM_PNCS_BYTES)
#error ECUM_COMM_NUM_PNCS_BYTES already defined
#endif
/** \brief Number of bytes needed by ComM Pncs (each bit represents an individual ComM PNC) */ 
[!IF "num:i(count(node:refs(as:modconf('EcuM')[1]/EcuMConfiguration/*[1]/EcuMCommonConfiguration/EcuMWakeupSource/*/EcuMComMPNCRef))) > 0"!][!//
#define ECUM_COMM_NUM_PNCS_BYTES (((ECUM_COMM_PNC_NUMBER - 1U) / 8U) + 1U)
[!ELSE!][!//
#define ECUM_COMM_NUM_PNCS_BYTES 0U
[!ENDIF!]


#if (defined ECUM_CROSS_CORE_COMM_WAKEUP)
#error ECUM_CROSS_CORE_COMM_WAKEUP already defined
#endif
/** \brief Enables ComM, EcuM configuration in RTE*/ 
#define ECUM_CROSS_CORE_COMM_WAKEUP [!//
[!IF "as:modconf('EcuM')[1]/EcuMGeneral/EcuMCrossCoreComMWakeup = 'true'"!]TRUE[!ELSE!]FALSE[!ENDIF!]

[!LOOP "EcuMWakeupSource/*"!][!//
#if (defined EcuMConf_[!"name(..)"!]_[!"name(.)"!])
#error EcuMConf_[!"name(..)"!]_[!"name(.)"!] already defined
#endif
/** \brief Identifier for wakeup source [!"name(.)"!] */
#define EcuMConf_[!"name(..)"!]_[!"name(.)"!]   [!"node:value(./EcuMWakeupSourceId)"!]U

#if (defined ECUM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined EcuM_[!"name(.)"!])
#error EcuM_[!"name(.)"!] already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define EcuM_[!"name(.)"!]   [!"bit:bitset(0, EcuMWakeupSourceId)"!]U
#endif /* ECUM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

[!ENDLOOP!][!//
[!//
/** \brief Number of wakeup sources */
#define ECUM_WKSCONFIGNUM          [!//
[!"num:i(count(EcuMWakeupSource/*))"!]U

/** \brief Maximum value of Wakeup Source ID */
#define ECUM_WKS_ID_MAXVAL          [!//
[!"num:i(num:max(EcuMWakeupSource/*/EcuMWakeupSourceId))"!]U

/** \brief Bit mask of all wakeup sources */
#define ECUM_WKSMASKALL (EcuM_WakeupSourceType)(\
[!LOOP "EcuMWakeupSource/*"!][!//
   ((EcuM_WakeupSourceType)1U << EcuMConf_[!"name(..)"!]_[!"name(.)"!]) | \
[!ENDLOOP!][!//
   0U)

/** \brief Bit mask of wakeup sources with no validation All standard WKS
 * require no validation */
#define ECUM_WKSMASKNOVAL (EcuM_WakeupSourceType)(\
[!LOOP "EcuMWakeupSource/*[not(node:exists(EcuMValidationTimeout))]"!][!//
   ((EcuM_WakeupSourceType)1U << EcuMConf_[!"name(..)"!]_[!"name(.)"!]) | \
[!ENDLOOP!][!//
   0U)

/** \brief Bit mask of wakeup sources with ComM channel */
#define ECUM_WKSMASKCOMMCH (EcuM_WakeupSourceType)(\
[!LOOP "EcuMWakeupSource/*[node:refexists(EcuMComMChannelRef)]"!][!//
   ((EcuM_WakeupSourceType)1U << EcuMConf_[!"name(..)"!]_[!"name(.)"!]) | \
[!ENDLOOP!][!//
   0U)

/** \brief Switch to enable handling of wakeup sources with ComM channel */
#define ECUM_WKS_COMMCH_ENABLED    [!//
[!IF "count(node:refs(EcuMWakeupSource/*/EcuMComMChannelRef)) > 0"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

/** \brief Bit mask of wakeup sources with ComM PNCs */
#define ECUM_WKSMASKCOMMPNC (EcuM_WakeupSourceType)(\
[!LOOP "EcuMWakeupSource/*[node:refexists(EcuMComMPNCRef)]"!][!//
   ((EcuM_WakeupSourceType)1U << EcuMConf_[!"name(..)"!]_[!"name(.)"!]) | \
[!ENDLOOP!][!//
   0U)

/** \brief Switch to enable handling of wakeup sources with ComM PNC */
#define ECUM_WKS_COMMPNC_ENABLED    [!//
[!IF "count(node:refs(EcuMWakeupSource/*/EcuMComMPNCRef)) > 0"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

/*------------------[Sleep modes]-------------------------------------------*/
/* !LINKSTO EcuM2957,1 */
/** \brief number of sleep modes */
#define ECUM_SLEEPMODECONFIGNUM    [!//
[!"num:i(count(EcuMSleepMode/*))"!]U

[!LOOP "node:order(EcuMSleepMode/*,'node:value(EcuMSleepModeId)')"!][!//
#if (defined EcuMConf_[!"name(..)"!]_[!"name(.)"!])
#error EcuMConf_[!"name(..)"!]_[!"name(.)"!] already defined
#endif

/** \brief Identifier for sleep mode [!"name(.)"!] */
#define EcuMConf_[!"name(..)"!]_[!"name(.)"!]   [!"num:inttohex(EcuMSleepModeId)"!]U

#if (defined ECUM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined EcuM_[!"name(.)"!])
#error EcuM_[!"name(.)"!] already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define EcuM_[!"name(.)"!]   [!"num:inttohex(EcuMSleepModeId)"!]U
#endif /* ECUM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/** \brief Wakeup event mask of sleep mode [!"name(.)"!] */
#define ECUM_[!"name(.)"!]_WKUP_MASK (\
[!LOOP "EcuMWakeupSourceMask/*"!][!//
(1U << EcuMConf_[!"name(as:ref(.)/..)"!]_[!"name(as:ref(.))"!]) | \
[!ENDLOOP!][!//
0U)
[!ENDLOOP!][!//


[!ENDSELECT!]
/*------------------[Mcu Mode]----------------------------------------------*/
[!SELECT "EcuMConfiguration/*[1]/EcuMFlexConfiguration"!][!//
[!//
[!//An xdm check ensures that the reference is valid for EcuMNormalMcuModeRef.
#if (defined [!//
McuConf_[!"node:name(node:dtos(as:ref(./EcuMNormalMcuModeRef)))"!]_[!"as:name(as:ref(EcuMNormalMcuModeRef))"!])
#define ECUM_NORMALMCUMODE   [!//
McuConf_[!"node:name(node:dtos(as:ref(./EcuMNormalMcuModeRef)))"!]_[!"as:name(as:ref(EcuMNormalMcuModeRef))"!]  [!//
/* [!"as:ref(EcuMNormalMcuModeRef)/McuMode"!]U */
#else
#define ECUM_NORMALMCUMODE   [!//
[!"as:name(as:ref(EcuMNormalMcuModeRef))"!]   [!//
/* [!"as:ref(EcuMNormalMcuModeRef)/McuMode"!]U */
#endif

/*------------------[Reset Modes]----------------------------------------------*/
/* !LINKSTO EcuM4005,1 */
[!LOOP "EcuMResetMode/*"!][!//
#if (defined EcuMConf_[!"name(..)"!]_[!"name(.)"!])
#error EcuMConf_[!"name(..)"!]_[!"name(.)"!] already defined
#endif
/** \brief Identifier for reset modes [!"name(.)"!] */
#define EcuMConf_[!"name(..)"!]_[!"name(.)"!]   [!"EcuMResetModeId"!]U

#if (defined ECUM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined EcuM_[!"name(.)"!])
#error EcuM_[!"name(.)"!] already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define EcuM_[!"name(.)"!]   [!"EcuMResetModeId"!]U
#endif /* ECUM_PROVIDE_LEGACY_SYMBOLIC_NAMES */
[!ENDLOOP!][!//

/*------------------[Shutdown Causes]----------------------------------------------*/
/* !LINKSTO EcuM4007,1 */
[!LOOP "EcuMShutdownCause/*"!][!//
#if (defined EcuMConf_[!"name(..)"!]_[!"name(.)"!])
#error EcuMConf_[!"name(..)"!]_[!"name(.)"!] already defined
#endif
/** \brief Identifier for reset modes [!"name(.)"!] */
#define EcuMConf_[!"name(..)"!]_[!"name(.)"!]   [!"EcuMShutdownCauseId"!]U

#if (defined ECUM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
[!// The following macros are also generated by the Rte
#if (defined EcuM_[!"name(.)"!])
#error EcuM_[!"name(.)"!] already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix
 ** only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define EcuM_[!"name(.)"!]   [!"EcuMShutdownCauseId"!]U
#endif /* ECUM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

[!ENDLOOP!][!//
/** \brief Number of shutdown causes */
#define ECUM_SHUTDOWNCAUSECONFIGNUM          [!//
[!"num:i(count(EcuMShutdownCause/*))"!]U

[!ENDSELECT!]




/*------------------[Defensive programming]---------------------------------*/
[!SELECT "EcuMDefensiveProgramming"!][!//

#if (defined ECUM_DEFENSIVE_PROGRAMMING_ENABLED)
#error ECUM_DEFENSIVE_PROGRAMMING_ENABLED is already defined
#endif
/** \brief Defensive programming usage
 **
 ** En- or disables the usage of the defensive programming */
#define ECUM_DEFENSIVE_PROGRAMMING_ENABLED   [!//
[!IF "(../EcuMGeneral/EcuMDevErrorDetect  = 'true') and (EcuMDefProgEnabled = 'true')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

#if (defined ECUM_PRECONDITION_ASSERT_ENABLED)
#error ECUM_PRECONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Precondition assertion usage
 **
 ** En- or disables the usage of precondition assertion checks */
#define ECUM_PRECONDITION_ASSERT_ENABLED     [!//
[!IF "(../EcuMGeneral/EcuMDevErrorDetect  = 'true') and (EcuMDefProgEnabled = 'true') and (EcuMPrecondAssertEnabled = 'true')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

#if (defined ECUM_POSTCONDITION_ASSERT_ENABLED)
#error ECUM_POSTCONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Postcondition assertion usage
 **
 ** En- or disables the usage of postcondition assertion checks */
#define ECUM_POSTCONDITION_ASSERT_ENABLED    [!//
[!IF "(../EcuMGeneral/EcuMDevErrorDetect  = 'true') and (EcuMDefProgEnabled = 'true') and (EcuMPostcondAssertEnabled = 'true')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

#if (defined ECUM_UNREACHABLE_CODE_ASSERT_ENABLED)
#error ECUM_UNREACHABLE_CODE_ASSERT_ENABLED is already defined
#endif
/** \brief Unreachable code assertion usage
 **
 ** En- or disables the usage of unreachable code assertion checks */
#define ECUM_UNREACHABLE_CODE_ASSERT_ENABLED [!//
[!IF "(../EcuMGeneral/EcuMDevErrorDetect  = 'true') and (EcuMDefProgEnabled = 'true') and (EcuMUnreachAssertEnabled = 'true')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

#if (defined ECUM_INVARIANT_ASSERT_ENABLED)
#error ECUM_INVARIANT_ASSERT_ENABLED is already defined
#endif
/** \brief Invariant assertion usage
 **
 ** En- or disables the usage of invariant assertion checks */
#define ECUM_INVARIANT_ASSERT_ENABLED        [!//
[!IF "(../EcuMGeneral/EcuMDevErrorDetect  = 'true') and (EcuMDefProgEnabled = 'true') and (EcuMInvariantAssertEnabled = 'true')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

#if (defined ECUM_STATIC_ASSERT_ENABLED)
#error ECUM_STATIC_ASSERT_ENABLED is already defined
#endif
/** \brief Static assertion usage
 **
 ** En- or disables the usage of static assertion checks */
#define ECUM_STATIC_ASSERT_ENABLED           [!//
[!IF "(../EcuMGeneral/EcuMDevErrorDetect  = 'true') and (EcuMDefProgEnabled = 'true') and (EcuMStaticAssertEnabled = 'true')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]

[!ENDSELECT!][!//


/*==================[type definitions]======================================*/


/*==================[external function declarations]========================*/
[!SELECT "EcuMConfiguration/*[1]"!][!//
#define ECUM_START_SEC_CODE
#include <EcuM_MemMap.h>

[!IF "node:exists(EcuMCommonConfiguration/EcuMDriverInitListOne)"!][!//
/** \brief Callout for driver initialization sequence one for EcuM.
 **
 ** This is the configuration specific callout called from
 ** EcuM_AL_DriverInitOne().  This function contains the Initialization
 ** of Modules configured in EcuMDriverInitListOne
 **
 ** \param[in] ConfigPtr Pointer to the EcuM post-build configuration which
 ** contains pointers to all other BSW module post-build configurations. */
extern FUNC(void, ECUM_APPL_CODE) EcuM_DriverInitListOne
(
  P2CONST(EcuM_ConfigType, AUTOMATIC, ECUM_CONST) ConfigPtr
);
[!ENDIF!][!//

[!IF "node:exists(EcuMCommonConfiguration/EcuMDriverRestartList)"!][!//
/** \brief Callout for restarting drivers for EcuM.
 **
 ** This is the configuration specific callout called from
 ** EcuM_AL_DriverRestart().  This function contains the Initialization
 ** of Modules configured in EcuMDriverRestartList
 **
 ** \param[in] ConfigPtr Pointer to the EcuM post-build configuration which
 ** contains pointers to all other BSW module post-build configurations. */
extern FUNC(void, ECUM_APPL_CODE) EcuM_DriverRestartList
(
  P2CONST(EcuM_ConfigType, AUTOMATIC, ECUM_CONST) ConfigPtr
);
[!ENDIF!][!//

[!ENDSELECT!][!//

[!IF "EcuMGeneral/EcuMProvideShutdownHook = 'true'"!][!//
/** \brief Hook routine called by Os during shutdown.
 **
 ** This hook routine is called by the operating system when the
 ** OS service ShutdownOS has been called. This routine is called
 ** during the operating system shut down.
 **
 ** If enabled by configuration, the EcuM provides a minimalistic
 ** implementation of the ShutdownHook() callback function for the Os.
 **
 ** \param[in] errorID Implementation dependent error value */

extern void ShutdownHook(StatusType errorID);
[!ENDIF!][!//

#define ECUM_STOP_SEC_CODE
#include <EcuM_MemMap.h>

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef ECUM_CFG_H */
/*==================[end of file]===========================================*/

