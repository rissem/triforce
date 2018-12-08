import serial
from random import random
import time
from flask import Flask
from flask import request

app = Flask(__name__)

ser = serial.Serial('/dev/tty.usbmodem14201', 115200, timeout=1)

@app.route("/")
def hello():
    if request.args.get('msg') == "144": 
        print("DO STUFF " + request.args.get('msg'))
        colors = [str(int(random() * 255)) for i in range(0, 4*3)]
        string = "<" + ",".join(colors) + ">"
        # ser.write(b'<255,255,255,255,255,255,255,255,255,255,255,255>')
        print("WRITING BYTES")
        ser.write(bytes(string, 'utf-8'))
        return "HI"
    return "YO"

