#include "liquid_level_functions.h"
#include "led_functions.h"
#define LIQUID_SENSOR 10

int Liquid_level;
byte statusLedliquid    = 4;

void liquid_sensor_setup(){
  pinMode(statusLedliquid, OUTPUT);  
  digitalWrite(statusLedliquid, LOW);
  pinMode(LIQUID_SENSOR,INPUT);
}

void liquid_level_Read(){
  Liquid_level=digitalRead(LIQUID_SENSOR);  
  Serial.println(F("04 Liquid Level Sensor"));
  Serial.println("--------------------");
  Serial.println(" ");
  Serial.print("Liquid_level = ");Serial.println(Liquid_level,DEC);
  Serial.println(" ");
  Serial.println("--------------------");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  digitalWrite(statusLedliquid, HIGH);
  delay(500);
  digitalWrite(statusLedliquid, LOW);
  delay(500);
  digitalWrite(statusLedliquid, HIGH);
  delay(500);
  digitalWrite(statusLedliquid, LOW);
  delay(500);
  digitalWrite(statusLedliquid, HIGH);
  delay(500);
  digitalWrite(statusLedliquid, LOW);
  delay(500);
  if (Liquid_level == 1 ){
  digitalWrite(statusLedliquid, HIGH);
  }
}