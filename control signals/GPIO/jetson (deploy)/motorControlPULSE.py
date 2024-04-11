#!/usr/bin/env python3
import Jetson.GPIO as GPIO
from pinControl import motorPin, usleep

# Definitions
#frequency = 50 #in hertz (50 to 200?)
#period = (1.0 / frequency) * 1000000.0 #convert to microseconds
period = 20000 #in microseconds
pulseMin = 725 #in microseconds
pulseMax = 2125 #in microseconds
deadband = 3

MAX_ITERATIONS = 200 #depends on hardware looking ~200 = 0.5 seconds

def motor_control(pulse):
    
    if(pulse < pulseMin): #keep input in range
        pulse = pulseMin
    elif (pulse > pulseMax):
        pulse = pulseMax
        
    print("pulse: " + str(pulse))
    #pulse = map_range(angle, angleMin, angleMax, pulseMin, pulseMax) / 1000000.0 #convert to seconds
    
    for i in range(0, MAX_ITERATIONS): #setting it, may take multiple pulses, with delays in between, need to test on hardware
        GPIO.output(motorPin, GPIO.HIGH)
        usleep(pulse)
        GPIO.output(motorPin, GPIO.LOW)
        usleep((period - pulse) + deadband)
        
        
calibrateNEEDED = 500
def motor_calibration():
    for i in range(0,calibrateNEEDED):
        motor_control(1500)
