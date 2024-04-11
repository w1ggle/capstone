#include "Servo.h"

Servo steering; //creating servo objects
Servo motor;

#define steeringPin 11 //setting pins (hardware PWM)
#define motorPin 10
//#define period 20000 //50hz in microseconds
#define steeringMin 1190 //need to figure out min and maxes
#define steeringMax 1620
#define motorMin 750
#define motorMax 2150

void setup(){
    steering.attach(steeringPin, steeringMin , steeringMax); //attaching the pins to objects
    motor.attach(motorPin, motorMin, motorMax);

    steering.writeMicroseconds(1500); //centering servo

    Serial.begin(9600);
    //Serial.println("Listening"); //open serial port for debugging, not expecting feedback
}

int selection;
int pulse;

void loop(){
    if (Serial.available() > 0) { //if data is inputted
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