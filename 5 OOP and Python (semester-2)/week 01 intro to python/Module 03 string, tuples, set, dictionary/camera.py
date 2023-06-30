import cv2

cam = cv2.VideoCapture(0)

while True:
   fram = cam.read()
   cv2.imshow('read camera',fram)
   cv2.waitkey(1)