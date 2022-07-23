#include "ph_sensor_functions.h"
#define PH_SENSOR A1
float calibration_value = 21.34;
int phval = 0; 
unsigned long int avgval; 
int buffer_arr[10],temp;
int ph_level;

void ph_sensor_read() {
 for(int i=0;i<10;i++) 
 {
 ph_level=analogRead(PH_SENSOR); 
 buffer_arr[i]=ph_level;
 delay(30);
 }
 for(int i=0;i<9;i++)
 {
 for(int j=i+1;j<10;j++)
 {
 if(buffer_arr[i]>buffer_arr[j])
 {
 temp=buffer_arr[i];
 buffer_arr[i]=buffer_arr[j];
 buffer_arr[j]=temp;
 }
 }
 }
 avgval=0;
 for(int i=2;i<8;i++)
 avgval+=buffer_arr[i];
 float volt=(float)avgval*5.0/1024/6;
 float ph_act = -5.70 * volt + calibration_value;
 Serial.println(F("07 DIGITAL PH SENSOR "));
  Serial.println("--------------------");  
  Serial.print("pH Sensor: ");
  Serial.println(ph_level);
  Serial.println(" ");
  Serial.print("pH Val: ");
  Serial.println(ph_act);
  Serial.println(" ");
  Serial.println("--------------------");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" "); 
  delay(1000);
}