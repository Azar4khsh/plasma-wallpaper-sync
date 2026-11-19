#ifndef WALLPAPERSYNC_H
#define WALLPAPERSYNC_H
#pragma once

#include <KConfigGroup>
#include <KSharedConfig>
#include <QObject>
#include <QQmlParserStatus>
#include <qqmlintegration.h>

class WallpaperSync : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    explicit WallpaperSync(QObject *parent = nullptr);

    Q_INVOKABLE QString setLockScreenWallpaper(const QString &plugin, const QString &configJson);

    Q_INVOKABLE QString setPlasmaLoginWallpaper(const QString &plugin, const QString &configJson);
};

#endif
