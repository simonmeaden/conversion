#ifndef LENGTHPLUGINWRAPPER_H
#define LENGTHPLUGINWRAPPER_H

#include <QObject>
#include <QStringList>
#include <QtPlugin>

#include "conversion_global.h"
#include "conversioninterface.h"

#if defined(DISABLE_CONVERSION_NAMESPACE)
QT_BEGIN_NAMESPACE_CONVERSION
#else
namespace Conversion {
#endif

class LengthPluginWrapper : public QObject, public IPluginInterface {
        Q_OBJECT
    public:
        LengthPluginWrapper();

        virtual QStringList importer() const;

    protected:
        QStringList mValues;
};

QT_END_NAMESPACE_CONVERSION

#endif // LENGTHPLUGINWRAPPER_H
