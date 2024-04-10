#include "Servo.h"

Servo steering;
Servo motor;

#define steeringPin 8
#define motorPin 8
#define period 20000

int MAX_ITERATIONS = 100; //depends on hardware
int ITERATION_DELAY = 0; //depends on hardware


void setup(){
  steering.attach(steeringPin);
  motor.attach(motorPin);



  myservo.writeMicroseconds(1500);

  
  

  Serial.begin(9600);
  Serial.println("Enter an speed (-100 to 100):"); //open serial and prompt user

  for(int i = 0; i < 400; i++){ //calibrating motor center
    Serial.println(1500);
    digitalWrite(controlPin, HIGH);
    delayMicroseconds(pulse);
    digitalWrite(controlPin, LOW);
    delayMicroseconds(period - 1500);
    delay(3);
    Serial.println("iteration");

  }
}


void loop(){

  if (Serial.available() > 0) { //if data is inputted
    speed = Serial.parseInt(); //get number

    if(speed < speedMin){ //keep input in range
      speed = speedMin;
    } else if (speed > speedMax){
      speed = speedMax;
    }

    Serial.print("speed: "); //print back input
    Serial.println(speed);
    Serial.print("pulse: "); //print back input
    Serial.println(pulse);

    pulse = map(speed, speedMin, speedMax, pulseMin, pulseMax); //mapping input to pulse

    for(int i = 0; i < MAX_ITERATIONS; i++){ //setting it, may take multiple pulses, with delays in between, need to test on hardware
      Serial.println(pulse);
      digitalWrite(controlPin, HIGH);
      delayMicroseconds(pulse);
      digitalWrite(controlPin, LOW);
      delayMicroseconds(period - pulse);
      delay(ITERATION_DELAY);

    }
  }

}