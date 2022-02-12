/**
 * @file HAMqttDiscoverySensor.cpp
 * @author Chen Yijun
 * @brief
 * @version 0.1
 * @date 2022-02-12
 *
	Copyright (C) 2022  Chen Yijun

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "HAMqttDiscoverySensor.h"
HAMqttDiscoverySensor::HAMqttDiscoverySensor(HAMqttDiscoveryHandler &deviceObj)
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
	_stateClass = stateClass;
	_deviceNameMin = deviceNameMin;
	_deviceClass = deviceClass;
	_unitOfMeasurement = unitOfMeasurement;
	_valueTemplate = valueTemplate;
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