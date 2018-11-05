#include <Servo.h>

const int pingPin = 7;
double microseconds;
Servo servoRight;
Servo servoLeft;

void setup() {
  // initialize serial communication:
  Serial.begin(19200);
  servoRight.attach(A3);
  servoLeft.attach(A4);
}

void loop() {

  servoRight.write(180);
  servoLeft.write(0);
  
  double duration, inches, cm;
  
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

/*
  if(inches < 2) {
      servoRight.write(180);
      delay(2000);
  }
  else {
    servoRight.write(0);
  }
*/
    
  while(inches < 2) {

      servoRight.write(0);

      pinMode(pingPin, OUTPUT);
      digitalWrite(pingPin, LOW);
      delayMicroseconds(2);
      digitalWrite(pingPin, HIGH);
      delayMicroseconds(2);
      digitalWrite(pingPin, LOW);

      pinMode(pingPin, INPUT); 
      duration = pulseIn(pingPin, HIGH);

  
      inches = microsecondsToInches(duration);
      cm = microsecondsToCentimeters(duration);

      Serial.print(inches);
      Serial.print("in, ");
      Serial.println();

      delay(100);
  }

  delay(100);
}

double microsecondsToInches(double duration) {
 
  return duration / 73.746 / 2.0;
}

double microsecondsToCentimeters(double microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

