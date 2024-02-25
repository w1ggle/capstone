import Jetson.GPIO as GPIO
import time

# Pin Definitions
output_pin = 7 #BOARD pin 7

frequency = 1000 #in hertz (1k to 16k?)
pulseMin = 500 #in microseconds
pulseMax = 2500 #in microseconds
speedMin = -100 #in degrees
speedMax = 100 #in degrees

def map_range(x, in_min, in_max, out_min, out_max):
  return (x - in_min) * (out_max - out_min) // (in_max - in_min) + out_min

def main():
    # Setup:
    GPIO.setmode(GPIO.BOARD)  #using board numbering
    GPIO.setup(output_pin, GPIO.OUT) #set pin to output
    period = 1.0/frequency * 1000000; #convert to microseconds

    
    print("Starting demo now! Press CTRL+C to exit")
    try:
        pulse = 0
        while pulse < pulseMax:
            speed = map_range(pulse, pulseMin, pulseMax, speedMin, speedMax);
            print("Outputting {} to pin {}".format(speed, output_pin))
            GPIO.output(output_pin, GPIO.HIGH)
            time.sleep(pulse/1000000.0)
            GPIO.output(output_pin, GPIO.LOW)
            time.sleep((period - pulse)/1000000.0)
            pulse += 1

    
    finally:
        GPIO.cleanup()



if __name__ == '__main__':
    main()