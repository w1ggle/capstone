import keyboard
from servoControl import servo_control
from motorControl import motor_control
from pinControl import pin_setup, pin_clean


pin_setup()

while True:  #polling; ctrl+C to stop
    try:  # used try so that if user pressed other than the given key error will not be shown
        if keyboard.is_pressed('w'): 
            motor_control(100)
        elif keyboard.is_pressed('s'):
            motor_control(-100)
        elif keyboard.is_pressed('a'):
            servo_control(-100)
        elif keyboard.is_pressed('d'):
            servo_control(100)
        
    except:
        pin_clean()
        break