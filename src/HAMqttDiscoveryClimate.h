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
	void setFanModeCommandTemplate(String fanModeCommandTemplate);
	void setModeCommandTemplate(String modeCommandTemplate);
	void setSwingModeCommandTemplate(String swingModeCommandTemplate);
	void setTemperatureCommandTemplate(String temperatureCommandTemplate);
	void setfanModeStateTemplate(String fanModeStateTemplate);
	void setModeStateTemplate(String modeStateTemplate);
	void setSwingModeStateTemplate(String swingModeStateTemplate);
	void setTemperatureStateTemplate(String temperatureStateTemplate);

	void setModes(String modes[10]);
	void setSwingModes(String swingModes[10]);
	void setFanModes(String fanModes[10]);
	void setMaxTemp(float maxTemp);
	void setMinTemp(float minTemp);
	void setTemperatureUnit(String temperatureUnit);

private:
	const String _deviceType = "climate";

	String _uniqueId;
	String _entityName;

	String _deviceNameMin;

	String _fanModeCommandTemplate;
	String _modeCommandTemplate;
	String _swingModeCommandTemplate;
	String _temperatureCommandTemplate;

	String _fanModeStateTemplate;
	String _modeStateTemplate;
	String _swingModeStateTemplate;
	String _temperatureStateTemplate;

	String _modes[10];
	String _swingModes[10];
	String _fanModes[10];
	float _maxTemp = 31;
	float _minTemp = 16;
	String _temperatureUnit = "C";
};
