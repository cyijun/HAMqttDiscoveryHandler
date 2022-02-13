/**
 * @file HAMqttDiscoverySensor.h
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
#pragma once

#include "HAMqttDiscoveryHandler.h"

class HAMqttDiscoverySensor : public HAMqttDiscoveryHandler
{

public:
	HAMqttDiscoverySensor(HAMqttDiscoveryHandler &deviceObj);
	HAMqttDiscoverySensor(HAMqttDiscoveryHandler &deviceObj, String stateClass, String deviceNameMin, String deviceClass, String unitOfMeasurement, String valueTemplate);
	void construct();

	String getMqttDiscoveryConfigTopic();
	String getMqttDiscoveryMesg();

	void setDeviceClass(String deviceClass);
	void setStateClass(String stateClass);
	void setUnitOfMeasurement(String unitOfMeasurement);
	void setValueTemplate(String valueTemplate);
	void setDeviceNameMin(String deviceNameMin);

private:
	const String _deviceType = "sensor";

	String _deviceClass;
	String _unitOfMeasurement;
	String _stateClass;
	String _valueTemplate;
	String _deviceNameMin;

	String _uniqueId;
	String _entityName;
	String _mqttDiscoveryConfigTopic;
	String _mqttDiscoveryMesg;
};