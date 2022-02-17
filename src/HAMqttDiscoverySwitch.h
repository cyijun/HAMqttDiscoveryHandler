/**
 * @file HAMqttDiscoverySwitch.h
 * @author Chen Yijun
 * @brief 
 * @version 0.1
 * @date 2022-02-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "HAMqttDiscoveryHandler.h"


class HAMqttDiscoverySwitch : public HAMqttDiscoveryHandler
{
public:
	HAMqttDiscoverySwitch(HAMqttDiscoveryHandler &deviceObj);
	void construct();

	void setDeviceNameMin(String deviceNameMin);
	void setPayloadOn(String payloadOn);
	void setPayloadOff(String payloadOff);
	void setValueTemplate(String stateTemplate);

private:
	const String _deviceType = "switch";

	String _uniqueId;
	String _entityName;

	String _deviceNameMin;

	String _payloadOn;
	String _payloadOff;

	String _valueTemplate;
};
