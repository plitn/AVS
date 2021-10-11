#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// shape.h - содержит описание обобщающей геометрической фигуры,
//------------------------------------------------------------------------------

#include "rectangle.h"
#include "triangle.h"
#include "circle.h"

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся фигуры
struct shape {
    // значения ключей для каждой из фигур
    enum key {RECTANGLE, TRIANGLE, CIRCLE};
    key k; // ключ
    // используемые альтернативы
    union { // используем простейшую реализацию
        rectangle r;
        triangle t;
        circle c;
    };
    enum color {red, orange, yellow, green, blue, dark_blue, purple};
};

// Ввод обобщенной фигуры
bool In(shape &s, ifstream &ifdt);

// Случайный ввод обобщенной фигуры
bool InRnd(shape &s);

// Вывод обобщенной фигуры
void Out(shape &s, ofstream &ofst);

// Вычисление периметра обобщенной фигуры
double Perimeter(shape &s);

#endif
