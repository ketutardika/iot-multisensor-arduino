#include "water_temp_functions.h"
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 9
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float Celcius=0;
float Fahrenheit=0;
byte statusLedWTS   = 3;

void water_temp_setup(){
  sensors.begin();
  pinMode(statusLedWTS, OUTPUT);  
  digitalWrite(statusLedWTS, LOW);
  Serial.print("Found ");
  Serial.print(sensors.getDeviceCount(), DEC);
  Serial.println(" devices.");
  delay(10000);
}
void water_temp_read(){
  sensors.requestTemperatures(); 
  Celcius=sensors.getTempCByIndex(0);
  Fahrenheit=sensors.toFahrenheit(Celcius);
  Serial.println(F("05 Digital Temperature Sensor"));
  Serial.println("--------------------");
  Serial.print(" C  ");
  Serial.print(Celcius);
  Serial.print(" F  ");
  Serial.println(Fahrenheit);
  Serial.println("--------------------");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  digitalWrite(statusLedWTS, HIGH);
  delay(500);
  digitalWrite(statusLedWTS, LOW);
  delay(500);
  digitalWrite(statusLedWTS, HIGH);
  delay(500);
  digitalWrite(statusLedWTS, LOW);
  delay(500);
  digitalWrite(statusLedWTS, HIGH);
  delay(500);
  digitalWrite(statusLedWTS, LOW);
  delay(500);
  delay(1000);
}