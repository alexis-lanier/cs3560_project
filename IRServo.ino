#include <IRremote.h>
#include <IRremoteInt.h>

//#include <Servo.h>


int RECV_PIN = 4;
//Servo servo;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(8, OUTPUT);
  //servo.attach(0);
  //servo.write(180);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    irrecv.resume(); // Receive the next value
  }
  if (results.value == 50165895) {
    digitalWrite(8, HIGH);
    //servo.write(180);
  }
  else if (results.value == 50157735) {
    digitalWrite(8, LOW);
    //servo.write(0);
  }
 }

