#include <WiFi.h>
#include <WebSocketsClient.h>
#include <ESP32Servo.h>
#include "../shared_config.h" // Ensure shared_config.h is in the parent folder or adjust path

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";
const char* server_ip = "192.168.1.100";

WebSocketsClient webSocket;
Servo servo1, servo2, servo3, servo4;

void setup() {
  Serial.begin(115200);
  
  servo1.attach(U15_SERVO1, 500, 2400);
  servo2.attach(U15_SERVO2, 500, 2400);
  servo3.attach(U15_SERVO3, 500, 2400);
  servo4.attach(U15_SERVO4, 500, 2400);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { delay(500); }

  webSocket.begin(server_ip, 8080, "/ws");
  webSocket.onEvent(webSocketEvent);
  webSocket.setReconnectInterval(5000);
}

void loop() {
  webSocket.loop();
}

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
  if (type == WStype_TEXT) {
    JsonDocument doc;
    deserializeJson(doc, payload);
    
    if (doc["type"] == "action_command" && doc["payload"]["action"] == "CAMERA_MOVE") {
      int servoId = doc["payload"]["params"]["servo_id"];
      int angle = doc["payload"]["params"]["angle"];
      
      if (angle < 0) angle = 0;
      if (angle > 180) angle = 180;

      if (servoId == 1) servo1.write(angle);
      if (servoId == 2) servo2.write(angle);
      if (servoId == 3) servo3.write(angle);
      if (servoId == 4) servo4.write(angle);
      
      ackAction(doc["payload"]["id"]);
    }
  }
}

void ackAction(String actionId) {
  DeviceMessage msg;
  msg.device_id = "U15_VOICE_SERVO";
  msg.type = "action_status";
  msg.timestamp = millis();
  msg.payload["action_id"] = actionId;
  msg.payload["status"] = "completed";
  webSocket.sendTXT(serializeMessage(msg));
}
