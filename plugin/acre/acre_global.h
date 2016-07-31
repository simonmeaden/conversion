#ifndef ACRE_GLOBAL_H
#define ACRE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ACRE_LIBRARY)
#  define ACRESHARED_EXPORT Q_DECL_EXPORT
#else
#  define ACRESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // ACRE_GLOBAL_H
