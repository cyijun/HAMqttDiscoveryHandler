/**
 * @file HAMqttDiscoveryHandler.cpp
 * @author Chen Yijun
 * @brief
 * @version 0.1
 * @date 2022-02-09
 *
 * GPLv3
 *
 */

#include "HAMqttDiscoveryHandler.h"

HAMqttDiscoveryHandler::HAMqttDiscoveryHandler(){};

HAMqttDiscoveryHandler::HAMqttDiscoveryHandler(String platform, String serialNo, String deviceManufacturer, String deviceModel, String deviceSwVersion)
{
    _platform = platform;
    _platform.toLowerCase();
    _deviceName = serialNo;
    _deviceName.toLowerCase();
    _deviceManufacturer = deviceManufacturer;
    _deviceModel = deviceModel;
    _deviceSwVersion = deviceSwVersion;
    _deviceId = _platform + "_" + _deviceName;
    _cmdTopic = _platform + "/" + _deviceName + "/cmd";
    _ctrlTopic = _platform + "/" + _deviceName + "/ctrl";
    _stateTopic = _platform + "/" + _deviceName + "/attr";
    _availabilityTopic = _platform + "/" + _deviceName + "/state";
}

//********* Getters *********

String HAMqttDiscoveryHandler::getPlatform()
{
    return _platform;
}
String HAMqttDiscoveryHandler::getDeviceName()
{
    return _deviceName;
}
String HAMqttDiscoveryHandler::getDeviceManufacturer()
{
    return _deviceManufacturer;
}
String HAMqttDiscoveryHandler::getDeviceModel()
{
    return _deviceModel;
}
String HAMqttDiscoveryHandler::getDeviceSwVersion()
{
    return _deviceSwVersion;
}

String HAMqttDiscoveryHandler::getDeviceId()
{
    return _deviceId;
}

String HAMqttDiscoveryHandler::getCmdTopic()
{
    return _cmdTopic;
}

String HAMqttDiscoveryHandler::getCtrlTopic()
{
    return _ctrlTopic;
}

String HAMqttDiscoveryHandler::getStateTopic()
{
    return _stateTopic;
}

String HAMqttDiscoveryHandler::getAvailabilityTopic()
{
    return _availabilityTopic;
}
