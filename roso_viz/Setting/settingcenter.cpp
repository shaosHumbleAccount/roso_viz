#include "settingcenter.h"

SettingCenter* global_settingCenter_instance = NULL;

SettingCenter::SettingCenter(QObject *parent) :
    QObject(parent)
{
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
    if(settingMap.contains(name))
    {
        return settingMap[name];
    }
    else
    {
        return QVariant();
    }
}



void SettingCenter::set_SettingValue(QString name, QVariant value)
{
    settingMap[name] = value;
    emit settingChanged(name,value);
}
