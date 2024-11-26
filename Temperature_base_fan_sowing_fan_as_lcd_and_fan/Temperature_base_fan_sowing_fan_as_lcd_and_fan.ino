#include<LiquidCrystal.h>

#define TEMP A0
#define LED 13

float consttemp = 30;

LiquidCrystal lcd(12,11,7,8,9,10);

void setup()
{
  pinMode(LED, OUTPUT);
  lcd.begin(0,0);
  lcd.print("lcd begin");
  delay(1000);
  lcd.clear();
}

void loop()
{
  lcd.clear();
  lcd.begin(0,0);
  
  float temp = analogRead(TEMP);
  
  if(temp>consttemp)
  {
    digitalWrite(LED,HIGH);
    lcd.print("high temperature");
  }
  else
  {
    digitalWrite(LED,LOW);
    lcd.print("low temperature");
  }
  delay(2000);
}