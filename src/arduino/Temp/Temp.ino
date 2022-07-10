#include <Wire.h>
#include "DHT.h"
#include "rgb_lcd.h"

#define DHTTYPE DHT22   // DHT 22  (AM2302)
#define DHTPIN 2     // what pin we're connected to（DHT10 and DHT20 don't need define it）
DHT dht(DHTPIN, DHTTYPE);   //   DHT11 DHT21 DHT22

#if defined(ARDUINO_ARCH_AVR)
#define debug  Serial

#elif defined(ARDUINO_ARCH_SAMD) ||  defined(ARDUINO_ARCH_SAM)
#define debug  SerialUSB
#else
#define debug  Serial
#endif

#include "Air_Quality_Sensor.h"
AirQualitySensor sensor(A0);

rgb_lcd lcd;

void setup() {
  Wire.begin();
  dht.begin();
  debug.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  //lcd.clear();
  //lcd.setCursor(0, 0);
  float temp_hum_val[2] = {0};
  int quality = sensor.slope();
  
  if (!dht.readTempAndHumidity(temp_hum_val)) {
//    debug.print("Humidity: ");
//    debug.print(temp_hum_val[0]);
//    debug.print(" %\t");
//    debug.print("Temperature: ");
    debug.print(temp_hum_val[1]);
//    debug.println(" *C");

//    lcd.print("Humidity: ");
//    lcd.print(temp_hum_val[0]);
//    lcd.print(" %\t");
    lcd.print("Temp: ");
    lcd.print(temp_hum_val[1]);
    lcd.println(" *C");
  } else {
    debug.println("Failed to get temprature and humidity value.");
  }

 //Air Quality
    lcd.setCursor(0, 1);
//    debug.print("Sensor value: ");
//    debug.println(sensor.getValue());
    //lcd.print("Sensor value: ");
    if (quality == AirQualitySensor::FORCE_SIGNAL) {
        debug.println("High pollution! Force signal active.");
        lcd.println("High pollution! Force signal active.");
        lcd.setRGB(255, 0, 0);
    } else if (quality == AirQualitySensor::HIGH_POLLUTION) {
        debug.println("High pollution!");
        lcd.println("High pollution!");
        lcd.setRGB(255, 150, 0);
    } else if (quality == AirQualitySensor::LOW_POLLUTION) {
        debug.println("Low pollution!");
        lcd.println("Low pollution!");
        lcd.setRGB(0, 255, 255);
    } else if (quality == AirQualitySensor::FRESH_AIR) {
        debug.println("Fresh air.");
        lcd.println("Fresh air.");
        lcd.setRGB(0, 150, 255);
    }

  delay(3000);
}
