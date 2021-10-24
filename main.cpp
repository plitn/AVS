//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
#include <cstring>
#include "chrono"
#include "container.h"

void errMessage1() {
    cout << "incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01\n";
}

void errMessage2() {
    cout << "incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01\n";
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    if(argc != 4) {
        errMessage1();
        return 1;
    }
    cout << "Start"<< endl;
    Container c;
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << 0;
    if(!strcmp(argv[1], "-f")) {
        ifstream ifst(argv[2]);
        c.In(ifst);
    }
    else if(!strcmp(argv[1], "-n")) {
        int size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) {
            cout << "incorrect numer of figures = "
                 << size
                 << ". Set 0 < number <= 10000\n";
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        c.InRnd(size);
    }
    else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл
    ofstream ofst1(argv[3]);
    ofst1 << "Filled container:\n";
    c.SortCont();
    cout << "Sorted" << endl;
    c.Out(ofst1);
    c.~Container();
    cout << "Stop"<< endl;
    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << (std::chrono::duration_cast<std::chrono::microseconds>(finish - start)).count();
    return 0;
}
