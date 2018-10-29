#include <Servo.h>

const int pingPin = 7;
double microseconds;
Servo servo;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  servo.attach(2);
  servo.write(0);
}

void loop() {
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  double duration, inches, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
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

  if (inches < 2) {
      servo.write(180);
      delay(2000);
  }
  else {
    servo.write(0);
  }
  
  delay(1000);
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

