#ifndef __triangle__
#define __triangle__

//------------------------------------------------------------------------------
// triangle.h - содержит описание треугольника
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"

//------------------------------------------------------------------------------
// треугольник
struct triangle {
    int xa, ya, xb, yb, xc, yc; // координаты углов
    double ab_len, bc_len, ac_len;
};

// Ввод параметров треугольника из файла
void In(triangle &t, ifstream &ifst);

// Случайный ввод параметров треугольника
void InRnd(triangle &t);

// Вывод параметров треугольника в форматируемый поток
void Out(triangle &t, ofstream &ofst);

// Вычисление периметра треугольника
double Perimeter(triangle &t);

#endif //__triangle__
