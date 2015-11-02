cmake_minimum_required( VERSION 3.0.2 )

#project name
project( SF-server )


#find packages
find_package( Qt5Core          REQUIRED )
#find_package( Qt5Network       REQUIRED )
#find_package( Qt5Sql           REQUIRED )
#find_package( Qt5LinguistTools REQUIRED )

#settings
set( CMAKE_INCLUDE_CURRENT_DIR ON )
set( CMAKE_AUTOMOC OFF )

include_directories( "${ROOT_DIR}" )
include_directories( "${ROOT_DIR}/Core" )
include_directories( "${CMAKE_CURRENT_LIST_DIR}" )
include_directories( "${QT5_PATH}/include" )

add_definitions(
    -D_CRT_SECURE_NO_DEPRECATE
)

#build file list
file( GLOB_RECURSE H_FILES "${CMAKE_CURRENT_LIST_DIR}/*.h" )
file( GLOB_RECURSE CPP_FILES "${CMAKE_CURRENT_LIST_DIR}/*.cpp" )

set( USER_FILES ${H_FILES} ${CPP_FILES} )

#translations
#SET( OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/bin" )
#SET( LANGUAGE "language_ru" )
#SET( TS_FILE "${ROOT_DIR}/Translations/cmake_${LANGUAGE}.ts")
#for QtCreator remove "/Debug"
#SET( QM_PATH "${OUTPUT_DIR}/Translations" )
#SET_SOURCE_FILES_PROPERTIES(${TS_FILE} PROPERTIES OUTPUT_LOCATION ${QM_PATH})
#qt5_create_translation( QM_FILES ${USER_FILES} ${TS_FILE} )

qt5_wrap_cpp( MOC_LIST ${H_FILES} )
set( GENERATED_FILES ${MOC_LIST} )

set( ALL_FILES ${USER_FILES} ${GENERATED_FILES} ${QM_FILES} )

apply_source_groups( USER_FILES ${CMAKE_CURRENT_LIST_DIR} "Sources" )
apply_source_groups( GENERATED_FILES ${CMAKE_CURRENT_BINARY_DIR} "Generated" )
#apply_source_groups( QM_FILES ${QM_PATH} "Translations" )

#compiling
add_executable( ${PROJECT_NAME} ${ALL_FILES} )

#linking
target_link_libraries( ${PROJECT_NAME} Qt5::Core )
#target_link_libraries( ${PROJECT_NAME} Qt5::Network )
#target_link_libraries( ${PROJECT_NAME} Qt5::Sql )

target_link_libraries( ${PROJECT_NAME} Core )
target_link_libraries( ${PROJECT_NAME} Network )
#target_link_libraries( ${PROJECT_NAME} Types )
#target_link_libraries( ${PROJECT_NAME} Utils )

#cotire
set_target_properties( ${PROJECT_NAME} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT "Common.h" )
cotire( ${PROJECT_NAME} )

#compiler settings
if ( WIN32 )
#    set_target_properties( ${PROJECT_NAME} PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE" )
#    set_target_properties( ${PROJECT_NAME} PROPERTIES COMPILE_DEFINITIONS_DEBUG "_CONSOLE" )
#    set_target_properties( ${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:CONSOLE" )
#    set_target_properties( ${PROJECT_NAME} PROPERTIES COMPILE_DEFINITIONS_RELEASE "_CONSOLE" )
endif( WIN32 )
