#include<Servo.h>

Servo Sgate;

const int trig =9;
const int echo =10;
long duration;
int distance;

void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Sgate.attach(3);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(3);

  digitalWrite(trig,HIGH);
  delayMicroseconds(30);
  digitalWrite(trig,LOW);

  duration = pulseIn(echo,HIGH);

  distance = (duration*0.034)/2;

  Serial.print("distance: ");
  Serial.print(distance);
  Serial.print("cm");

  if(distance<10){
    Sgate.write(90);
    Serial.println("Gate is opened");
  }
  else{
    Sgate.write(0);
    Serial.println("Gate is closed");
  }

  delay(500);
}
