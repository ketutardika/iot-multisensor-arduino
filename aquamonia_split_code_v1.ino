#include <Arduino.h>
#include "led_functions.h"
#include "dht_functions.h"
#include "turbinity_functions.h"
#include "liquid_level_functions.h"
#include "water_temp_functions.h"
#include "water_flow_functions.h"
#include "ph_sensor_functions.h"
#include "buzzer_functions.h"
#include "rtc_functions.h"

byte statusLedARD    = 7;
byte statusLedPH   = 11;

void setup() {
  Serial.begin(115200);
  rtc_setup();
  buzzer_setup();
  setup_dht();
  liquid_sensor_setup();  
  water_temp_setup();
  water_flow_setup();
  pinMode(statusLedARD, OUTPUT);
  digitalWrite(statusLedARD, HIGH);
  pinMode(statusLedPH, OUTPUT);
  digitalWrite(statusLedPH, LOW);
  delay(2000);
}

void loop() {
  rtc_read();
  buzzer_read();
  read_dht_1();
  delay(100);
  buzzer_read();
  read_dht_2();
  delay(100);
  buzzer_read();
  turbibnity_Read();
  delay(100);
  buzzer_read();
  liquid_level_Read();
  delay(100);
  buzzer_read();
  water_temp_read();
  delay(100);
  buzzer_read();
  water_flow_read();
  delay(100);
  buzzer_read();
  ph_sensor_read();
  digitalWrite(statusLedPH, HIGH);
  delay(500);
  digitalWrite(statusLedPH, LOW);
  delay(500);
  digitalWrite(statusLedPH, HIGH);
  delay(500);
  digitalWrite(statusLedPH, LOW);
  delay(500);
  digitalWrite(statusLedPH, HIGH);
  delay(500);
  digitalWrite(statusLedPH, LOW);
  delay(500);
  delay(100);
}
