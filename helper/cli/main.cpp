#include "setwallpaper.h"
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("Plasma Wallpaper Sync Helper");
    QCoreApplication::setApplicationVersion("0.1.0");

    QCommandLineParser parser;
    parser.setApplicationDescription("Plasma Wallpaper Sync Helper");
    parser.addHelpOption();
    parser.addVersionOption();

    QCommandLineOption lockScreenOption(QStringList() << "lock", "Set wallpaper for the lock screen.");
    parser.addOption(lockScreenOption);

    QCommandLineOption plasmaloginOption(QStringList() << "login", "Set wallpaper for the login screen.");
    parser.addOption(plasmaloginOption);

    QCommandLineOption pluginOption(QStringList() << "plugin", "The wallpaper plugin to use, by default org.kde.image.", "pluginName", "org.kde.image");
    parser.addOption(pluginOption);

    QCommandLineOption configOption(QStringList() << "config", "The plugin configuration in JSON format", "jsonString");
    parser.addOption(configOption);

    parser.process(app);

    QTextStream tsOut(stdout);
    QTextStream tsErr(stderr);
    QString error;

    const QString plugin = parser.value(pluginOption);
    QString config = parser.value(configOption);

    if (config.isEmpty()) {
        tsErr << "Must give config" << Qt::endl;
        parser.showHelp(1);
    }

    int ret{};
    if (parser.isSet(lockScreenOption)) {
        ret = CoreLogic::setLockScreenWallpaper(plugin, config, error);
    }
    if (parser.isSet(plasmaloginOption)) {
        ret = CoreLogic::setPlasmaLoginWallpaper(plugin, config, error);
    }
    if (ret != 0) {
        if (!error.isEmpty()) {
            tsErr << error << Qt::endl;
        }
        return 1;
    }
    return 0;
}
