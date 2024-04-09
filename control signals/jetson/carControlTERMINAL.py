#import keyboard
from servoControlPULSE import servo_control
#from motorControl import motor_control
from pinControl import pin_setup, pin_clean


pin_setup()

while True:  #polling; ctrl+C to stop
    pulse = input("Please enter servopulse: ")
    
    try:
        # used try so that if user pressed other than the given key error will not be shown
        servo_control(int(pulse))
        
    except:
        pin_clean()
        break
