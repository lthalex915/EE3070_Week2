const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  Serial.begin(9600); 
  Serial.println("RGB LED Controller");
  Serial.println("Commands: r=Red, g=Green, b=Blue, p=Purple, y=Yellow, c=Cyan, w=White, o=Off");
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();  // Read the incoming character
    
    switch (command) {
      case 'r':  // Red
        digitalWrite(redPin, HIGH);
        digitalWrite(greenPin, LOW);
        digitalWrite(bluePin, LOW);
        Serial.println("Color: Red");
        break;
        
      case 'g':  // Green
        digitalWrite(redPin, LOW);
        digitalWrite(greenPin, HIGH);
        digitalWrite(bluePin, LOW);
        Serial.println("Color: Green");
        break;
        
      case 'b':  // Blue
        digitalWrite(redPin, LOW);
        digitalWrite(greenPin, LOW);
        digitalWrite(bluePin, HIGH);
        Serial.println("Color: Blue");
        break;
        
      case 'p':  // Purple
        digitalWrite(redPin, HIGH);
        digitalWrite(greenPin, LOW);
        digitalWrite(bluePin, HIGH);
        Serial.println("Color: Purple");
        break;
        
      case 'y':  // Yellow
        digitalWrite(redPin, HIGH);
        digitalWrite(greenPin, HIGH);
        digitalWrite(bluePin, LOW);
        Serial.println("Color: Yellow");
        break;
        
      case 'c':  // Cyan
        digitalWrite(redPin, LOW);
        digitalWrite(greenPin, HIGH);
        digitalWrite(bluePin, HIGH);
        Serial.println("Color: Cyan");
        break;
        
      case 'w':  // White
        digitalWrite(redPin, HIGH);
        digitalWrite(greenPin, HIGH);
        digitalWrite(bluePin, HIGH);
        Serial.println("Color: White");
        break;
        
      case 'o':  // Off
        digitalWrite(redPin, LOW);
        digitalWrite(greenPin, LOW);
        digitalWrite(bluePin, LOW);
        Serial.println("LED Off");
        break;
    }
  }
}