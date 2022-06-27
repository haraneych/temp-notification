#include <Wire.h>
#include "DHT.h"

#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE);   //   DHT11 DHT21 DHT22


#if defined(ARDUINO_ARCH_AVR)
#define debug  Serial

#elif defined(ARDUINO_ARCH_SAMD) ||  defined(ARDUINO_ARCH_SAM)
#define debug  SerialUSB
#else
#define debug  Serial
#endif


void setup() {
  Wire.begin();
  dht.begin();
  debug.begin(9600);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  float temp_hum_val[2] = {0};
  
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

  delay(1500);
}