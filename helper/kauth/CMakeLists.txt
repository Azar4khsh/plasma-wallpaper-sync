
set(PLASMALOGIN_CONFIG_FILE "${CMAKE_INSTALL_FULL_SYSCONFDIR}/plasmalogin.conf" CACHE PATH "Path of the plasma-login config file")

configure_file(config.h.in config.h IMMEDIATE @ONLY)

add_library(settings STATIC
    config.h
)

set_property(TARGET settings PROPERTY POSITION_INDEPENDENT_CODE ON)

target_link_libraries(settings)

add_library(kauth_core STATIC plasmaloginauthhelper.cpp plasmaloginauthhelper.h)
target_link_libraries(kauth_core
    settings
    Qt6::Core
    Qt6::DBus
    KF6::ConfigCore
    KF6::AuthCore
    KF6::I18n
)

add_executable(wallpapersync_kauthhelper)

target_link_libraries(wallpapersync_kauthhelper PRIVATE
    kauth_core
)

install(TARGETS wallpapersync_kauthhelper DESTINATION ${KAUTH_HELPER_INSTALL_DIR})
kauth_install_helper_files(wallpapersync_kauthhelper luisbocanegra.plasma.wallpapersync root)
kauth_install_actions(luisbocanegra.plasma.wallpapersync luisbocanegra.plasma.wallpapersync.actions)

target_include_directories(kauth_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
