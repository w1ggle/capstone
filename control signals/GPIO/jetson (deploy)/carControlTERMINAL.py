#!/usr/bin/env python3
from servoControlPULSE import servo_control
from motorControlPULSE import motor_control, motor_calibration
from pinControl import pin_setup, pin_clean


pin_setup()
motor_calibration()

while True:  #polling; ctrl+C to stop
    pulse = input("Please enter servopulse: ")
    
    try:
        # used try so that if user pressed other than the given key error will not be shown
        motor_control(int(pulse))
        print("pulse!!!")
    except:
        pin_clean()
        break
