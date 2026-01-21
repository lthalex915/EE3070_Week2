const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("=== RGB LED Controller with Brightness ===");
  Serial.println("Command format: Cxx (C=Color, xx=Brightness 0-100)");
  Serial.println("Colors: R=Red, G=Green, B=Blue, P=Purple, Y=Yellow, C=Cyan");
  Serial.println("Examples: R100, G50, P75, B0");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();  
    
    if (input.length() >= 2) {
      char color = input.charAt(0); 
      int brightness = input.substring(1).toInt();  
      
      brightness = constrain(brightness, 0, 100);
      
      int pwmValue = map(brightness, 0, 100, 0, 255);
      
      setColor(color, pwmValue);
    }
  }
}

void setColor(char color, int pwm) {
  // turn off all LEDs
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
  
  switch (color) {
    case 'R':
    case 'r':
      analogWrite(redPin, pwm);
      Serial.print("Red at ");
      break;
      
    case 'G':
    case 'g':
      analogWrite(greenPin, pwm);
      Serial.print("Green at ");
      break;
      
    case 'B':
    case 'b':
      analogWrite(bluePin, pwm);
      Serial.print("Blue at ");
      break;
      
    case 'P':
    case 'p':
      analogWrite(redPin, pwm);
      analogWrite(bluePin, pwm);
      Serial.print("Purple at ");
      break;
      
    case 'Y':
    case 'y':
      analogWrite(redPin, pwm);
      analogWrite(greenPin, pwm);
      Serial.print("Yellow at ");
      break;
      
    case 'C':
    case 'c':
      analogWrite(greenPin, pwm);
      analogWrite(bluePin, pwm);
      Serial.print("Cyan at ");
      break;
      
    default:
      Serial.println("Invalid color! Use R, G, B, P, Y, or C");
      return;
  }
  
  Serial.print(map(pwm, 0, 255, 0, 100));
  Serial.print("% (PWM: ");
  Serial.print(pwm);
  Serial.println(")");
}