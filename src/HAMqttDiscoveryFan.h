/**
 * @file HAMqttDiscoveryFan.h
 * @author Chen Yijun
 * @brief
 * @version 0.1
 * @date 2022-02-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "HAMqttDiscoveryHandler.h"

class HAMqttDiscoveryFan : public HAMqttDiscoveryHandler
{
public:
	HAMqttDiscoveryFan(HAMqttDiscoveryHandler &deviceObj);
	void construct();

	String getMqttDiscoveryConfigTopic();
	String getMqttDiscoveryMesg();

	void setDeviceNameMin(String deviceNameMin);
	void setCommandTemplate(String commandTemplate);
	void setOscillationCommandTemplate(String oscillationCommandTemplate);
	void setPercentageCommandTemplate(String percentageCommandTemplate);
	void setPresetModeCommandTemplate(String presetModeCommandTemplate);
	void setPresetModes(String presetModes[10]);
	void setSpeedRangeMin(String speedRangeMin);

private:
	const String _deviceType = "fan";

	String _uniqueId;
	String _entityName;
	String _mqttDiscoveryConfigTopic;
	String _mqttDiscoveryMesg;

	String _deviceNameMin;
	String _commandTemplate;
	String _oscillationCommandTemplate;
	String _percentageCommandTemplate;
	String _presetModeCommandTemplate;
	String _presetModes[10];
	String _speedRangeMin;
	String _speedRangeMax;

	
	String _stateValueTemplate
	String _oscillationValueTemplate
	String _percentageValueTemplate
	String _presetModeValueTemplate
};