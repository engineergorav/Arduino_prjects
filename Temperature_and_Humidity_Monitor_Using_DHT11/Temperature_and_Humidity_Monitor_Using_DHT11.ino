#include"DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

}

void loop() {
  delay(2000);

  float humidity = dht.readHumidity();
  float temp = dht.readTemperature();

  if(isnan(humidity) || isnan(temp)){
    Serial.print("  Faild to read or value can't be read  ");
    return;
  }

  Serial.print(" Humidity-");
  Serial.print(humidity);
  Serial.print(" Temperatur-");
  Serial.print(temp);
  Serial.print("Celcius");
  Serial.println("");
  
}
