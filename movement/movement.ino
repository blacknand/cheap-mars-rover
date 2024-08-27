void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(13, HIGH);
  Serial.print("LED status: on\n");
  delay(1000);
  digitalWrite(13, LOW);
  Serial.print("LED status: off\n");
  delay(1000);
}
