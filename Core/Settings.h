#pragma once


namespace core
{
    
    class Settings
    {
    public:
        Settings();
        ~Settings();

        QSettings *operator->() const;

        Settings& setDefaultValue( const QString& key, const QVariant& value );

    private:
        QScopedPointer< QSettings > _storage;
    };

}