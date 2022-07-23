#include "RTC_functions.h"
#include <DS3231.h> //mengincludekan library DS3231
 
DS3231  rtc(SDA, SCL); // inisialisasi penggunaan i2c

void rtc_setup(){
  rtc.begin();
  // The following lines can be uncommented to set the date and time
  //rtc.setDOW(MONDAY);     // Set Day-of-Week to SUNDAY
  //rtc.setTime(15, 39, 0);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(18, 7, 2022);   // Set the date to January 1st, 2014
}
void rtc_read(){
    // Send Day-of-Week
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  
  // Send date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");

  // Send time
  Serial.println(rtc.getTimeStr());
  
  // Wait one second before repeating
  delay (1000);
}