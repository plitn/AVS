import random

from shape import *


# ----------------------------------------------
class Rectangle(Shape):
    def __init__(self):
        self.x_left = 0
        self.y_left = 0
        self.x_right = 0
        self.y_right = 0

    def ReadStrArray(self, strArray, i):
        # должно быт как минимум 4 непрочитанных значения в массиве
        if i >= len(strArray) - 3:
            return 0
        self.x_left = int(strArray[i])
        self.y_left = int(strArray[i + 1])
        self.x_right = int(strArray[i + 2])
        self.y_right = int(strArray[i + 3])
        i += 4
        # print("Rectangle: x = ", self.x, " y = ", self.y)
        return i

    def Print(self):
        print("Rectangle: x upper left = ", self.x_left, " y upper left = ", self.y_left, " x lower right = ",
              self.x_right, " y lower right =", self.y_right, ", Perimeter = ", self.Perimeter())
        pass

    def Write(self, ostream):
        ostream.write("Rectangle: x upper left = {}  y upper left= {} "
                      "x lower right = {} y lower right = {}, Perimeter = {}"
                      .format(self.x_left, self.y_left, self.x_right, self.y_right, self.Perimeter()))
        pass

    def Perimeter(self):
        return 2.0 * (self.x_right - self.x_left + self.y_left - self.y_left)
        pass

    def FillRdn(self):
        self.x_left = random.randint(0, 20)
        self.x_left = random.randint(0, 20)
        distance_x = random.randint(0, 20)
        distance_y = random.randint(0, 20)
        self.x_right = self.x_left + distance_x
        self.y_right = self.y_left - distance_y
        pass
