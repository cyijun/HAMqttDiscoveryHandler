/**
 * @file HAMqttDiscoveryClimate.h
 * @author Chen Yijun
 * @brief 
 * @version 0.1
 * @date 2022-02-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "HAMqttDiscoveryHandler.h"

class HAMqttDiscoveryClimate : public HAMqttDiscoveryHandler
{
public:
	HAMqttDiscoveryClimate(HAMqttDiscoveryHandler &deviceObj);
	void construct();

	void setDeviceNameMin(String deviceNameMin);


private:
	const String _deviceType = "climate";

	String _uniqueId;
	String _entityName;

	String _deviceNameMin;

	String _fanModeCommandTemplate;
	String _modeCommandTemplate;
	String _swingModeCommandTemplate;
	String _temperatureCommandTemplate;

	String _fanMode_stateTemplate;
	String _modeStateTemplate;
	String _swingModeStateTemplate;
	String _temperatureStateTemplate;

	String _modes[10];
	String _swingModes[10];
	String _fanModes[10];
	float _maxTemp =16;
	float _minTemp =31;
	String _temperatureUnit="C";
};
