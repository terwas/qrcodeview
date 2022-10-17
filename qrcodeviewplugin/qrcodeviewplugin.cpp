#include "qrcodeviewplugin.h"
#include "qrcodeview.h"

#include <QtPlugin>

QRcodeViewPlugin::QRcodeViewPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void QRcodeViewPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool QRcodeViewPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *QRcodeViewPlugin::createWidget(QWidget *parent)
{
    return new QRcodeView(parent);
}

QString QRcodeViewPlugin::name() const
{
    return QLatin1String("QRcodeView");
}

QString QRcodeViewPlugin::group() const
{
    return QLatin1String("My Widgets");
}

QIcon QRcodeViewPlugin::icon() const
{
    return QIcon();
}

QString QRcodeViewPlugin::toolTip() const
{
    return QLatin1String("");
}

QString QRcodeViewPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool QRcodeViewPlugin::isContainer() const
{
    return false;
}

QString QRcodeViewPlugin::domXml() const
{
    return QDesignerCustomWidgetInterface::domXml();
}

QString QRcodeViewPlugin::includeFile() const
{
    return QLatin1String("qwebview.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(qrcodeviewplugin, QRcodeViewPlugin)
#endif // QT_VERSION < 0x050000
