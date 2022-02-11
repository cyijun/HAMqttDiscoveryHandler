/**
 * @file HAMqttDiscoveryHandler.h
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

#include "Arduino.h"
#include <ArduinoJson.h>

//#include "HAJsonKeyAbbr.h"
#include "HAJsonKey.h"

class HAMqttDiscoveryHandler
{
public:
	HAMqttDiscoveryHandler();
	HAMqttDiscoveryHandler(String platform, String serialNo, String deviceManufacturer, String deviceModel, String deviceSwVersion);

	String getPlatform();
	String getDeviceName();
	String getDeviceManufacturer();
	String getDeviceModel();
	String getDeviceSwVersion();
	String getDeviceId();
	String getCmdTopic();
	String getCtrlTopic();
	String getStateTopic();
	String getAvailabilityTopic();

protected:
	// must be init
	String _platform;
	String _deviceName;
	String _deviceManufacturer;
	String _deviceModel;
	String _deviceSwVersion;

	// can be generated
	String _deviceId;
	String _availabilityTopic;
	String _stateTopic;

private:
	String _cmdTopic;
	String _ctrlTopic;
};
