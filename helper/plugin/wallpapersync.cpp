#include "wallpapersync.h"
#include "setwallpaper.h"

WallpaperSync::WallpaperSync(QObject *parent)
    : QObject(parent)
{
}

QString WallpaperSync::setLockScreenWallpaper(const QString &plugin, const QString &configJson)
{
    QString error;
    CoreLogic::setLockScreenWallpaper(plugin, configJson, error);
    return error;
}

QString WallpaperSync::setPlasmaLoginWallpaper(const QString &plugin, const QString &configJson)
{
    QString error;
    CoreLogic::setPlasmaLoginWallpaper(plugin, configJson, error);
    return error;
}
