from time import sleep
from picamera import PiCamera

camera = PiCamera()
camera.resolution = (3280,2464)
camera.rotation = 90
for i in range(5):
    sleep(1)
    camera.capture('/home/pi/GardenOS/Images/image%s.jpg' % i)

