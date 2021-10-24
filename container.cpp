//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Конструктор контейнера
Container::Container(): len{0} { }

//------------------------------------------------------------------------------
// Деструктор контейнера
Container::~Container() {
    Clear();
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Container::Clear() {
    for(int i = 0; i < len; i++) {
        delete storage[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void Container::In(ifstream &ifst) {
    while(!ifst.eof()) {
        if((storage[len] = Shape::StaticIn(ifst)) != 0) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void Container::InRnd(int size) {
    while(len < size) {
        if((storage[len] = Shape::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Container::Out(ofstream &ofst) {
    ofst << "Container contains " << len << " elements.\n";
    for(int i = 0; i < len; i++) {
        ofst << i << ": ";
        storage[i]->Out(ofst);
    }
}

void Container::SortCont() {
    int control = len - 1;
    int left = 0;
    int right = len - 1;
    do {
        for (int i = left; i < right; ++i) {
            if (storage[i]->Perimeter() > storage[i + 1]->Perimeter()) {
                auto temp = storage[i];
                storage[i] = storage[i + 1];
                storage[i + 1] = temp;
                control = i;
            }
        }
        right = control;
        for (int i = right; i > left; i--) {
            if (storage[i]->Perimeter() < storage[i - 1]->Perimeter()) {
                auto temp = storage[i];
                storage[i] = storage[i - 1];
                storage[i - 1] = temp;
                control = i;
            }
        }
        left = control;
    } while (left < right);
}
