#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(MDC_CLIENT_LIB)
#  define MDC_CLIENT_EXPORT Q_DECL_EXPORT
# else
#  define MDC_CLIENT_EXPORT Q_DECL_IMPORT
# endif
#else
# define MDC_CLIENT_EXPORT
#endif
