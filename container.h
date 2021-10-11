#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------
#include "shape.h"
//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
struct container {
    enum {max_len = 10000}; // максимальная длина
    int len; // текущая длина
    shape cont[max_len];
};

// Инициализация контейнера
void Init(container &c);

// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c);

// Ввод содержимого контейнера из указанного потока
void In(container &c, ifstream &ifst);

// Случайный ввод содержимого контейнера
void InRnd(container &c, int size);

// Вывод содержимого контейнера в указанный поток
void Out(container &c, ofstream &ofst);

// Вычисление суммы периметров всех фигур в контейнере
//double PerimeterSum(container &c);

// Shaker sort
void SortCont(container &c);

#endif
