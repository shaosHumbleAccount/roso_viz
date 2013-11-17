#ifndef SETTINGCENTER_H
#define SETTINGCENTER_H

#include <QtCore>

class SettingCenter : public QObject
{
    Q_OBJECT
public:
    static SettingCenter* singleton();

    QVariant getSettingValue(QString name) const;

private:
    explicit SettingCenter(QObject *parent = 0);

signals:
    void settingChanged(QString name, QVariant value);

public slots:
    void set_SettingValue(QString name, QVariant value);

private:
    //QMap<QString,QVariant> settingMap;
    QSettings settings;
};

#endif // SETTINGCENTER_H
