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

class HAMqttDiscoveryHandler
{
public:
    enum DeviceType
    {
        ALARM_CONTROL_PANEL,
        BINARY_SENSOR,
        CAMERA,
        COVER,
        FAN,
        LIGHT,
        LOCK,
        SENSOR,
        SWITCH,
        CLIMATE,
        VACUUM
    };
    HAMqttDiscoveryHandler(String platform, String serialNo, String deviceManufacturer, String deviceModel, String deviceSwVersion);

    void generate();

    String getCmdTopic();
    String getCtrlTopic();
    String getStateTopic();
    String getAvailabilityTopic();
    String getMqttDiscoveryConfigTopic();
    String getMqttDiscoveryMesg();

    void setDeviceClass(String deviceClass);
    void setStateClass(String stateClass);
    void setUnitOfMeasurement(String unitOfMeasurement);
    void setValueTemplate(String valueTemplate);
    void setDeviceNameMin(String deviceNameMin);
    void setDeviceType(DeviceType type);

private:
    String deviceTypeToStr(DeviceType type);

    void constructMqttDiscoveryMesg();

    DeviceType _type;

    // init needed
    String _platform;
    String _serialNo;
    String _deviceManufacturer;
    String _deviceType;

    // need to be set
    String _deviceClass;       // temperature
    String _unitOfMeasurement; //"°C"
    String _stateClass;        //"measurement"
    String _valueTemplate;     //"{{ value_json.temperature }}""
    String _deviceNameMin;

    // can be generated
    String _deviceId;
    String _deviceModel;
    String _deviceName;
    String _deviceSwVersion;
    String _entityName;
    String _uniqueId;
    String _availabilityTopic;
    String _cmdTopic;
    String _ctrlTopic;
    String _stateTopic;
    String _mqttDiscoveryConfigTopic;
    String _mqttDiscoveryMesg;
};