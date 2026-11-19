add_executable(plasma-wallpaper-sync-helper main.cpp)
target_link_libraries(plasma-wallpaper-sync-helper PUBLIC
    Qt6::Core
)

target_link_libraries(plasma-wallpaper-sync-helper PRIVATE core_logic)
install(TARGETS plasma-wallpaper-sync-helper DESTINATION ${KDE_INSTALL_BINDIR})
