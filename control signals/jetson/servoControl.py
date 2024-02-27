#import Jetson.GPIO as GPIO
import time

# Definitions
output_pin = 10 #BOARD pin 10
frequency = 50 #in hertz (50 to 200?)
pulseMin = 1200 #in microseconds
pulseMax = 1610 #in microseconds
angleMin = -100 #in degrees   THESE DONT HAVE TO BE ACCURATE, THEYRE JUST FOR INPUT FEEDBACK
angleMax = 100 #in degrees
period = 1.0/frequency * 1000000 #convert to microseconds
angle = period = 0
MAX_ITERATIONS = 2 #depends on hardware
ITERATION_DELAY = 0


def map_range(x, in_min, in_max, out_min, out_max):
  return (x - in_min) * (out_max - out_min) // (in_max - in_min) + out_min

def pin_setup():
    print()
    #GPIO.setmode(GPIO.BOARD)  #using board numbering
    #GPIO.setup(output_pin, GPIO.OUT) #set pin to output
    
def servo_control(angle):
    #pin_setup()
    
    #try:
    if(angle < angleMin): #keep input in range
        angle = angleMin
    elif (angle > angleMax):
        angle = angleMax
        
    print("Angle: " + str(angle))
    pulse = map_range(angle, angleMin, angleMax, pulseMin, pulseMax)
    
    for i in range(0, MAX_ITERATIONS): #setting it, may take multiple pulses, with delays in between, need to test on hardware
        #GPIO.output(output_pin, GPIO.HIGH)
        print(i)
        print("HIGH")
        time.sleep(pulse/1000000.0)
        print("LOW")
        # #GPIO.output(output_pin, GPIO.LOW)
        time.sleep((period - pulse)/1000000.0)
        time.sleep(ITERATION_DELAY)
    
    return 10
#    except:
 #       print("nothing")
             
    #finally:
    #    break
#    GPIO.cleanup()