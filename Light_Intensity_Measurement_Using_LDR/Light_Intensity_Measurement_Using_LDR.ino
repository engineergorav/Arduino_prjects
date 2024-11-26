int ldr =A0;
int ldrval =0;
void setup() {
  pinMode(ldr,INPUT);
  Serial.begin(9600);
}

void loop() {
  ldrval = analogRead(ldr);

  Serial.print("light intensity ");
  Serial.print(ldrval);
  Serial.print("Lumen");
  Serial.println("");

  delay(1000);
}
