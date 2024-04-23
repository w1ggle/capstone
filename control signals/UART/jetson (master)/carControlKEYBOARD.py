import keyboard
#from modules import arduinoControl as ac

#interrupts
keyboard.on_press_key('space', lambda x: print("siren"))
keyboard.on_press_key('a', lambda x: print("left"))
keyboard.on_press_key('s', lambda x: print("straight"))
keyboard.on_press_key('d', lambda x: print("right"))


while True:  #polling; ctrl+C to stop

    try:  # used try so that if user pressed other than the given key error will not be shown

        if keyboard.is_pressed('i'): 
            print("forward")#ac.forward()
        elif keyboard.is_pressed('k'):
            print("back")#ac.back()
        else:
           print("stop")#ac.stop()
           keyboard.read_event() #less taxing bc we block here
            
    except:
        break