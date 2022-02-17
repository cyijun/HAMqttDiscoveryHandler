/**
 * @file HAMqttDiscoverySwitch.cpp
 * @author Chen Yijun
 * @brief
 * @version 0.1
 * @date 2022-02-16
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "HAMqttDiscoverySwitch.h"

HAMqttDiscoverySwitch::HAMqttDiscoverySwitch(HAMqttDiscoveryHandler &deviceObj)
{
	_platform = deviceObj.getPlatform();
	_deviceName = deviceObj.getDeviceName();
	_deviceManufacturer = deviceObj.getDeviceManufacturer();
	_deviceModel = deviceObj.getDeviceModel();
	_deviceSwVersion = deviceObj.getDeviceSwVersion();
	_deviceId = deviceObj.getDeviceId();
	_stateTopic = deviceObj.getStateTopic();
	_availabilityTopic = deviceObj.getAvailabilityTopic();
	_ctrlTopic = deviceObj.getCtrlTopic();
	_mqttDiscoveryMesgBase = deviceObj.getMqttDiscoveryMesgBase();
}

void HAMqttDiscoverySwitch::construct()
{
	_uniqueId = _deviceName + "_" + _deviceNameMin + "_" + _platform;
	_entityName = _deviceName + " " + _deviceNameMin;
	_mqttDiscoveryConfigTopic = "homeassistant/" + _deviceType + "/" + _deviceName + "/" + _deviceNameMin + "/config";

	DynamicJsonDocument doc(1024);
	deserializeJson(doc, _mqttDiscoveryMesgBase);
	doc[_JSON_ATTRIBUTES_TOPIC] = _stateTopic;
	doc[_NAME] = _entityName;
	doc[_UNIQUE_ID] = _uniqueId;

	doc[_COMMAND_TOPIC] = _ctrlTopic;

	if (!_payloadOn.isEmpty())
	{
		doc[_PAYLOAD_ON] = _payloadOn;
		doc[_PAYLOAD_OFF] = _payloadOff;
	}

	if (!_valueTemplate.isEmpty())
	{
		doc[_STATE_TOPIC] = _stateTopic;
		doc[_VALUE_TEMPLATE] = _valueTemplate;
	}

	serializeJson(doc, _mqttDiscoveryMesg);
}

//********* Setters *********

void HAMqttDiscoverySwitch::setDeviceNameMin(String deviceNameMin)
{
	_deviceNameMin = deviceNameMin;
}
void HAMqttDiscoverySwitch::setPayloadOn(String payloadOn)
{
	_payloadOn = payloadOn;
}
void HAMqttDiscoverySwitch::setPayloadOff(String payloadOff)
{
	_payloadOff = payloadOff;
}
void HAMqttDiscoverySwitch::setValueTemplate(String valueTemplate)
{
	_valueTemplate = valueTemplate;
}