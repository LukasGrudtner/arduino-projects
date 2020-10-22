#include <Arduino.h>
#include <Adafruit_BMP280.h>
#include <Wire.h>
#include <SPI.h>

#define BMP_SCK 18
#define BMP_MISO 19
#define BMP_MOSI 23
#define BMP_CS 5

Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO, BMP_SCK);

void setup()
{
  Serial.begin(9600);
  delay(5000);
  Serial.println(F("BMP280 test"));

  if (!bmp.begin())
  {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1)
      ;
  }

  /**
   * Default settings from datasheet.
   **/
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
}

void loop()
{
  Serial.print(F("Temperature: "));
  Serial.print(bmp.readTemperature());
  Serial.println(" ºC");

  Serial.print(F("Pressure: "));
  Serial.print(bmp.readPressure());
  Serial.println(" Pa");

  Serial.print(F("Approx altitude: "));
  Serial.print(bmp.readAltitude(1013.25)); /* Adjusted to local forecast! */
  Serial.println(" m");

  Serial.println();
  delay(2000);
}