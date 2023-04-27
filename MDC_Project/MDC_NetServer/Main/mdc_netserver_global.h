#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(MDC_NETSERVER_LIB)
#  define MDC_NETSERVER_EXPORT Q_DECL_EXPORT
# else
#  define MDC_NETSERVER_EXPORT Q_DECL_IMPORT
# endif
#else
# define MDC_NETSERVER_EXPORT
#endif
