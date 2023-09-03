import cv2   #include opencv library functions in python
import numpy as np
import time
#Create an object to hold reference to camera video capturing
while(True):
    vidcap = cv2.VideoCapture(1)
    #check if connection with camera is successfully
    if vidcap.isOpened():
        ret, frame = vidcap.read()  #capture a frame from live video

        #check whether frame is successfully captured
        if ret:
            # continue to display window until 'q' is pressed
            while(True):
                  #show captured frame







                lane_image = np.copy(frame)
                gray = cv2.cvtColor(lane_image, cv2.COLOR_RGB2GRAY)
                blur = cv2.GaussianBlur(gray, (1, 1), 0)
                canny = cv2.Canny(blur, 50, 150)
                cv2.imshow('tonto quien lo lea y no diga que lo ha leido', canny)
                time.sleep(0)






                
                break

        #print error if frame capturing was unsuccessful
        else:
            print("Error : Failed to capture frame")

    # print error if the connection with camera is unsuccessful
    else:
        print("Cannot open camera")
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
