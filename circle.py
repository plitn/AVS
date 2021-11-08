import math
import random

from shape import *


# ----------------------------------------------
class Circle(Shape):
    def __init__(self):
        self.x = 0
        self.y = 0
        self.r = 0

    def ReadStrArray(self, strArray, i):
        # должно быт как минимум 3 непрочитанных значения в массиве
        if i >= len(strArray) - 2:
            return 0
        self.x = int(strArray[i])
        self.y = int(strArray[i + 1])
        self.r = int(strArray[i + 2])
        i += 3
        return i

    def Print(self):
        print("Circle: x = ", self.x, " y = ", self.y, "radius = ", self.r, ", Perimeter = ", self.Perimeter())
        pass

    def Write(self, ostream):
        ostream.write(
            "Circle: x = {}  y = {}  radius = {}, Perimeter = {}".format(self.x, self.y, self.r, self.Perimeter()))
        pass

    def Perimeter(self):
        return float(2 * math.pi * self.r)
        pass

    def FillRdn(self):
        self.x = random.randint(1, 20)
        self.y = random.randint(1, 20)
        self.r = random.randint(1, 20)
