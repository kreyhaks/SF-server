#pragma once


namespace
{
    
    template< typename T >
    struct MetaTypeRegistrator
    {
        MetaTypeRegistrator()
        {
            //const auto type = typeid( T ).name();
            //qDebug() << QString( "qRegisterMetaType< %1 >();" ).arg( type );
            qRegisterMetaType< T >();
        }

        static MetaTypeRegistrator _inst;
    };

}


#define RegisterMetaType( TYPE )                                \
namespace {                                                     \
    template<>MetaTypeRegistrator<TYPE> MetaTypeRegistrator<TYPE>::_inst; \
}
