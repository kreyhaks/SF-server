cmake_minimum_required( VERSION 3.0.2 )

project( SF-server )

set( ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}" )
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${ROOT_DIR}/cmake/" )
set( CONFIG_PATH "${ROOT_DIR}/config.in" )
set( CONFIG_TEMPLATE_PATH "${ROOT_DIR}/cmake/templates/config.in" )

set_property( GLOBAL PROPERTY USE_FOLDERS ON )
set( CMAKE_CXX_STANDARD 11 )

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

#include section
include( custom-tools )
include( cotire )

#set build path
foreach( OUTPUT_CONFIG ${CMAKE_CONFIGURATION_TYPES} )
    string( TOUPPER ${OUTPUT_CONFIG} OUTPUT_CONFIG )
    set_target_properties( ${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_${OUTPUT_CONFIG} ${OUTPUT_DIR} )
endforeach( OUTPUT_CONFIG CMAKE_CONFIGURATION_TYPES )
SET( EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/bin )
SET( LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/bin )

#load config
load_config( ${CONFIG_PATH} ${CONFIG_TEMPLATE_PATH} )

#message( "Qt found at: \"${QT5_PATH}\"" )
set( CMAKE_PREFIX_PATH ${QT5_PATH} )

add_subdirectory( Common )
add_subdirectory( SF-server )
add_subdirectory( Core )
add_subdirectory( Types )
#add_subdirectory( Utils )
add_subdirectory( Network )
#add_subdirectory( WebProxy )
