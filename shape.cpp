//------------------------------------------------------------------------------
// shape.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольной фигуры
//------------------------------------------------------------------------------

#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include "shape.h"

//------------------------------------------------------------------------------
Random Shape::rnd20(1, 20);
Random Shape::rnd2(1,2);

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
Shape* Shape::StaticIn(ifstream &ifst) {
    int k;
    ifst >> k;
    Shape* sp = nullptr;
    switch(k) {
        case 1:
            sp = new Rectangle;
            break;
        case 2:
            sp = new Triangle;
            break;
        case 3:
            sp = new Circle;
            break;
    }
    sp->In(ifst);
    return sp;
}

// Случайный ввод обобщенной фигуры
Shape *Shape::StaticInRnd() {
    auto k = Shape::rnd2.Get();
    Shape* sp = nullptr;
    switch(k) {
        case 1:
            sp = new Rectangle;
            break;
        case 2:
            sp = new Triangle;
            break;
        case 3:
            sp = new Circle;
            break;
    }
    sp->InRnd();
    return sp;
}
