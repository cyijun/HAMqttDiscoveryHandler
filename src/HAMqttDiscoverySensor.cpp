#include "HAMqttDiscoverySensor.h"

HAMqttDiscoverySensor::HAMqttDiscoverySensor(HAMqttDiscoveryHandler &deviceObj, String stateClass, String deviceNameMin, String deviceClass, String unitOfMeasurement, String valueTemplate)
{
    _platform = deviceObj.getPlatform();
    _deviceName = deviceObj.getDeviceName();
    _deviceManufacturer = deviceObj.getDeviceManufacturer();
    _deviceModel = deviceObj.getDeviceModel();
    _deviceSwVersion = deviceObj.getDeviceSwVersion();
    _deviceId = deviceObj.getDeviceId();
    _stateTopic = deviceObj.getStateTopic();
    _availabilityTopic = deviceObj.getAvailabilityTopic();
}

void HAMqttDiscoverySensor::construct()
{
    _uniqueId = _deviceName + "_" + _deviceNameMin + "_" + _platform;
    _entityName = _deviceName + " " + _deviceNameMin;
    _mqttDiscoveryConfigTopic = "homeassistant/" + _deviceType + "/" + _deviceName + "/" + _deviceNameMin + "/config";

    DynamicJsonDocument doc(1024);
    doc[_AVAILABILITY][0][_TOPIC] = _availabilityTopic;
    JsonObject device = doc.createNestedObject(_DEVICE);
    device[_IDENTIFIERS][0] = _deviceId;
    device[_MANUFACTURER] = _deviceManufacturer;
    device[_MODEL] = _deviceModel;
    device[_NAME] = _deviceName;
    device[_SW_VERSION] = _deviceSwVersion;
    doc[_JSON_ATTRIBUTES_TOPIC] = _stateTopic;
    doc[_NAME] = _entityName;
    doc[_UNIQUE_ID] = _uniqueId;
    doc[_DEVICE_CLASS] = _deviceClass;
    doc[_STATE_CLASS] = _stateClass;
    doc[_STATE_TOPIC] = _stateTopic;
    if (!_unitOfMeasurement.isEmpty())
    {
        doc[_UNIT_OF_MEASUREMENT] = _unitOfMeasurement;
    }
    doc[_VALUE_TEMPLATE] = _valueTemplate;

    serializeJson(doc, _mqttDiscoveryMesg);
}

//********* Getters *********

String HAMqttDiscoverySensor::getMqttDiscoveryConfigTopic()
{
    return _mqttDiscoveryConfigTopic;
}

String HAMqttDiscoverySensor::getMqttDiscoveryMesg()
{
    String mqttDiscoveryMesg = _mqttDiscoveryMesg;
    _mqttDiscoveryMesg.clear();
    return mqttDiscoveryMesg;
}

//********* Setters *********

void HAMqttDiscoverySensor::setDeviceClass(String deviceClass)
{
    _deviceClass = deviceClass;
}

void HAMqttDiscoverySensor::setStateClass(String stateClass)
{
    _stateClass = stateClass;
}

void HAMqttDiscoverySensor::setUnitOfMeasurement(String unitOfMeasurement)
{
    _unitOfMeasurement = unitOfMeasurement;
}

void HAMqttDiscoverySensor::setValueTemplate(String valueTemplate)
{
    _valueTemplate = valueTemplate;
}

void HAMqttDiscoverySensor::setDeviceNameMin(String deviceNameMin)
{
    _deviceNameMin = deviceNameMin;
}