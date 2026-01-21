int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);

}

void loop() {
blink(200);
blink(200);
blink(200);
delay(50);

blink(100);
blink(100);
blink(100);
delay(50);

blink(200);
blink(200);
blink(200);
delay(1000);
}

void blink(int duration){
  digitalWrite(ledPin, HIGH);
  delay(duration);
  digitalWrite(ledPin, LOW);
  delay(duration);
}