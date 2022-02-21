/**
 * @file HAMqttDiscoveryClimate.cpp
 * @author Chen Yijun
 * @brief
 * @version 0.1
 * @date 2022-02-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "HAMqttDiscoveryClimate.h"

HAMqttDiscoveryClimate::HAMqttDiscoveryClimate(HAMqttDiscoveryHandler &deviceObj)
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

void HAMqttDiscoveryClimate::construct()
{
	_uniqueId = _deviceName + "_" + _deviceNameMin + "_" + _platform;
	_entityName = _deviceName + " " + _deviceNameMin;
	_mqttDiscoveryConfigTopic = "homeassistant/" + _deviceType + "/" + _deviceName + "/" + _deviceNameMin + "/config";

	DynamicJsonDocument doc(2048);
	deserializeJson(doc, _mqttDiscoveryMesgBase);
	doc[_JSON_ATTRIBUTES_TOPIC] = _stateTopic;
	doc[_NAME] = _entityName;
	doc[_UNIQUE_ID] = _uniqueId;

	if (!_fanModeCommandTemplate.isEmpty())
	{
		doc[_FAN_MODE_COMMAND_TEMPLATE] = _fanModeCommandTemplate;
		doc[_FAN_MODE_COMMAND_TOPIC] = _ctrlTopic;
	}
	if (!_modeCommandTemplate.isEmpty())
	{
		doc[_MODE_COMMAND_TEMPLATE] = _modeCommandTemplate;
		doc[_MODE_COMMAND_TOPIC] = _ctrlTopic;
	}
	if (!_swingModeCommandTemplate.isEmpty())
	{
		doc[_SWING_MODE_COMMAND_TEMPLATE] = _swingModeCommandTemplate;
		doc[_SWING_MODE_COMMAND_TOPIC] = _ctrlTopic;
	}
	if (!_temperatureCommandTemplate.isEmpty())
	{
		doc[_TEMPERATURE_COMMAND_TEMPLATE] = _temperatureCommandTemplate;
		doc[_TEMPERATURE_COMMAND_TOPIC] = _ctrlTopic;
	}
	if (!_fanModeStateTemplate.isEmpty())
	{
		doc[_FAN_MODE_STATE_TEMPLATE] = _fanModeStateTemplate;
		doc[_FAN_MODE_STATE_TOPIC] = _stateTopic;
	}
	if (!_modeStateTemplate.isEmpty())
	{
		doc[_MODE_STATE_TEMPLATE] = _modeStateTemplate;
		doc[_MODE_STATE_TOPIC] = _stateTopic;
	}
	if (!_swingModeStateTemplate.isEmpty())
	{
		doc[_SWING_MODE_STATE_TEMPLATE] = _swingModeStateTemplate;
		doc[_SWING_MODE_STATE_TOPIC] = _stateTopic;
	}
	if (!_temperatureStateTemplate.isEmpty())
	{
		doc[_TEMPERATURE_STATE_TEMPLATE] = _temperatureStateTemplate;
		doc[_TEMPERATURE_STATE_TOPIC] = _stateTopic;
	}

	for (int i = 0; i < 10; i++)
	{
		if (!_modes[i].isEmpty())
			doc[_MODES][i] = _modes[i];

		if (!_swingModes[i].isEmpty())
			doc[_SWING_MODES][i] = _swingModes[i];

		if (!_fanModes[i].isEmpty())
			doc[_FAN_MODES][i] = _fanModes[i];
	}

	doc[_MAX_TEMP]=_maxTemp;
	doc[_MIN_TEMP]=_minTemp;
	doc[_TEMPERATURE_UNIT]=_temperatureUnit;

	serializeJson(doc, _mqttDiscoveryMesg);
}
//******** Setters ********
void HAMqttDiscoveryClimate::setDeviceNameMin(String deviceNameMin)
{
	_deviceNameMin = deviceNameMin;
}
void HAMqttDiscoveryClimate::setFanModeCommandTemplate(String fanModeCommandTemplate)
{
	_fanModeCommandTemplate = fanModeCommandTemplate;
}
void HAMqttDiscoveryClimate::setModeCommandTemplate(String modeCommandTemplate)
{
	_modeCommandTemplate = modeCommandTemplate;
}
void HAMqttDiscoveryClimate::setSwingModeCommandTemplate(String swingModeCommandTemplate)
{
	_swingModeCommandTemplate = swingModeCommandTemplate;
}
void HAMqttDiscoveryClimate::setTemperatureCommandTemplate(String temperatureCommandTemplate)
{
	_temperatureCommandTemplate = temperatureCommandTemplate;
}
void HAMqttDiscoveryClimate::setfanModeStateTemplate(String fanModeStateTemplate)
{
	_fanModeStateTemplate = fanModeStateTemplate;
}
void HAMqttDiscoveryClimate::setModeStateTemplate(String modeStateTemplate)
{
	_modeStateTemplate = modeStateTemplate;
}
void HAMqttDiscoveryClimate::setSwingModeStateTemplate(String swingModeStateTemplate)
{
	_swingModeStateTemplate = swingModeStateTemplate;
}
void HAMqttDiscoveryClimate::setTemperatureStateTemplate(String temperatureStateTemplate)
{
	_temperatureStateTemplate = temperatureStateTemplate;
}

void HAMqttDiscoveryClimate::setModes(String modes[10])
{
	for (int i = 0; i < 10; i++)
	{
		if (!modes[i].isEmpty())
			_modes[i] = modes[i];
	}
}
void HAMqttDiscoveryClimate::setSwingModes(String swingModes[10])
{
	for (int i = 0; i < 10; i++)
	{
		if (!swingModes[i].isEmpty())
			_swingModes[i] = swingModes[i];
	}
}
void HAMqttDiscoveryClimate::setFanModes(String fanModes[10])
{
	for (int i = 0; i < 10; i++)
	{
		if (!fanModes[i].isEmpty())
			_fanModes[i] = fanModes[i];
	}
}
void HAMqttDiscoveryClimate::setMaxTemp(float maxTemp)
{
	_maxTemp = maxTemp;
}
void HAMqttDiscoveryClimate::setMinTemp(float minTemp)
{
	_minTemp = minTemp;
}
void HAMqttDiscoveryClimate::setTemperatureUnit(String temperatureUnit)
{
	_temperatureUnit = temperatureUnit;
}