#include<Servo.h>

Servo myServo;

const int led = 13;
const int trig = 5;
const int echo = 6;
long duration;
int distance;

void setup() {
  myServo.attach(3);
  pinMode(led , OUTPUT);
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  
}

void loop() {
  
  digitalWrite(trig,LOW);
  delayMicroseconds(4);
  
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  duration = pulseIn(echo , HIGH);
  distance = (duration*0.034)/2;
  
  if(distance<90)
  {
    myServo.write(90);
    int i=1;
    while(i>0){
      digitalWrite(led,HIGH);
      digitalWrite(led,LOW);
      i++;
      
    }
  }
  else if(distance<100)
  {
    digitalWrite(led , HIGH);
  }
  else
  {
    myServo.write(0);
    digitalWrite(led , LOW);
  }
  delay(500);
}
