import math
import random

from shape import *


# ----------------------------------------------
class Triangle(Shape):
    def __init__(self):
        self.xa = 0
        self.ya = 0
        self.xb = 0
        self.yb = 0
        self.xc = 0
        self.yc = 0
        self.bc_len = math.sqrt(pow(self.xc - self.xb, 2) + pow(self.yc - self.yb, 2))
        self.ac_len = math.sqrt(pow(self.xa - self.xc, 2) + pow(self.ya - self.yc, 2))
        self.ab_len = math.sqrt(pow(self.xa - self.xb, 2) + pow(self.ya - self.yb, 2))

    def ReadStrArray(self, strArray, i):
        # должно быт как минимум 6 непрочитанных значения в массиве
        if i >= len(strArray) - 5:
            return 0
        self.xa = int(strArray[i])
        self.ya = int(strArray[i + 1])
        self.xb = int(strArray[i + 2])
        self.yb = int(strArray[i + 3])
        self.xc = int(strArray[i + 4])
        self.yc = int(strArray[i + 5])
        i += 6
        return i

    def Print(self):
        print("Triangle: a = (", self.xa, ";", self.ya, ") b = (", self.xb, ";", self.yb, ") c = (", self.xc, ";", self.yc, "), Perimeter = ",
              self.Perimeter())
        pass

    def Write(self, ostream):
        ostream.write("Triangle: a = ({};{})  b = ({};{})  c = ({};{}), Perimeter = {}"
                      .format(self.xa, self.ya, self.xb, self.yb, self.xc, self.yc, self.Perimeter()))
        pass

    def Perimeter(self):
        return float(self.ab_len + self.bc_len + self.ac_len)
        pass

    def FillRdn(self):
        self.xa = random.randint(1, 20)
        self.ya = random.randint(1, 20)
        self.xb = random.randint(1, 20)
        self.yb = random.randint(1, 20)
        self.ab_len = math.sqrt(pow(self.xa - self.xb, 2) + pow(self.ya - self.yb, 2))
        self.yc = random.randint(1, 20)
        self.xc = random.randint(1, 20)
        self.bc_len = math.sqrt(pow(self.xc - self.xb, 2) + pow(self.yc - self.yb, 2))
        self.ac_len = math.sqrt(pow(self.xa - self.xc, 2) + pow(self.ya - self.yc, 2))
        while (self.ab_len >= (self.bc_len + self.ac_len)) and (self.bc_len >= (self.ab_len + self.ac_len)) and (self.ac_len >= (self.ab_len + self.bc_len)):
            self.yc = random.randint(1, 20)
            self.xc = random.randint(1, 20)
        pass

