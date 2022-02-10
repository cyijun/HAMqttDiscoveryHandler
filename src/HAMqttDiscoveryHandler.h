/**
 * @file HAMqttDiscoveryHandler.h
 * @author Chen Yijun
 * @brief
 * @version 0.1
 * @date 2022-02-09
 *
 * HAMqttDiscoveryHandler
 *  Copyright (C) 2022  Chen Yijun
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
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