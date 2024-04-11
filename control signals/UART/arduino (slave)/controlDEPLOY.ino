#include "Servo.h"

Servo steering; //initializing servo objects
Servo motor;

#define steeringPin 11 //setting pins (hardware PWM)
#define motorPin 10
#define steeringMin 1200 //min and maxes
#define steeringMax 1620
#define middle 1430
#define motorMin 750
#define motorMax 2100


void setup(){
    steering.attach(steeringPin, steeringMin , steeringMax); //attaching updating objects
    motor.attach(motorPin, motorMin, motorMax);

    steering.writeMicroseconds(middle); //centering steering

    Serial.begin(9600);
}

int selection;
int pulse;

void loop(){
    if (Serial.available() > 0) { //if data is received (in format of "num1 num2 ")
        selection = Serial.readStringUntil(' ').toInt(); //first is selection
        pulse = Serial.readStringUntil(' ').toInt(); //second is pulse (need to end with a space, or else slow bc timeout)

        switch (selection) { 
            case 1: //steering
                steering.writeMicroseconds(pulse); 
                break;
            case 2: //motor
                motor.writeMicroseconds(pulse); 
                break;
            default: //do nothing
                break;
        }  
    }
}