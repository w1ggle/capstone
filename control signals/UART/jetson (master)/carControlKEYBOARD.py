#!/usr/bin/env python3
import keyboard
from modules import arduinoControl as ac


while True:  #polling; ctrl+C to stop

    try:  # used try so that if user pressed other than the given key error will not be shown
        if keyboard.is_pressed('i'): 
            ac.forward()
        elif keyboard.is_pressed('k'):
            ac.back()
        elif keyboard.is_pressed('a'):
            ac.left()
        elif keyboard.is_pressed('s'):
            ac.straight()
        elif keyboard.is_pressed('d'):
            ac.right()
        else:
            ac.stop()
            
    except:
        break
