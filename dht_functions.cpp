#include "DHT.h"
#include "dht_functions.h"
#include "led_functions.h"

#define DHTPIN_11 13
#define DHTPIN_10 12
#define DHTTYPE DHT11

DHT dht11(DHTPIN_11, DHTTYPE);
DHT dht10(DHTPIN_10, DHTTYPE);

byte statusLedDHT    = 6;

void setup_dht(){
  pinMode(statusLedDHT, OUTPUT);
  digitalWrite(statusLedDHT, LOW); 
  dht11.begin();
  dht10.begin();
}

void read_dht_1(){
  float h1 = dht11.readHumidity();
  float t1 = dht11.readTemperature();

  if (isnan(h1) || isnan(t1)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    Serial.println("--------------------");
    digitalWrite(statusLedDHT, HIGH);
    return;
  }
  Serial.println(F("01 DHT11 Sensors 1"));
  Serial.println("--------------------");
  Serial.print(F("Humidity 1: "));
  Serial.println(h1);
  Serial.print(F("Temperature 1: "));
  Serial.println(t1);
  Serial.println("--------------------");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  digitalWrite(statusLedDHT, HIGH);
  delay(500);
  digitalWrite(statusLedDHT, LOW);
  delay(500);
  digitalWrite(statusLedDHT, HIGH);
  delay(500);
  digitalWrite(statusLedDHT, LOW);
  delay(500);
  digitalWrite(statusLedDHT, HIGH);
  delay(500);
  digitalWrite(statusLedDHT, LOW);
  delay(500);
}

void read_dht_2(){
  float h2 = dht10.readHumidity();
  float t2 = dht10.readTemperature();

  if (isnan(h2) || isnan(t2)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    Serial.println("--------------------");
    digitalWrite(statusLedDHT, HIGH);
    return;
  }
  Serial.println(F("02 DHT11 Sensors 2"));
  Serial.println("--------------------");
  Serial.print(F("Humidity 2: "));
  Serial.println(h2);
  Serial.print(F("Temperature 2: "));
  Serial.println(t2);
  Serial.println("--------------------");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  digitalWrite(statusLedDHT, HIGH);
  delay(500);
  digitalWrite(statusLedDHT, LOW);
  delay(500);
  digitalWrite(statusLedDHT, HIGH);
  delay(500);
  digitalWrite(statusLedDHT, LOW);
  delay(500);
  digitalWrite(statusLedDHT, HIGH);
  delay(500);
  digitalWrite(statusLedDHT, LOW);
  delay(500);
}