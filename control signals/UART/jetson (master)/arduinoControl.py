import serial

serial_port = serial.Serial(
    port="/dev/ttyS0",
    baudrate=9600,
    bytesize=serial.EIGHTBITS,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
)

def send_command(selection, pulse):
    serial_port.write("{} {} ".format(selection,pulse).encode()) #do i need encode?

#everything below should be 50% to its max
def forward():
    send_command(2, 1725)
    
def back():
    send_command(2, 1237)
    
def stop():
    send_command(2, 1500)
    
def left():
    send_command(1, 1298)
    
def right():
    send_command(1, 1513)

def straight():
    send_command(1, 1430)
    
def finish():
    stop()
    left()
    right()
    left()
    right()
    straight()
    return True