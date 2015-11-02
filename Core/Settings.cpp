#include "Common.h"
#include "Settings.h"


namespace core
{

    Settings::Settings()
    {
        const auto configPath = QString( "%1/%2" )
            .arg( QCoreApplication::instance()->applicationDirPath() )
            .arg( CONFIG_NAME );
        _storage.reset( new QSettings( configPath, QSettings::IniFormat ) );
        _storage->sync();
    }

    Settings::~Settings()
    {
        _storage->sync();
    }

    QSettings* Settings::operator->() const
    {
        return _storage.data();
    }

    Settings& Settings::setDefaultValue( const QString& key, const QVariant& value )
    {
        auto currentValue = _storage->value( key );
        if ( !currentValue.isValid() && currentValue != value )
            _storage->setValue( key, value );

        return *this;
    }

}
