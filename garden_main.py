#!/usr/bin/env python3

__author__ = "Stephen D. Sharp"
__version__ = "0.1.0"
__license__ = "N/A"

from datetime import datetime
import time
import RPi.GPIO as GPIO
#import ndvi

#GPIO Setup


#Initialize
start_time = datetime.now()
print("Setup Complete...")

def current_datetime():
    global now
    now = datetime.now()
    current_hour = now.hour
    current_minute = now.minute
    current_second = now.second
    current_year = now.year
    current_month = now.month
    current_day = now.day

def initialize_Fogger():
    pass
    global last_trigger
    last_trigger = start_time.minute

def fogger():
    time_On = 30 #seconds
    time_Off = 30 #minutes
    #next_Trigger = last_trigger + time_Off

def lights():
    GPIO.setmode(GPIO.BCM) 
    pin_Light = 6
    GPIO.setup(pin_Light, GPIO.OUT)
    current_datetime()
    lights_on = 8
    lights_off = 20
    if lights_off > lights_on:
        if now.hour >= lights_on and now.hour <= lights_off:
            #lights on 
            GPIO.output(pin_Light, GPIO.LOW)
        else:
            #lights off
            GPIO.output(pin_Light, GPIO.HIGH)
    else:
        if now.hour >= lights_on or now.hour <= lights_off:
            #lights on
            pass
        else:
            #lights off
            pass

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
        GPIO.cleanup()
        time.sleep(1)

if __name__ == "__main__":
    main()