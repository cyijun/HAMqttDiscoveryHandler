/**
 * @file HAMqttDiscoveryHandler.cpp
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

	DynamicJsonDocument doc(1024);
	doc[_AVAILABILITY][0][_TOPIC] = _availabilityTopic;
	JsonObject device = doc.createNestedObject(_DEVICE);
	device[_IDENTIFIERS][0] = _deviceId;
	device[_MANUFACTURER] = _deviceManufacturer;
	device[_MODEL] = _deviceModel;
	device[_NAME] = _deviceName;
	device[_SW_VERSION] = _deviceSwVersion;
	serializeJson(doc, _mqttDiscoveryMesgBase);
}

HAMqttDiscoveryHandler::HAMqttDiscoveryHandler(String platform, String serialNo, String deviceManufacturer, String deviceModel, String deviceSwVersion, String viaDevice)
{
	_platform = platform;
	_platform.toLowerCase();
	_deviceName = serialNo;
	_deviceName.toLowerCase();
	_deviceManufacturer = deviceManufacturer;
	_deviceModel = deviceModel;
	_deviceSwVersion = deviceSwVersion;
	_viaDevice = viaDevice;
	_deviceId = _platform + "_" + _deviceName;
	_cmdTopic = _platform + "/" + _deviceName + "/cmd";
	_ctrlTopic = _platform + "/" + _deviceName + "/ctrl";
	_stateTopic = _platform + "/" + _deviceName + "/attr";
	_availabilityTopic = _platform + "/" + _deviceName + "/state";

	DynamicJsonDocument doc(1024);
	doc[_AVAILABILITY][0][_TOPIC] = _availabilityTopic;
	JsonObject device = doc.createNestedObject(_DEVICE);
	device[_IDENTIFIERS][0] = _deviceId;
	device[_MANUFACTURER] = _deviceManufacturer;
	device[_MODEL] = _deviceModel;
	device[_NAME] = _deviceName;
	device[_SW_VERSION] = _deviceSwVersion;
	device[_VIA_DEVICE] = _viaDevice;
	serializeJson(doc, _mqttDiscoveryMesgBase);
}

//********* Getters *********

String HAMqttDiscoveryHandler::getMqttDiscoveryConfigTopic()
{
	return _mqttDiscoveryConfigTopic;
}

String HAMqttDiscoveryHandler::getMqttDiscoveryMesg()
{
	String mqttDiscoveryMesg = _mqttDiscoveryMesg;
	_mqttDiscoveryMesg.clear();
	return mqttDiscoveryMesg;
}

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
String HAMqttDiscoveryHandler::getMqttDiscoveryMesgBase()
{
	return _mqttDiscoveryMesgBase;
}