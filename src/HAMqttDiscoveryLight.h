/**
 * @file HAMqttDiscoveryLight.h
 * @author Chen Yijun
 * @brief
 * @version 0.1
 * @date 2022-02-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "HAMqttDiscoveryHandler.h"

class HAMqttDiscoveryLight : public HAMqttDiscoveryHandler
{
public:
	HAMqttDiscoveryLight(HAMqttDiscoveryHandler &deviceObj);
	void construct();

	String getMqttDiscoveryConfigTopic();
	String getMqttDiscoveryMesg();

	void setDeviceNameMin(String deviceNameMin);
	void setCommandOnTemplate(String commandOnTemplate);
	void setCommandOffTemplate(String commandOffTemplate);
	void setPayloadOn(String payloadOn);
	void setPayloadOff(String payloadOff);
	void setStateTemplate(String stateTemplate);

private:
	const String _deviceType = "light";

	String _uniqueId;
	String _entityName;
	String _mqttDiscoveryConfigTopic;
	String _mqttDiscoveryMesg;

	String _deviceNameMin;

	String _payloadOn;
	String _payloadOff;

	String _commandOnTemplate;
	String _commandOffTemplate;

	String _stateTemplate;
};
