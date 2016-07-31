#include "lengthpluginwrapper.h"

#include "mil.h"
#include "thou.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

LengthPluginWrapper::LengthPluginWrapper() {

    mValues.append( ( new Mil() )->name() );
    mValues.append( ( new Thou() )->name() );

}

QStringList LengthPluginWrapper::importer() const {

    return mValues;

}

QT_END_NAMESPACE_CONVERSION
