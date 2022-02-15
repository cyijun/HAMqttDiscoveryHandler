[![arduino-library-badge](https://www.ardu-badge.com/badge/HAMqttDiscoveryHandler.svg?)](https://www.ardu-badge.com/HAMqttDiscoveryHandler)

# HAMqttDiscoveryHandler

An Arduino library that generates MQTT topics and messages for Home Assistant MQTT Discovery. This library is to simplify adding DIY hardware to Home Assistant by MQTT Discovery. Its OO feature makes it can handle complex cases like multiple entities of different types in one device.

## TBD

- [ ] Comments
- [ ] Document
- [ ] Examples

## Supported Device Types

- [ ] ALARM_CONTROL_PANEL
- [ ] BINARY_SENSOR
- [ ] CAMERA
- [ ] COVER
- [x] FAN
- [x] LIGHT
- [ ] LOCK
- [x] SENSOR
- [ ] SWITCH
- [ ] CLIMATE
- [ ] VACUUM

## Release Note

* v0.0.1: Sensor device type is ready and has been tested!
* v0.1.0: Not crap any more.
* v0.1.2: Add two more types. The fan supports most of the operations with feedback like on/off, oscillation percentage and preset mode. But light is too complex to finish in a short time. So the light can only be on or off currently.
