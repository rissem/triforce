import serial
from random import random
import time
from flask import Flask
from flask_cors import CORS
from flask import request
from music21 import chord

app = Flask(__name__)
CORS(app)

ser = serial.Serial('/dev/tty.usbmodem14201', 115200, timeout=1)

@app.route("/")
def hello():
    note_nums = [int(x) for x in request.args.get("notes").split("_")]

    colors = [str(int(random() * 255)) for i in range(0, 4*3)]
    string = "<" + ",".join(colors) + ">"
    # ser.write(b'<255,255,255,255,255,255,255,255,255,255,255,255>')

    if 'triangle' in request.args:
        print("WRITING BYTES")
        ser.write(bytes(string, 'utf-8'))
    result = chord.Chord(note_nums)

    return result.root().name + " " + result.commonName, 200
