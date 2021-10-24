//------------------------------------------------------------------------------
// rectangle.cpp - содержит методы прямоугольника
//------------------------------------------------------------------------------

#include "rectangle.h"

//------------------------------------------------------------------------------
// Ввод параметров прямоугольника из файла
void Rectangle::In(ifstream &ifst) {
    ifst >> x_left >> y_left >> x_right >> y_right;
}

// Случайный ввод параметров прямоугольника
void Rectangle::InRnd() {
    x_left = Shape::rnd20.Get();
    y_left = Shape::rnd20.Get();
    int distance_x = Shape::rnd20.Get();
    int distance_y = Shape::rnd20.Get();
    x_right = x_left + distance_x;
    y_right = y_left - distance_y;
}

//------------------------------------------------------------------------------
// Вывод параметров прямоугольника в форматируемый поток
void Rectangle::Out(ofstream &ofst) {
    ofst << "It is Rectangle: x upper left = " << x_left << ", y upper left = " << y_left
         << ", x lower right = " << x_right << ", y lower right =" << y_right
         << ". Perimeter = " << Perimeter() << "\n";
}

//------------------------------------------------------------------------------
// Вычисление периметра прямоугольника
double Rectangle::Perimeter() {
    return 2.0 * (x_right - x_left + y_left - y_left);
}
