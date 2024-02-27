#import Jetson.GPIO as GPIO

servoPin = 10
motorPin = 7

def pin_setup():
    #GPIO.setmode(GPIO.BOARD)  #using board numbering
    #GPIO.setup(servoPin, GPIO.OUT) #set pin to output
    #GPIO.setup(motorPin, GPIO.OUT)
    return
    
def pin_clean():
    #GPIO.cleanup()
    return
    
def map_range(x, in_min, in_max, out_min, out_max):
    return (x - in_min) * (out_max - out_min) // (in_max - in_min) + out_min