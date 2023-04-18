from time import sleep
from picamera import PiCamera

camera = PiCamera()
camera.resolution = (3280,2464)
camera.rotation = 90
for i in range(5):
    sleep(5)
    camera.capture('/home/pi/Desktop/Images/image%s.jpg' % i)

