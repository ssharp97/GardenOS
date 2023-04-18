import serial
YpulseCalc = 200

serial1 = serial.Serial('/dev/ttyACM0', 9600)
serial1.flush()
YpulseCalc = bytearray(YpulseCalc)

while True:
    serial1.write(YpulseCalc)
    print(YpulseCalc)