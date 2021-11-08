import random
import sys
import string
import time

from extender import *

# ----------------------------------------------
if __name__ == '__main__':
    container = Container()
    start = time.time()
    isFile = False;
    print(sys.argv[2])
    if len(sys.argv) == 3 and sys.argv[1] != "-r":
        inputFileName = sys.argv[1]
        outputFileName = sys.argv[2]
        isFile = True;
    elif len(sys.argv) == 2:
        inputFileName = sys.argv[1]
        outputFileName = "output.txt"
        isFile = True;
    elif len(sys.argv) == 1:
        print("Incorrect command line! You must write: python main <inputFileName> [<outputFileName>]\nOr python main -r number <outputFileName>")
        exit()
    elif len(sys.argv) == 4 and sys.argv[1] == "-r":
        container.RandomGen(int(sys.argv[2]))
        outputFileName = sys.argv[3]
    elif len(sys.argv) == 3 and sys.argv[1] == "-r":
        container.RandomGen(int(sys.argv[2]))
        outputFileName = "output.txt"
    # Чтение исходного файла, содержащего данные, разделенные пробелами и переводами строки
    if isFile:
        ifile = open(inputFileName)
        str = ifile.read()
        ifile.close()

    # Формирование массива строк, содержащего чистые данные в виде массива строк символов.
        strArray = str.replace("\n", " ").split(" ")

        print('==> Start')

        figNum = ReadStrArray(container, strArray)
    container.ShakerSort()
    print('==> Sorted')
    ofile = open(outputFileName, 'w')
    container.Write(ofile)
    ofile.close()

    print('==> Finish')
    print('Work time: ', time.time() - start)
