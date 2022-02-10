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

#include "Arduino.h"
#include <ArduinoJson.h>
#include "HAMqttDiscoveryHandler.h"
//#include "HAJsonKeyAbbr.h"
#include "HAJsonKey.h"

HAMqttDiscoveryHandler::HAMqttDiscoveryHandler(String platform, String serialNo, String deviceManufacturer, String deviceModel, String deviceSwVersion)
{
    _platform = platform;
    _platform.toLowerCase();

    _serialNo = serialNo;
    _serialNo.toLowerCase();

    _deviceManufacturer = deviceManufacturer;

    _deviceModel = deviceModel;

    _deviceSwVersion = deviceSwVersion;

    _deviceName = _serialNo;

    _deviceId = _platform + "_" + _serialNo;

    _cmdTopic = _platform + "/" + _serialNo + "/cmd";
    _ctrlTopic = _platform + "/" + _serialNo + "/ctrl";
    _stateTopic = _platform + "/" + _serialNo + "/attr";
    _availabilityTopic = _platform + "/" + _serialNo + "/state";
}

void HAMqttDiscoveryHandler::generate()
{
    _uniqueId = _serialNo + "_" + _deviceNameMin + "_" + _platform;
    _entityName = _serialNo + " " + _deviceNameMin;
    _mqttDiscoveryConfigTopic = "homeassistant/" + _deviceType + "/" + _serialNo + "/" + _deviceNameMin + "/config";

    constructMqttDiscoveryMesg();
}

void HAMqttDiscoveryHandler::constructMqttDiscoveryMesg()
{
    DynamicJsonDocument doc(1024);

    doc[AVAILABILITY][0][TOPIC] = _availabilityTopic;

    JsonObject device = doc.createNestedObject(DEVICE);
    device[IDENTIFIERS][0] = _deviceId;
    device[MANUFACTURER] = _deviceManufacturer;
    device[MODEL] = _deviceModel;
    device[NAME] = _deviceName;
    device[SW_VERSION] = _deviceSwVersion;

    doc[JSON_ATTRIBUTES_TOPIC] = _stateTopic;
    doc[NAME] = _entityName;

    doc[UNIQUE_ID] = _uniqueId;

    if (_deviceType.equals("sensor"))
    {
        doc[DEVICE_CLASS] = _deviceClass; //"temperature"
        doc[STATE_CLASS] = _stateClass;   //"measurement"
        doc[STATE_TOPIC] = _stateTopic;
        if (!_unitOfMeasurement.equals("null"))
        {
            doc[UNIT_OF_MEASUREMENT] = _unitOfMeasurement; //"°C"
        }
        doc[VALUE_TEMPLATE] = _valueTemplate; //"{{ value_json.temperature }}""
    }

    if (_deviceType.equals("fan"))
    {
    }

    _mqttDiscoveryMesg.clear();

    serializeJson(doc, _mqttDiscoveryMesg);
}

String HAMqttDiscoveryHandler::deviceTypeToStr(DeviceType type)
{
    switch (type)
    {
    case DeviceType::ALARM_CONTROL_PANEL:
        return "alarm_control_panel";
    case DeviceType::BINARY_SENSOR:
        return "binary_sensor";
    case DeviceType::CAMERA:
        return "camera";
    case DeviceType::COVER:
        return "cover";
    case DeviceType::FAN:
        return "fan";
    case DeviceType::LIGHT:
        return "light";
    case DeviceType::LOCK:
        return "lock";
    case DeviceType::SENSOR:
        return "sensor";
    case DeviceType::SWITCH:
        return "switch";
    case DeviceType::CLIMATE:
        return "climate";
    case DeviceType::VACUUM:
        return "vacuum";
    default:
        return "[Unknown DeviceType]";
    }
}

//********* Setters *********

void HAMqttDiscoveryHandler::setDeviceClass(String deviceClass)
{
    _deviceClass = deviceClass;
}

void HAMqttDiscoveryHandler::setStateClass(String stateClass)
{
    _stateClass = stateClass;
}

void HAMqttDiscoveryHandler::setUnitOfMeasurement(String unitOfMeasurement)
{
    _unitOfMeasurement = unitOfMeasurement;
}

void HAMqttDiscoveryHandler::setValueTemplate(String valueTemplate)
{
    _valueTemplate = valueTemplate;
}

void HAMqttDiscoveryHandler::setDeviceNameMin(String deviceNameMin)
{
    _deviceNameMin = deviceNameMin;
}

void HAMqttDiscoveryHandler::setDeviceType(DeviceType type)
{
    _deviceType = deviceTypeToStr(type);
}

//********* Getters *********

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

String HAMqttDiscoveryHandler::getMqttDiscoveryConfigTopic()
{
    return _mqttDiscoveryConfigTopic;
}

String HAMqttDiscoveryHandler::getMqttDiscoveryMesg()
{
    return _mqttDiscoveryMesg;
}