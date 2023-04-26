#pragma once

#include <QtCore/qglobal.h>

# if defined(SOUTH_NETWORKBASE_LIB)
#  define SOUTH_NETWORKBASE_EXPORT Q_DECL_EXPORT
# else
#  define SOUTH_NETWORKBASE_EXPORT Q_DECL_IMPORT
# endif