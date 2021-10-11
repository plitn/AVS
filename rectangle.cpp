//------------------------------------------------------------------------------
// rectangle_In.cpp - содержит процедуру ввода параметров
// для уже созданного прямоугольника
//------------------------------------------------------------------------------

#include "rectangle.h"

//------------------------------------------------------------------------------
// Ввод параметров прямоугольника из файла
void In(rectangle &r, ifstream &ifst) {
    ifst >> r.x_left >> r.y_left >> r.x_right >> r.y_right;
}

// Случайный ввод параметров прямоугольника
void InRnd(rectangle &r) {
    r.x_left = Random();
    r.y_left = Random();
    int distance_x = Random();
    int distance_y = Random();
    r.x_right = r.x_left + distance_x;
    r.y_right = r.y_left - distance_y;
}

//------------------------------------------------------------------------------
// Вывод параметров прямоугольника в форматируемый поток
void Out(rectangle &r, ofstream &ofst) {
    ofst << "It is Rectangle: x upper left = " << r.x_left << ", y upper left = " << r.y_left
        << ", x lower right = " << r.x_right << ", y lower right =" << r.y_right
         << ". Perimeter = " << Perimeter(r) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление периметра прямоугольника
double Perimeter(rectangle &r) {
    return 2.0 * (r.x_right - r.x_left + r.y_left - r.y_left);
}
