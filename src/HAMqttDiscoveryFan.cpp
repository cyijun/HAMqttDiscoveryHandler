/**
 * @file HAMqttDiscoveryFan.cpp
 * @author Chen Yijun
 * @brief
 * @version 0.1
 * @date 2022-02-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "HAMqttDiscoveryFan.h"

HAMqttDiscoveryFan::HAMqttDiscoveryFan(HAMqttDiscoveryHandler &deviceObj)
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
}

void HAMqttDiscoveryFan::construct()
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

	if (!_commandTemplate.isEmpty())
	{
		doc[_COMMAND_TOPIC] = _ctrlTopic;
		doc[_COMMAND_TEMPLATE] = _commandTemplate;
	}

	if (!_oscillationCommandTemplate.isEmpty())
	{
		doc[_OSCILLATION_COMMAND_TOPIC] = _ctrlTopic;
		doc[_OSCILLATION_COMMAND_TEMPLATE] = _oscillationCommandTemplate;
	}
	if (!_percentageCommandTemplate.isEmpty())
	{
		doc[_PERCENTAGE_COMMAND_TOPIC] = _ctrlTopic;
		doc[_PERCENTAGE_COMMAND_TEMPLATE] = _percentageCommandTemplate;
	}
	if (!_presetModeCommandTemplate.isEmpty())
	{
		doc[_PRESET_MODE_COMMAND_TOPIC] = _ctrlTopic;
		doc[_PRESET_MODE_COMMAND_TEMPLATE] = _presetModeCommandTemplate;
		for (int i = 0; i < 10; i++)
		{
			if (!_presetModes[i].isEmpty())
				doc[_PRESET_MODES][i] = _presetModes[i];
		}
	}

	if (!_speedRangeMin.isEmpty())
	{
		doc[_SPEED_RANGE_MIN] = _speedRangeMin;
	}

	if (!_speedRangeMax.isEmpty())
	{
		doc[_SPEED_RANGE_MAX] = _speedRangeMax;
	}

	if (!_stateValueTemplate.isEmpty())
	{
		doc[_STATE_TOPIC] = _feedbackTopic;
		doc[_STATE_VALUE_TEMPLATE] = _stateValueTemplate;
	}

	if (!_oscillationValueTemplate.isEmpty())
	{
		doc[_OSCILLATION_STATE_TOPIC] = _feedbackTopic;
		doc[_OSCILLATION_VALUE_TEMPLATE] = _oscillationValueTemplate;
	}
	if (!_percentageValueTemplate.isEmpty())
	{
		doc[_PERCENTAGE_STATE_TOPIC] = _feedbackTopic;
		doc[_PERCENTAGE_VALUE_TEMPLATE] = _percentageValueTemplate;
	}

	if (!_presetModeValueTemplate.isEmpty())
	{
		doc[_PERCENTAGE_STATE_TOPIC] = _feedbackTopic;
		doc[_PRESET_MODE_VALUE_TEMPLATE] = _presetModeValueTemplate;
	}

	serializeJson(doc, _mqttDiscoveryMesg);
}

//********* Getters *********

String HAMqttDiscoveryFan::getMqttDiscoveryConfigTopic()
{
	return _mqttDiscoveryConfigTopic;
}

String HAMqttDiscoveryFan::getMqttDiscoveryMesg()
{
	String mqttDiscoveryMesg = _mqttDiscoveryMesg;
	_mqttDiscoveryMesg.clear();
	return mqttDiscoveryMesg;
}

//******** Setters ********

void HAMqttDiscoveryFan::setDeviceNameMin(String deviceNameMin)
{
	_deviceNameMin = deviceNameMin;
}
void HAMqttDiscoveryFan::setCommandTemplate(String commandTemplate)
{
	_commandTemplate = commandTemplate;
}
void HAMqttDiscoveryFan::setOscillationCommandTemplate(String oscillationCommandTemplate)
{
	_oscillationCommandTemplate = oscillationCommandTemplate;
}
void HAMqttDiscoveryFan::setPercentageCommandTemplate(String percentageCommandTemplate)
{
	_percentageCommandTemplate = percentageCommandTemplate;
}
void HAMqttDiscoveryFan::setPresetModeCommandTemplate(String presetModeCommandTemplate)
{
	_presetModeCommandTemplate = presetModeCommandTemplate;
}
void HAMqttDiscoveryFan::setPresetModes(String presetModes[10])
{
	for (int i = 0; i < 10; i++)
	{
		if (!presetModes[i].isEmpty())
			_presetModes[i] = presetModes[i];
	}
}
void HAMqttDiscoveryFan::setSpeedRangeMin(String speedRangeMin)
{
	_speedRangeMin = speedRangeMin;
}
