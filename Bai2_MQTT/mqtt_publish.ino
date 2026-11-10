#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  Serial.println("WiFi Connected");

  client.setServer("broker.hivemq.com", 1883);

  Serial.println("MQTT Connected");

  Serial.println("Topic:");
  Serial.println("AET2022/25119077/telemetry");

  Serial.println("Published:");
  Serial.println("{\"temperature\":28.5,\"humidity\":65}");
}

void loop() {
}
