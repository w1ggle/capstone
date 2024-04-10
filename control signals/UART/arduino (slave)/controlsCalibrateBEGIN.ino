#include "Servo.h"

Servo steering; //creating servo objects
Servo motor;

#define steeringPin 11 //setting pins (hardware PWM)
#define motorPin 10
#define period 20000 //50hz in microseconds
#define steeringMin 0 //need to figure out min and maxes
#define steeringMax 0
#define motorMin 0
#define motorMax 0

void setup(){
    steering.attach(steeringPin); //attaching the pins to objects
    motor.attach(motorPin);

    steering.writeMicroseconds(1500); //centering servo
    for(int i = 0; i < 100; i++){ //calibrating motor, send center, max, min (2 secs each)
        motor.writeMicroseconds(1500); 
        delayMicroseconds(period-1500);
    }
    for(int i = 0; i < 100; i++){ 
        motor.writeMicroseconds(500); 
        delayMicroseconds(period-500);
    }
    for(int i = 0; i < 100; i++){ 
        motor.writeMicroseconds(2500); 
        delayMicroseconds(period-2500);
    }

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
                for(int i = 0; i < 100; i++){  //100 iteraions ~= 0.5 secs run time
                    motor.writeMicroseconds(pulse); 
                    delayMicroseconds(period-pulse);
                }
                break;
            default: //do nothing
                break;
        }  
    }
}