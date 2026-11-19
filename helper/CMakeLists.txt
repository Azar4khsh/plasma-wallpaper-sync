find_package(Qt6 ${QT_MIN_VERSION} REQUIRED COMPONENTS Core DBus)
find_package(KF6Config ${KF6_MIN_VERSION} REQUIRED)
find_package(KF6 ${KF6_MIN_VERSION} REQUIRED COMPONENTS Auth CoreAddons I18n Package)

add_subdirectory(kauth)
add_subdirectory(core)
add_subdirectory(plugin)
add_subdirectory(cli)
