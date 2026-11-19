qt_add_library(core_logic STATIC
    setwallpaper.h
    validation.h
)

set_target_properties(core_logic PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_include_directories(core_logic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(core_logic
    Qt6::Core
    Qt6::DBus
    KF6::ConfigCore
    KF6::AuthCore
    kauth_core
)
