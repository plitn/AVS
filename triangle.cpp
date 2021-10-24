//------------------------------------------------------------------------------
// triangle.cpp - содержит функции обработки треугольника
//------------------------------------------------------------------------------

#include "triangle.h"
#include "math.h"

//------------------------------------------------------------------------------
// Ввод параметров треугольника из потока
void Triangle::In(ifstream &ifst) {
    ifst >> xa >> ya >> xb >> yb >> xc >> yc;
    bc_len = sqrt(pow(xc - xb, 2) + pow(yc - yb, 2));
    ac_len = sqrt(pow(xa - xc, 2) + pow(ya - yc, 2));
    ab_len = sqrt(pow(xa - xb, 2) + pow(ya - yb, 2));
}

// Случайный ввод параметров треугольника
void Triangle::InRnd() {
    double ab_len, bc_len, ac_len;
    xa =  Shape::rnd20.Get();
    ya =  Shape::rnd20.Get();
    xb =  Shape::rnd20.Get();
    yb =  Shape::rnd20.Get();
    ab_len = sqrt(pow(xa - xb, 2) + pow(ya - yb, 2));
    do {
        yc =  Shape::rnd20.Get();
        xc =  Shape::rnd20.Get();
        bc_len = sqrt(pow(xc - xb, 2) + pow(yc - yb, 2));
        ac_len = sqrt(pow(xa - xc, 2) + pow(ya - yc, 2));
    } while((ab_len >= (bc_len + ac_len))
            || (bc_len >= (ab_len + ac_len))
            || (ac_len >= (ab_len + bc_len)));
}

//------------------------------------------------------------------------------
// Вывод параметров треугольника в поток
void Triangle::Out(ofstream &ofst) {
    ofst << "It is Triangle with coordinates: A = ("
         << xa << ";" << ya << ")"
         << ", B = (" << xb << ";" << yb << ")"
         << ", C = (" << xc << ";" << yc << ")"
         << ". Perimeter = " << Perimeter() << "\n";
}

//------------------------------------------------------------------------------
// Вычисление периметра треугольника
double Triangle::Perimeter() {
    return double(ab_len + bc_len + ac_len);
}
