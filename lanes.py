import cv2
import numpy as np
import matplotlib. pyplot as plt


def funcioncanny(image): #función que convierte la imagen normal en bordes

    gray = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY) #pasa a blanco y negro
    blur = cv2.GaussianBlur(gray, (5, 5), 0) #Difumina en un rango de 5X5
    canny = cv2.Canny(blur, 50, 150)  
    return canny

#def region_interesante(image):
    altura = image.shape[0]
    triangulo = np.array([(200, altura), (1100, altura), (550, 250)])
    mask = np.zeros_like(image)
    cv2.fillPoly(mask, triangulo, 255)
    return mask


image = cv2.imread('test_image.jpg')
lane_image = np.copy(image)
cannyimg = funcioncanny(image)
#cv2.imshow("nombresito", region_interesante(cannyimg))
#cv2.waitKey(0)
plt.imshow(cannyimg) 
plt.show()