#!/usr/bin/env python3

__author__ = "Stephen D. Sharp"
__version__ = "0.1.0"
__license__ = "N/A"

from datetime import datetime
#import serial
import time
#import ndvi

#Initialize
print("Setup")
start_time = datetime.now()
#ser = serial.Serial('/dev/ttyACM0',9600, timeout=1)
#ser.flush()

def current_datetime():
    global now
    now = datetime.now()
    #current_hour = now.hour
    #current_minute = now.minute
    #current_second = now.second
    #current_year = now.year
    #current_month = now.month
    #current_day = now.day

def initialize_Fogger():
    pass
    global last_trigger
    last_trigger = start_time.minute

def fogger():
    time_On = 30 #seconds
    time_Off = 30 #minutes
    #next_Trigger = last_trigger + time_Off

def lights():
    current_datetime()
    lights_on = 17
    lights_off = 8
    if lights_off > lights_on:
        if now.hour >= lights_on and now.hour <= lights_off:
            print("Lights ON!") 
        else:
            print("Lights OFF!")
    else:
        if now.hour >= lights_on or now.hour <= lights_off:
            print("Lights ON!") 
        else:
            print("Lights OFF!")

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
        lights()
        
        #Time
        print(start_time)
        print(now)

        #ser.write(b"on\n")
        #print("on")
        #time.sleep(3)
        #ser.write(b"off\n")
        #print("off")
        time.sleep(1)

if __name__ == "__main__":
    main()