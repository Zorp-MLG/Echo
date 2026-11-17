#include <WiFi.h>
#include <WebSocketsClient.h>
#include <Wire.h>
#include "../shared_config.h" // Ensure shared_config.h is in the parent folder or adjust path

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";
const char* server_ip = "192.168.1.100"; // PC Server IP

WebSocketsClient webSocket;

void setup() {
  Serial.begin(115200);
  pinMode(U4_FAN1_GATE, OUTPUT);
  pinMode(U4_FAN2_GATE, OUTPUT);
  pinMode(U4_FAN3_GATE, OUTPUT);
  
  Wire.begin(U4_I2C_SDA, U4_I2C_SCL);
  Serial2.begin(9600, SERIAL_8N1, U4_PMS_RX, U4_PMS_TX);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { delay(500); }

  webSocket.begin(server_ip, 8080, "/ws");
  webSocket.onEvent(webSocketEvent);
  webSocket.setReconnectInterval(5000);
}

void loop() {
  webSocket.loop();
  
  static unsigned long lastSensorRead = 0;
  if (millis() - lastSensorRead > 5000) { 
    sendSensorData();
    lastSensorRead = millis();
  }
}

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
  if (type == WStype_TEXT) {
    JsonDocument doc;
    deserializeJson(doc, payload);
    if (doc["type"] == "action_command" && doc["payload"]["action"] == "FAN_SET") {
      int fanId = doc["payload"]["params"]["fan_id"];
      bool state = doc["payload"]["params"]["state"];
      
      if (fanId == 1) digitalWrite(U4_FAN1_GATE, state ? HIGH : LOW);
      if (fanId == 2) digitalWrite(U4_FAN2_GATE, state ? HIGH : LOW);
      if (fanId == 3) digitalWrite(U4_FAN3_GATE, state ? HIGH : LOW);
      
      ackAction(doc["payload"]["id"]);
    }
  }
}

void sendSensorData() {
  DeviceMessage msg;
  msg.device_id = "U4_ENV";
  msg.type = "sensor_update";
  msg.timestamp = millis();
  
  msg.payload["pm1"] = 8;    
  msg.payload["pm25"] = 15;  
  msg.payload["pm10"] = 22;  
  msg.payload["temp_c"] = 29.5; 
  
  webSocket.sendTXT(serializeMessage(msg));
}

void ackAction(String actionId) {
  DeviceMessage msg;
  msg.device_id = "U4_ENV";
  msg.type = "action_status";
  msg.timestamp = millis();
  msg.payload["action_id"] = actionId;
  msg.payload["status"] = "completed";
  webSocket.sendTXT(serializeMessage(msg));
}
