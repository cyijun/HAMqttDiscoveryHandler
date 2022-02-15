/**
 * @file HAMqttDiscoveryLight.cpp
 * @author Chen Yijun
 * @brief
 * @version 0.1
 * @date 2022-02-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "HAMqttDiscoveryLight.h"

HAMqttDiscoveryLight::HAMqttDiscoveryLight(HAMqttDiscoveryHandler &deviceObj)
{
	_platform = deviceObj.getPlatform();
	_deviceName = deviceObj.getDeviceName();
	_deviceManufacturer = deviceObj.getDeviceManufacturer();
	_deviceModel = deviceObj.getDeviceModel();
	_deviceSwVersion = deviceObj.getDeviceSwVersion();
	_deviceId = deviceObj.getDeviceId();
	_stateTopic = deviceObj.getStateTopic();
	_availabilityTopic = deviceObj.getAvailabilityTopic();
	_feedbackTopic = deviceObj.getFeedbackTopic();
	_ctrlTopic = deviceObj.getCtrlTopic();
	_mqttDiscoveryMesgBase = deviceObj.getMqttDiscoveryMesgBase();
}

void HAMqttDiscoveryLight::construct()
{
	_uniqueId = _deviceName + "_" + _deviceNameMin + "_" + _platform;
	_entityName = _deviceName + " " + _deviceNameMin;
	_mqttDiscoveryConfigTopic = "homeassistant/" + _deviceType + "/" + _deviceName + "/" + _deviceNameMin + "/config";

	DynamicJsonDocument doc(1024);
	deserializeJson(doc, _mqttDiscoveryMesgBase);
	doc[_JSON_ATTRIBUTES_TOPIC] = _feedbackTopic;
	doc[_NAME] = _entityName;
	doc[_UNIQUE_ID] = _uniqueId;

	doc[_COMMAND_TOPIC] = _ctrlTopic;
	if (!_commandOnTemplate.isEmpty())
	{
		doc[_COMMAND_ON_TEMPLATE] = _commandOnTemplate;
		doc[_COMMAND_OFF_TEMPLATE] = _commandOffTemplate;
	}

	if (!_payloadOn.isEmpty())
	{
		doc[_PAYLOAD_ON] = _payloadOn;
		doc[_PAYLOAD_OFF] = _payloadOff;
	}

	if (!_stateTemplate.isEmpty())
	{
		doc[_STATE_TOPIC] = _feedbackTopic;
		doc[_STATE_TEMPLATE] = _stateTemplate;
	}

	serializeJson(doc, _mqttDiscoveryMesg);
}

//********* Getters *********

String HAMqttDiscoveryLight::getMqttDiscoveryConfigTopic()
{
	return _mqttDiscoveryConfigTopic;
}

String HAMqttDiscoveryLight::getMqttDiscoveryMesg()
{
	String mqttDiscoveryMesg = _mqttDiscoveryMesg;
	_mqttDiscoveryMesg.clear();
	return mqttDiscoveryMesg;
}

//********* Setters *********

void HAMqttDiscoveryLight::setDeviceNameMin(String deviceNameMin)
{
	_deviceNameMin = deviceNameMin;
}
void HAMqttDiscoveryLight::setPayloadOn(String payloadOn)
{
	_payloadOn = payloadOn;
}
void HAMqttDiscoveryLight::setPayloadOff(String payloadOff)
{
	_payloadOff = payloadOff;
}
void HAMqttDiscoveryLight::setCommandOnTemplate(String commandOnTemplate)
{
	_commandOnTemplate = commandOnTemplate;
}
void HAMqttDiscoveryLight::setCommandOffTemplate(String commandOffTemplate)
{
	_commandOffTemplate = commandOffTemplate;
}
void HAMqttDiscoveryLight::setStateTemplate(String stateTemplate)
{
	_stateTemplate = stateTemplate;
}