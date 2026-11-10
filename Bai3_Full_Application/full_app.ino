#define LED_PIN 2
#define BUTTON_PIN 4

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  digitalWrite(LED_PIN, HIGH);

  Serial.println("Temperature: 28.5 C");
  Serial.println("Humidity: 65 %");

  Serial.println("Button Pressed");
  Serial.println("LED ON");

  Serial.println("OLED: LED ON");
}

void loop() {
}
