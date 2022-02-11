/**
 * @file HAMqttDiscoveryHandler.h
 * @author Chen Yijun
 * @brief
 * @version 0.1
 * @date 2022-02-09
 *
 * GPLv3
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
