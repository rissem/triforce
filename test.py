import serial
from random import random
import time

ser = serial.Serial('/dev/tty.usbmodem14201', 115200, timeout=1)

time.sleep(1)
while True:
    time.sleep(0.2)
    colors = [str(int(random() * 255)) for i in range(0, 4*3)]
    # colors = ['0', '0', '255',   '0', '0', '255',    '0', '0', '255',   '0', '0', '255'  ]
    # colors = ['255', '0', '0',   '255', '0', '0',    '255', '0', '0',   '255', '0', '0'  ]
    colors = ['0', '255', '0',   '0', '255', '0',    '0', '255', '0',   '0', '255', '0'  ]
    string = "<" + ",".join(colors) + ">"
    ser.write(bytes(string, 'utf-8'))
    for i in range(1,10):
        print("R" + ser.readline().decode('utf-8'))
