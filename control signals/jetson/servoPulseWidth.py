import Jetson.GPIO as GPIO
import time

# Pin Definitions
output_pin = 10 #BOARD pin 10

frequency = 50 #in hertz (50 to 200?)
pulseMin = 500 #in microseconds
pulseMax = 2500 #in microseconds
angleMin = 0 #in degrees
angleMax = 270 #in degrees

def map_range(x, in_min, in_max, out_min, out_max):
  return (x - in_min) * (out_max - out_min) // (in_max - in_min) + out_min

def main():
    # Setup:
    GPIO.setmode(GPIO.BOARD)  #using board numbering
    GPIO.setup(output_pin, GPIO.OUT) #set pin to output
    period = 1.0/frequency * 1000000; #convert to microseconds

    
    print("Starting demo now! Press CTRL+C to exit")
    try:
        angle = angleMin
        while angle < angleMax:
            
            print("Outputting {} to pin {}".format(angle, output_pin))
            
            pulse = map_range(angle, angleMin, angleMax, pulseMin, pulseMax);
            GPIO.output(output_pin, GPIO.HIGH)
            time.sleep(pulse/1000000.0)
            GPIO.output(output_pin, GPIO.LOW)
            time.sleep((period - pulse)/1000000.0)
            
            angle += 1
            
            if angle == angleMax:
                angle = angleMin


    
    finally:
        GPIO.cleanup()



if __name__ == '__main__':
    main()