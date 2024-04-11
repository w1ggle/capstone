#!/usr/bin/env python3
import keyboard
import arduinoControl as ac

pin_setup()

while True:  #polling; ctrl+C to stop

    try:  # used try so that if user pressed other than the given key error will not be shown
        if keyboard.is_pressed('w'): 
            ac.forward()
        elif keyboard.is_pressed('s'):
            ac.back()
        elif keyboard.is_pressed('a'):
            ac.left()
        elif keyboard.is_pressed('d'):
            ac.right()
        
    except:
        break
