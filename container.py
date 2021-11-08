#----------------------------------------------
import random
from extender import *

class Container:
    def __init__(self):
        self.store = []

    #def ReadStrArray(self, strArray):

    def Print(self):
        print("Container is store", len(self.store), "shapes:")
        for shape in self.store:
            shape.Print()
        pass

    def Write(self, ostream):
        ostream.write("Container is store {} shapes:\n".format(len(self.store)))
        for shape in self.store:
            shape.Write(ostream)
            ostream.write("\n")
        pass

    def ShakerSort(self):
        def swap(i, j):
            self.store[i], self.store[j] = self.store[j], self.store[i]
        control = len(self.store)
        left = 0
        right = len(self.store) - 1
        no_swap = False
        while not no_swap and right - left > 1:
            no_swap = True
            for j in range(left, right):
                if self.store[j + 1].Perimeter() < self.store[j].Perimeter():
                    swap(j + 1, j)
                    no_swap = False
            right -= 1
            for j in range(right, left, -1):
                if self.store[j - 1].Perimeter() > self.store[j].Perimeter():
                    swap(j - 1, j)
                    no_swap = False
            left += 1

    def RandomGen(self, num):
        while num != 0:
            k = random.randint(1, 4)
            if k == 1:
                shape = Rectangle()
                shape.FillRdn()
                self.store.append(shape)
            if k == 2:
                shape = Triangle()
                shape.FillRdn()
                self.store.append(shape)
            if k == 3:
                shape = Circle()
                shape.FillRdn()
                self.store.append(shape)
            num -= 1
