#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shapes.h"
#include <QPaintDevice>
//using namespace std;

class Rectangle: public Shape
{
  public:
    Rectangle(int id = -1, ShapeType type = NONE);
    Rectangle();
    ~Rectangle() {};

    bool isSquare(); //checks if shape is square

    void draw(QPainter* shape) override;
    void move(int[]) override;
    int perimeter() override;
    int area() override;

  private:

};

#endif // RECTANGLE_H
