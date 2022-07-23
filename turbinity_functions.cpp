#include "turbinity_functions.h"

int sensorPin = A0;
float volt;
float ntu;

int square(int x) {  // function declared and implemented
    return x*x;
}

byte statusLedturbinity    = 5;

float round_to_dp( float in_value, int decimal_place )
{
  float multiplier = powf( 10.0f, decimal_place );
  in_value = roundf( in_value * multiplier ) / multiplier;
  return in_value;
}

void turbibnity_Read()
{
    volt = 0;
    for(int i=0; i<800; i++)
    {
        volt += ((float)analogRead(sensorPin)/1023)*5;
    }
    volt = volt/800;
    volt = round_to_dp(volt,2);
    if(volt < 2.5){
      ntu = 3000;
    }else{
      ntu = -1120.4*square(volt)+5742.3*volt-4353.8; 
    }
    Serial.println(F("03 Gravity Turbinity"));
    Serial.println("--------------------");
    Serial.print(volt);
    Serial.println(" V");

    Serial.print(ntu);
    Serial.println(" NTU");
    Serial.println(F("--------------------"));
    Serial.println(" ");
    Serial.println(" ");
    Serial.println(" ");
    Serial.println(" ");
    Serial.println(" ");
    pinMode(statusLedturbinity, OUTPUT);
    digitalWrite(statusLedturbinity, HIGH);
    delay(500);
    digitalWrite(statusLedturbinity, LOW);
    delay(500);
    digitalWrite(statusLedturbinity, HIGH);
    delay(500);
    digitalWrite(statusLedturbinity, LOW);
    delay(500);
    digitalWrite(statusLedturbinity, HIGH);
    delay(500);
    digitalWrite(statusLedturbinity, LOW);
    delay(500);
    delay(10);
}