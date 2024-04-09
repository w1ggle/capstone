#import Jetson.GPIO as GPIO
import time

servoPin = 26
motorPin = 6

def pin_setup():
    #GPIO.setmode(GPIO.BCM)  #using bcm numbering
    #GPIO.setup(servoPin, GPIO.OUT, initial=GPIO.LOW) #set pin to output
    #GPIO.setup(motorPin, GPIO.OUT, initial=GPIO.LOW )
    return
    
def pin_clean():
    #GPIO.cleanup()
    return
    
def map_range(x, in_min, in_max, out_min, out_max):
    return (x - in_min) * (out_max - out_min) // (in_max - in_min) + out_min

def usleep(x):
    return time.sleep(x/1000000.0)
