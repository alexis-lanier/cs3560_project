#include <Servo.h>

Servo servoRight;
Servo servoLeft;

int isObstaclePinRight = 3;
int isObstaclePinLeft = 2; // This is our input pin
int isObstacleRight = HIGH;  // HIGH MEANS NO OBSTACLE
int isObstacleLeft = HIGH;
int leftLine = 1;
int rightLine = 1;

void setup() {
  
  servoRight.attach(A3);
  servoLeft.attach(A4);
  pinMode(isObstaclePinRight, INPUT);
  pinMode(isObstaclePinLeft, INPUT);
  Serial.begin(19200);
  servoRight.write(180);
  servoLeft.write(0);
  
}

void loop() {
  
  isObstacleRight = digitalRead(isObstaclePinRight);
  isObstacleLeft = digitalRead(isObstaclePinLeft);
  
  if (isObstacleRight == LOW && isObstacleLeft == HIGH) {
    
    Serial.println("Line on the left");
    //Serial.print(isObstacleLeft, isObstacleRight);
    servoLeft.write(80);
    leftLine = 1;
    rightLine = 0;
    Serial.print("Left line = ");
    Serial.println(leftLine);
    Serial.print("Right line = ");
    Serial.println(rightLine);
    delay(100);
    
  }
  
  else if (isObstacleRight == HIGH && isObstacleLeft == LOW) {
    
    Serial.println("Line on the right");
    //Serial.println(isObstacleLeft, isObstacleRight);
    servoRight.write(90);
    leftLine = 0;
    rightLine = 1;
    Serial.print("Left line = ");
    Serial.println(leftLine);
    Serial.print("Right line = ");
    Serial.println(rightLine);
    delay(100);
    
  }
  
  else if (isObstacleRight == LOW && isObstacleLeft == LOW && !(leftLine == 0 && rightLine == 0)) { //((leftLine == 0 && rightLine == 1) || (leftLine == 1 && rightLine == 0) || (leftLine == 1 && rightLine == 1))) {

    Serial.println("Line in the center");
    //Serial.println(isObstacleLeft, isObstacleRight);
    servoRight.write(180);
    servoLeft.write(0);
    leftLine = 1;
    rightLine = 1;
    Serial.print("Left line = ");
    Serial.println(leftLine);
    Serial.print("Right line = ");
    Serial.println(rightLine);
    delay(100);
    
  }

  else {

    Serial.println("Line lost");
    //Serial.println(isObstacleLeft, isObstacleRight);
    servoRight.write(180);
    servoLeft.write(180);
    leftLine = 0;
    rightLine = 0;
    Serial.print("Left line = ");
    Serial.println(leftLine);
    Serial.print("Right line = ");
    Serial.println(rightLine);
    delay(100);
    
  }
  
  delay(200);
}

