import serial

serial_port = serial.Serial(
    port="/dev/ttyS0",
    baudrate=115200,
    bytesize=serial.EIGHTBITS,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
)

def send_command(selection, pulse):
    serial_port.write("{} {} ".format(selection,pulse).encode())

#everything below should be 2% to its max
def forward():
    send_command(2, 1725) #1630
    
def back():
    send_command(2, 1237) #1365
    
def stop():
    send_command(2, 1500)
    
def left():
    send_command(1, 1260) #full sends on the bottom
    
def right():
    send_command(1, 1710)

def straight():
    send_command(1, 1500)
    
def finish():
    stop()
    left()
    right()
    left()
    right()
    straight()
    return True

def toggleSiren():
    send_command(3, 1)