from arduinoControl import send_command

while True:  #polling; ctrl+C to stop
    rawInput = input("Please enter selection and pulse: ")
    selection, pulse = rawInput.split()
    
    try:
        send_command(selection, pulse)
        
    except:
        break
