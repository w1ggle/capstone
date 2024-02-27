#import Jetson.GPIO as GPIO
import time
from pinControl import servoPin, map_range

# Definitions
frequency = 50 #in hertz (50 to 200?)
pulseMin = 1200 #in microseconds
pulseMax = 1610 #in microseconds
angleMin = -100 #in degrees   THESE DONT HAVE TO BE ACCURATE, THEYRE JUST FOR INPUT FEEDBACK
angleMax = 100 #in degrees
period = 1.0 / frequency #convert to microseconds
MAX_ITERATIONS = 1 #depends on hardware
ITERATION_DELAY = 0
    
def servo_control(angle):
    
    if(angle < angleMin): #keep input in range
        angle = angleMin
    elif (angle > angleMax):
        angle = angleMax
        
    print("Angle: " + str(angle))
    pulse = map_range(angle, angleMin, angleMax, pulseMin, pulseMax) / 1000000.0 #convert to seconds
    
    for i in range(0, MAX_ITERATIONS): #setting it, may take multiple pulses, with delays in between, need to test on hardware
        #GPIO.output(servoPin, GPIO.HIGH)
        time.sleep(pulse)
        #GPIO.output(servoPin, GPIO.LOW)
        time.sleep(period - pulse)
        time.sleep(ITERATION_DELAY)