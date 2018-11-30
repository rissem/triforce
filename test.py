import serial
from random import random
import time

ser = serial.Serial('/dev/tty.usbmodem14201', 115200, timeout=1)

time.sleep(1)

ser.write(b'<255,255,255,255,255,255,255,255,255,255,255,255>')

for i in range(1,10):
    print("R" + ser.readline().decode('utf-8'))

time.sleep(5)

# ser.close()

while True:
    time.sleep(0.2)
    colors = [str(int(random() * 255)) for i in range(0, 4*3)]
    string = "<" + ",".join(colors) + ">"
    ser.write(bytes(string, 'utf-8'))

ser.close()