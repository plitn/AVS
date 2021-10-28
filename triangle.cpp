//------------------------------------------------------------------------------
// triangle.cpp - содержит функции обработки треугольника
//------------------------------------------------------------------------------

#include "triangle.h"
#include "math.h"

//------------------------------------------------------------------------------
// Ввод параметров треугольника из потока
void In(triangle &t, ifstream &ifst) {
    ifst >> t.xa >> t.ya >> t.xb >> t.yb >> t.xc >> t.yc;
    t.bc_len = sqrt(pow(t.xc - t.xb, 2) + pow(t.yc - t.yb, 2));
    t.ac_len = sqrt(pow(t.xa - t.xc, 2) + pow(t.ya - t.yc, 2));
    t.ab_len = sqrt(pow(t.xa - t.xb, 2) + pow(t.ya - t.yb, 2));
}

// Случайный ввод параметров треугольника
void InRnd(triangle &t) {
    double ab_len, bc_len, ac_len;
    t.xa = Random();
    t.ya = Random();
    t.xb = Random();
    t.yb = Random();
    t.ab_len = sqrt(pow(t.xa - t.xb, 2) + pow(t.ya - t.yb, 2));
    do {
        t.yc = Random();
        t.xc = Random();
        t.bc_len = sqrt(pow(t.xc - t.xb, 2) + pow(t.yc - t.yb, 2));
        t.ac_len = sqrt(pow(t.xa - t.xc, 2) + pow(t.ya - t.yc, 2));
    } while((t.ab_len >= (t.bc_len + t.ac_len))
            && (t.bc_len >= (t.ab_len + t.ac_len))
            && (t.ac_len >= (t.ab_len + t.bc_len)));
}

//------------------------------------------------------------------------------
// Вывод параметров треугольника в поток
void Out(triangle &t, ofstream &ofst) {
    ofst << "It is Triangle with coordinates: A = ("
         << t.xa << ";" << t.ya << ")"
         << ", B = (" << t.xb << ";" << t.yb << ")"
         << ", C = (" << t.xc << ";" << t.yc << ")"
         << ". Perimeter = " << Perimeter(t) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление периметра треугольника
double Perimeter(triangle &t) {
    return double(t.ab_len + t.ab_len + t.bc_len);
}
