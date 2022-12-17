#!/usr/bin/env python3

__author__ = "Stephen D. Sharp"
__version__ = "0.1.0"
__license__ = "N/A"

from datetime import datetime
import serial
import time
import ndvi

def serial_setup():
    global ser
    ser = serial.Serial('/dev/ttyACM0',9600, timeout=1)
    ser.flush()

def current_datetime():
    now = datetime.now()
    current_hour = now.hour
    current_minute = now.minute
    current_second = now.second
    current_year = now.year
    current_month = now.month
    current_day = now.day
    print(now)

def initialize_Fogger():
    pass

def fogger():
    pass
    time_On = 30 #seconds
    time_Off = 30 #minutes
    #next_Trigger =

def pH_Control():
    pass

def nutrient_Dosing():
    pass

def main():
    while True:
        current_datetime()
        fogger()
        pH_Control()
        nutrient_Dosing()

        ser.write(b"on\n")
        print("on")
        time.sleep(3)
        ser.write(b"off\n")
        print("off")
        time.sleep(1)

if __name__ == "__main__":
    serial_setup()
    main()