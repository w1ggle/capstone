#!/usr/bin/env python3
import Jetson.GPIO as GPIO
from pinControl import servoPin, usleep

# Definitions
#frequency = 50 #in hertz (50 to 200?)
#period = (1.0 / frequency) * 1000000.0 #convert to microseconds
period = 20000 #in microseconds
pulseMin = 1200 #in microseconds
pulseMax = 1610 #in microseconds
deadband = 2

MAX_ITERATIONS = 1 #depends on hardware
    
def servo_control(pulse):
    
    if(pulse < pulseMin): #keep input in range
        pulse = pulseMin
    elif (pulse > pulseMax):
        pulse = pulseMax
        
    print("pulse: " + str(pulse))
    #pulse = map_range(angle, angleMin, angleMax, pulseMin, pulseMax) / 1000000.0 #convert to seconds
    
    for i in range(0, MAX_ITERATIONS): #setting it, may take multiple pulses, with delays in between, need to test on hardware
        GPIO.output(servoPin, GPIO.HIGH)
        usleep(pulse)
        #print(pulse)
        GPIO.output(servoPin, GPIO.LOW)
        usleep((period - pulse) + deadband)
        #print((period - pulse) + deadband)
