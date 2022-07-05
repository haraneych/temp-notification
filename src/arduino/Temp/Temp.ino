#include <Wire.h>
#include "DHT.h"

#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE);   //   DHT11 DHT21 DHT22

#include "Air_Quality_Sensor.h"
AirQualitySensor sensor(A0);

#if defined(ARDUINO_ARCH_AVR)
#define debug  Serial

#elif defined(ARDUINO_ARCH_SAMD) ||  defined(ARDUINO_ARCH_SAM)
#define debug  SerialUSB
#else
#define debug  Serial
#endif

#include "MutichannelGasSensor.h"


void setup() {
  Wire.begin();
  dht.begin();
  debug.begin(9600);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  float temp_hum_val[2] = {0};
  int quality = sensor.slope();
  
  if (!dht.readTempAndHumidity(temp_hum_val)) {
    debug.print("Humidity: ");
    debug.print(temp_hum_val[0]);
    debug.print(" %\t");
    debug.print("Temperature: ");
    debug.print(temp_hum_val[1]);
    debug.println(" *C");
  } else {
    debug.println("Failed to get temprature and humidity value.");
  }

 //Air Quality
    debug.print("Sensor value: ");
    debug.println(sensor.getValue());

    if (quality == AirQualitySensor::FORCE_SIGNAL) {
        debug.println("High pollution! Force signal active.");
    } else if (quality == AirQualitySensor::HIGH_POLLUTION) {
        debug.println("High pollution!");
    } else if (quality == AirQualitySensor::LOW_POLLUTION) {
        debug.println("Low pollution!");
    } else if (quality == AirQualitySensor::FRESH_AIR) {
        debug.println("Fresh air.");
    }



  delay(1500);
}
