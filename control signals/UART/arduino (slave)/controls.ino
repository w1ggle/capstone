#include "Servo.h"

Servo steering;
Servo motor;

#define steeringPin 11
#define motorPin 10
#define period 20000 
#define steeringMin 0
#define steeringMax 0
#define motorMin 0
#define motorMax 0
#define MAX_ITERATIONS = 100; 
#define ITERATION_DELAY = 0;


void setup(){
  steering.attach(steeringPin);
  motor.attach(motorPin);

  steering.writeMicroseconds(1500); //centering

  for(int i = 0; i < 100; i++){ //calibrating motor center
    motor.writeMicroseconds(1500); 
    delayMicroseconds(period-1500);
  }
  for(int i = 0; i < 100; i++){ //calibrating motor center
    motor.writeMicroseconds(500); //centering
    delayMicroseconds(period-500);
  }
  for(int i = 0; i < 100; i++){ //calibrating motor center
    motor.writeMicroseconds(2500); //centering
    delayMicroseconds(period-2500);
  }

    Serial.begin(9600);
    Serial.println("Listening"); //open serial and prompt user
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