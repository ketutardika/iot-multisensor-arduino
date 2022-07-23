#include "buzzer_functions.h"
int buzzer = 8; // set the buzzer control digital IO pin
void buzzer_setup() {
	pinMode(buzzer, OUTPUT); // set pin 8 as output
}
void buzzer_read() {
	for (int i = 0; i < 100; i++) {  // make a sound
		digitalWrite(buzzer, HIGH); // send high signal to buzzer 
		delay(1); // delay 1ms
		digitalWrite(buzzer, LOW); // send low signal to buzzer
		delay(1);
	}
	delay(500);
}