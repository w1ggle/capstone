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

int selection;
int pulse;

void loop(){

  if (Serial.available() > 0) { //if data is inputted
    selection = Serial.readStringUntil(' ').toInt();
    pulse = Serial.readStringUntil(' ').toInt(); 

    switch (selection) {
        case 1:
            Serial.print("Steering: "); //print back input
            Serial.println(pulse);
            break;
        case 2:
            Serial.print("Motor: "); //print back input
            Serial.println(pulse);
            break;
        default:
            break;
        }

   
  }

}