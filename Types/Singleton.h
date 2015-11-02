#pragma once


template < typename T, typename R = T >
class Singleton
{
public:
    static T& instance()
    {
        static R inst;
        return inst;
    }

protected:
    Singleton(){}
    virtual ~Singleton(){}

private:
    Singleton( const Singleton& ) = delete;
    Singleton& operator=( const Singleton& ) = delete;
};



template < typename T, typename R = T >
class LazySingleton
{
public:
    static QSharedPointer< T > instance()
    {
        Q_ASSERT( !_inst.isNull() );
        return _inst;
    }

    template<typename ...Args>
    static void createSingleton( Args &&...args )
    {
        QMutexLocker lock( &_locker );
        _inst = QSharedPointer< R >::create( std::forward<Args>( args )... ).template staticCast< T >();
    }

    static void releaseSingleton()
    {
        QMutexLocker lock( &_locker );
        _inst.clear();
    }

protected:
    LazySingleton(){}
    virtual ~LazySingleton(){}

private:
    LazySingleton( const LazySingleton& ){}
    LazySingleton& operator=( const LazySingleton& ){ return *this; }

    static QSharedPointer< R > _inst;
    static QMutex _locker;
};

template <typename T, typename R>
QSharedPointer<R> LazySingleton<T, R>::_inst;

template <typename T, typename R>
QMutex LazySingleton<T, R>::_locker;
