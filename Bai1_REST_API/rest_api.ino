#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

WebServer server(80);

void handleSensor() {
  String json = "{\"temperature\":28.5,\"humidity\":65}";
  server.send(200, "application/json", json);
}

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected");
  Serial.println(WiFi.localIP());

  server.on("/api/sensor", handleSensor);

  server.begin();

  Serial.println("REST API Started");
}

void loop() {
  server.handleClient();
}
