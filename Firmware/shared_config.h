#pragma once
#include <ArduinoJson.h>

// --- VERIFIED GPIO MAPPINGS FROM SCHEMATIC ---

// U4: Environmental / Fan Controller
#define U4_FAN1_GATE    D0 
#define U4_FAN2_GATE    D1 
#define U4_FAN3_GATE    D2 
#define U4_DAT_DATA     D3 
#define U4_I2C_SDA      D4 
#define U4_I2C_SCL      D5 
#define U4_PMS_TX       D6 
#define U4_PMS_RX       D7 
#define U4_DISP_DIN     D10 
#define U4_DISP_CS      D9  
#define U4_DISP_CLK     D8  

// U15: Voice / Camera Servo Controller
#define U15_I2S_SCK     D0 
#define U15_I2S_WS      D1 
#define U15_I2S_SD      D2 
#define U15_MQ135_ADC   D3 
#define U15_SERVO1      D10 
#define U15_SERVO2      D9  
#define U15_SERVO3      D8  
#define U15_SERVO4      D7  

// --- MESSAGE PROTOCOL ---
struct DeviceMessage {
    String device_id;
    String type; 
    unsigned long timestamp;
    JsonDocument payload;
};

inline String serializeMessage(const DeviceMessage& msg) {
    JsonDocument doc;
    doc["device_id"] = msg.device_id;
    doc["type"] = msg.type;
    doc["timestamp"] = msg.timestamp;
    doc["payload"] = msg.payload;
    String output;
    serializeJson(doc, output);
    return output;
}
