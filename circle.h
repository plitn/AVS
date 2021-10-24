#ifndef __circle__
#define __circle__

//------------------------------------------------------------------------------
// circle.h - содержит описание круга  и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"
#include "shape.h"

// прямоугольник
class Circle: public Shape {
public:
    virtual ~Circle() {}
    // Ввод параметров прямоугольника из файла
    virtual void In(ifstream &ifst);
    // Случайный ввод параметров прямоугольника
    virtual void InRnd();
    // Вывод параметров прямоугольника в форматируемый поток
    virtual void Out(ofstream &ofst);
    // Вычисление периметра прямоугольника
    virtual double Perimeter();
private:
    int x, y; // координаты левого верхнего
    int r; // координаты правого нижнего
};

#endif //__circle__
