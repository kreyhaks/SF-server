cmake_minimum_required( VERSION 3.0.2 )

#project name
project( Core )

#find packages
find_package( Qt5Core       REQUIRED )
find_package( Qt5Network    REQUIRED )

#settings
set( CMAKE_INCLUDE_CURRENT_DIR ON )
set( CMAKE_AUTOMOC OFF )

include_directories( "${ROOT_DIR}" )
include_directories( "${CMAKE_CURRENT_LIST_DIR}" )
include_directories( "${QT5_PATH}/include" )

add_definitions(
    -D_CRT_SECURE_NO_DEPRECATE
)

#build file list
file( GLOB_RECURSE H_FILES "${CMAKE_CURRENT_LIST_DIR}/*.h" )
file( GLOB_RECURSE CPP_FILES "${CMAKE_CURRENT_LIST_DIR}/*.cpp" )

set( USER_FILES ${H_FILES} ${CPP_FILES} )

qt5_wrap_cpp( MOC_LIST ${H_FILES} )
set( GENERATED_FILES ${MOC_LIST} )

set( ALL_FILES ${USER_FILES} ${GENERATED_FILES} )

apply_source_groups( USER_FILES ${CMAKE_CURRENT_LIST_DIR} "Sources" )
apply_source_groups( GENERATED_FILES ${CMAKE_CURRENT_BINARY_DIR} "Generated" )

#compiling
add_library( ${PROJECT_NAME} SHARED ${ALL_FILES} )

#linking
target_link_libraries( ${PROJECT_NAME} Qt5::Core )
target_link_libraries( ${PROJECT_NAME} Qt5::Network )

target_link_libraries( ${PROJECT_NAME} Network )
target_link_libraries( ${PROJECT_NAME} Types )
#target_link_libraries( ${PROJECT_NAME} Utils )

#cotire
set_target_properties( ${PROJECT_NAME} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "Common.h" )
cotire( ${PROJECT_NAME} )
