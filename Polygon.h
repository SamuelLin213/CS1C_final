#ifndef POLYGON_H
#define POLYGON_H

#include "Shapes.h"
//using namespace std;

class Polygon: public Shape
{
  public:
    Polygon(int id = -1, ShapeType type = NONE);
    ~Polygon() {};

    void draw(QPainter* shape) override;
    void move(int[]) override;
    int perimeter() override;
    int area() override;
};

#endif // POLYGON_H
