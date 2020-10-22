#include <Arduino.h>

typedef struct Payload
{
  float temperature;
  float pressure;
  float altitude;
} Payload;

Payload payload;

void print() {
  Serial.print("Temperature: ");
  Serial.print(payload.temperature);
  Serial.println(" °C");

  Serial.print("Pressure: ");
  Serial.print(payload.pressure);
  Serial.println(" Pa");

  Serial.print("Altitude: ");
  Serial.print(payload.altitude);
  Serial.println(" m");

  Serial.println();
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    Serial.readBytes((uint8_t *) &payload, sizeof(Payload));
    print();
  }
}