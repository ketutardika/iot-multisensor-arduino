#include "water_flow_functions.h"
int X;
int Y;
float TIME = 0;
float FREQUENCY = 0;
float WATER = 0;
float TOTAL = 0;
float LS = 0;
const int input = A2;
byte statusLedWF   = 2;
void water_flow_setup()
{
  pinMode(input,INPUT);
  pinMode(statusLedWF, OUTPUT);  
  digitalWrite(statusLedWF, LOW);
}
void water_flow_read()
{
  X = pulseIn(input, HIGH);
  Y = pulseIn(input, LOW);
  TIME = X + Y;
  FREQUENCY = 1000000/TIME;
  WATER = FREQUENCY/7.5;
  LS = WATER/60;
  if(FREQUENCY >= 0)
  {
    if(isinf(FREQUENCY))
    {
      Serial.println(F("06 Water Flow Sensor"));
      Serial.println("--------------------");
      Serial.println("VOL. :0.00");
      Serial.print("TOTAL:");
      Serial.print( TOTAL);
      Serial.println(" L");
      Serial.println("--------------------");
      Serial.println(" ");
      Serial.println(" ");
      Serial.println(" ");
      Serial.println(" ");
      Serial.println(" ");
      Serial.println(" ");
      digitalWrite(statusLedWF, HIGH);
      delay(500);
      digitalWrite(statusLedWF, LOW);
      delay(500);
      digitalWrite(statusLedWF, HIGH);
      delay(500);
      digitalWrite(statusLedWF, LOW);
      delay(500);
      digitalWrite(statusLedWF, HIGH);
      delay(500);
      digitalWrite(statusLedWF, LOW);
      delay(500);
    }
    else
    {
      TOTAL = TOTAL + LS;
      Serial.println(F("06 Water Flow Sensor"));
      Serial.println("--------------------");
      Serial.println(FREQUENCY);
      Serial.print("VOL.: ");
      Serial.print(WATER);
      Serial.println(" L/M");
      Serial.print("TOTAL:");
      Serial.print( TOTAL);
      Serial.println(" L");
      Serial.println("--------------------");
      Serial.println(" ");
      Serial.println(" ");
      Serial.println(" ");
      Serial.println(" ");
      Serial.println(" ");
      Serial.println(" ");
      digitalWrite(statusLedWF, HIGH);
    }
  }
  delay(1000);
}