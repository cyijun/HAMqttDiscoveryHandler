#include "HAMqttDiscoveryHandler.h"

class HAMqttDiscoverySensor : public HAMqttDiscoveryHandler
{

public:
    /**
     * @brief Construct a new HAMqttDiscoverySensor object
     *
     * @param deviceObj
     * @param stateClass
     * @param deviceNameMin
     * @param deviceClass
     * @param unitOfMeasurement
     * @param valueTemplate
     */
    HAMqttDiscoverySensor(HAMqttDiscoveryHandler &deviceObj, String stateClass, String deviceNameMin, String deviceClass, String unitOfMeasurement, String valueTemplate);
    void construct();

    void setDeviceClass(String deviceClass);
    void setStateClass(String stateClass);
    void setUnitOfMeasurement(String unitOfMeasurement);
    void setValueTemplate(String valueTemplate);
    void setDeviceNameMin(String deviceNameMin);

    String getMqttDiscoveryConfigTopic();
    String getMqttDiscoveryMesg();

private:
    const String _deviceType = "sensor";

    String _deviceClass;
    String _unitOfMeasurement;
    String _stateClass;
    String _valueTemplate;
    String _deviceNameMin;

    String _uniqueId;
    String _entityName;
    String _mqttDiscoveryConfigTopic;
    String _mqttDiscoveryMesg;
};