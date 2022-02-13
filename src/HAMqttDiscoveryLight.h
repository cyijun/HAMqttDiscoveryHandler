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

class HAMqttDiscoveryFan : public HAMqttDiscoveryHandler
{
public:
	HAMqttDiscoveryFan(HAMqttDiscoveryHandler &deviceObj);
	void construct();

	String getMqttDiscoveryConfigTopic();
	String getMqttDiscoveryMesg();

	void setDeviceNameMin(String deviceNameMin);
	void setCommandTemplate(String commandTemplate);
	

private:
	const String _deviceType = "light";

	String _uniqueId;
	String _entityName;
	String _mqttDiscoveryConfigTopic;
	String _mqttDiscoveryMesg;

	String _deviceNameMin;
	String _commandTemplate;
	
};