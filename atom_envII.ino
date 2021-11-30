/*
参考: https://lang-ship.com/blog/work/m5stack-env-ii-unit-u001-b/
*/

#include <M5Atom.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_SHT31.h>

Adafruit_SHT31 sht3x = Adafruit_SHT31(&Wire1);
Adafruit_BMP280 bme = Adafruit_BMP280(&Wire1);

float temperature = 0.0;
float humidity = 0.0;
float pressure = 0.0;

void setup()
{
  M5.begin(true, false, true);
  Wire1.begin(26, 32);

  while (!bme.begin(0x76))
  {
    Serial.println("BME connect error");
  }

  while (!sht3x.begin(0x44))
  {
    Serial.println("SHT coonect error");
  }
}

void loop()
{

  pressure = bme.readPressure();
  temperature = sht3x.readTemperature();
  humidity = sht3x.readHumidity();

  Serial.println("==============================");
  Serial.printf("Temperature: %2.2f \n", temperature);
  Serial.printf("Humidity: %2.2f \n", humidity);
  Serial.printf("Pressure: %2.2f \n", pressure);
  Serial.println("==============================");

  delay(100);
  // put your main code here, to run repeatedly:
}
