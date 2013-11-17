#include "settingcenter.h"
#include <QMessageBox>

SettingCenter* global_settingCenter_instance = NULL;

SettingCenter::SettingCenter(QObject *parent) :
    QObject(parent),
    settings("rosoviz.ini",QSettings::IniFormat)
{
    if(!settings.contains("network/port"))
    {
        QMessageBox::warning(NULL, "rosoviz.ini NOT FOUND",
                             "rosoviz.ini cannot be found. Please copy it to the same folder as the executable.");
    }
}

SettingCenter* SettingCenter::singleton()
{
    if(!global_settingCenter_instance)
    {
        global_settingCenter_instance = new SettingCenter();
    }
    return global_settingCenter_instance;
}

QVariant SettingCenter::getSettingValue(QString name) const
{
    if(settings.contains(name))
    {
        return settings.value(name);
    }
    else
    {
        return QVariant();
    }
}



void SettingCenter::set_SettingValue(QString name, QVariant value)
{
    settings.setValue(name, value);
    emit settingChanged(name,value);
}
