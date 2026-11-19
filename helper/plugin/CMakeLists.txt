include(ECMQmlModule)
find_package(Qt6 ${QT_MIN_VERSION} REQUIRED COMPONENTS Qml)

set(wallpapersync_SRCS
    wallpapersync.cpp
    wallpapersync.h
)

add_library(plasma_wallpaper_sync_static STATIC ${wallpapersync_SRCS})
set_property(TARGET plasma_wallpaper_sync_static PROPERTY POSITION_INDEPENDENT_CODE ON)

target_link_libraries(plasma_wallpaper_sync_static PUBLIC Qt6::Qml)
target_link_libraries(plasma_wallpaper_sync_static PRIVATE core_logic)

ecm_add_qml_module(plasma_wallpaper_sync URI "com.github.luisbocanegra.wallpapersync" VERSION 1.0 CLASS_NAME WallpaperSync)

qt_generate_foreign_qml_types(plasma_wallpaper_sync_static plasma_wallpaper_sync)

target_sources(plasma_wallpaper_sync PRIVATE wallpapersyncplugin.cpp)

target_link_libraries(plasma_wallpaper_sync PRIVATE kauth_core plasma_wallpaper_sync_static)

ecm_finalize_qml_module(plasma_wallpaper_sync)
