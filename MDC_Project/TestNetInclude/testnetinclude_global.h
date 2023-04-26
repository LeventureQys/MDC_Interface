#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(TESTNETINCLUDE_LIB)
#  define TESTNETINCLUDE_EXPORT Q_DECL_EXPORT
# else
#  define TESTNETINCLUDE_EXPORT Q_DECL_IMPORT
# endif
#else
# define TESTNETINCLUDE_EXPORT
#endif
