//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"
//------------------------------------------------------------------------------
// Инициализация контейнера
void Init(container &c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void In(container &c, ifstream &ifst) {
    while(!ifst.eof()) {
        if(In(c.cont[c.len], ifst)) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void InRnd(container &c, int size) {
    while(c.len < size) {
        if(InRnd(c.cont[c.len])) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Out(container &c, ofstream &ofst) {
    ofst << "Container contains " << c.len << " elements." << endl;
    for(int i = 0; i < c.len; i++) {
        ofst << i << ": ";
        Out(c.cont[i], ofst);
    }
}

void SortCont(container &c) {
    int control = c.len - 1;
    int left = 0;
    int right = c.len - 1;
    do {
        for (int i = left; i < right; ++i) {
            if (Perimeter(c.cont[i]) > Perimeter(c.cont[i + 1])) {
                shape temp = c.cont[i];
                c.cont[i] = c.cont[i + 1];
                c.cont[i + 1] = temp;
                control = i;
            }
        }
        right = control;
        for (int i = right; i > left ; i--) {
            if (Perimeter(c.cont[i]) < Perimeter(c.cont[i - 1])) {
                shape temp = c.cont[i];
                c.cont[i] = c.cont[i - 1];
                c.cont[i - 1] = temp;
                control = i;
            }
        }
        left = control;
    } while (left < right);
}
