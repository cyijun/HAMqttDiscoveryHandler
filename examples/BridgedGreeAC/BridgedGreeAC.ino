/**
 * @file BridgedGreeAC.ino
 * @author Chen Yijun
 * @brief This is an example of Gree AC bridged by HomeGear. The two global objects handle HA device
 *        registry, and the climate entity is local object.
 * @version 0.1
 * @date 2022-02-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "HAMDHandler.h"

#define PLATFORM "HomeGear"
#define HOMEGEAR_SERIAL_NUMBER "SN001"
#define MANUFACTURER "Chen Yijun"
#define DEVICE_MODEL "HomeGear Scalable Hardware Stack"
#define SOFTWARE_VERSION "HomeGear 1.0"

HAMqttDiscoveryHandler hamdhHG(PLATFORM, HOMEGEAR_SERIAL_NUMBER, MANUFACTURER, DEVICE_MODEL, SOFTWARE_VERSION);
HAMqttDiscoveryHandler hamdhGree("homegear_ir", "ac001", "Gree", "Gree AC", SOFTWARE_VERSION, hamdhHG);

void setup()
{
	HAMqttDiscoveryClimate hamdhGreeAC(hamdhGree);
	hamdhGreeAC.setDeviceNameMin("gree_ac");
	hamdhGreeAC.setModeCommandTemplate("{\"acgree_mode\": \"{{ value }}\"}");
	hamdhGreeAC.setFanModeCommandTemplate("{\"acgree_fan_mode\": \"{{ value }}\"}");
	hamdhGreeAC.setSwingModeCommandTemplate("{\"acgree_swing_mode\": \"{{ value }}\"}");
	hamdhGreeAC.setTemperatureCommandTemplate("{\"acgree_temperature\": \"{{ value }}\"}");
	hamdhGreeAC.setfanModeStateTemplate("{{ value_json.acgree_fan_mode }}");
	hamdhGreeAC.setModeStateTemplate("{{ value_json.acgree_mode }}");
	hamdhGreeAC.setSwingModeStateTemplate("{{ value_json.acgree_swing_mode }}");
	hamdhGreeAC.setTemperatureStateTemplate("{{ value_json.acgree_temperature }}");
	String modes[10] = {"auto", "cool", "dry", "fan_only", "heat", "off", "", "", "", ""};
	String swingModes[10] = {"off", "vertical", "horizontal", "both", "", "", "", "", "", ""};
	String fanModes[10] = {"low", "medium", "high", "", "", "", "", "", "", ""};
	hamdhGreeAC.setModes(modes);
	hamdhGreeAC.setSwingModes(swingModes);
	hamdhGreeAC.setFanModes(fanModes);

	hamdhGreeAC.construct();
	//mqttClient.publish(hamdhGreeAC.getMqttDiscoveryConfigTopic(), hamdhGreeAC.getMqttDiscoveryMesg(), true);
	Serial.println("\nYou need to publish:\n");
	Serial.println(hamdhGreeAC.getMqttDiscoveryMesg());
	Serial.println("\nTo:\n");
	Serial.println(hamdhGreeAC.getMqttDiscoveryConfigTopic());
}

void loop() {}