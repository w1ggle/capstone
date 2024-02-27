import keyboard  # using module keyboard
from servoControl import servo_control

while True:  # making a loop
    try:  # used try so that if user pressed other than the given key error will not be shown
        if keyboard.is_pressed('w'):  # if key 'q' is pressed 
            print('You Pressed w!')
        elif keyboard.is_pressed('s'):
            print('You Pressed s!')
        elif keyboard.is_pressed('a'):
            servo_control(-100)
        elif keyboard.is_pressed('d'):
            servo_control(100)
            print("HELLO")
        
          
    except:
        break