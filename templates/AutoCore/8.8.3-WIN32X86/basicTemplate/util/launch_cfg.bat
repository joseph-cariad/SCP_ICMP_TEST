IF "%TARGET%"=="" SET TARGET=WINDOWS
IF "%DERIVATE%"=="" SET DERIVATE=WIN32X86
IF "%TOOLCHAIN%"=="" SET TOOLCHAIN=mgcc62
IF [%TOOLPATH_COMPILER%]==[] SET TOOLPATH_COMPILER=

IF [%TRESOS_BASE%]==[] SET TRESOS_BASE=C:/EB/tresos
IF [%PLUGINS_BASE%]==[] SET PLUGINS_BASE=%TRESOS_BASE%/plugins
