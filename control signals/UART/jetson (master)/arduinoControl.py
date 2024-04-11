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
