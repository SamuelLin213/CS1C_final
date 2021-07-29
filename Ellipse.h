#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shapes.h"
//using namespace std;

class Ellipse: public Shape
{
  public:
    Ellipse(int id = -1, ShapeType type = NONE);
    Ellipse();

    ~Ellipse() {}

    bool isCircle(); //checks if ellipse is circle

    void draw(QPainter* shape) override;
    void move(int[]) override;
    int perimeter() override;
    int area() override;

//    Ellipse(QPaintDevice* shape = nullptr, int id = -1, ShapeType type = NONE);
//    ~Ellipse();

//    void draw() override;
//    void move(int[]) override;
//    int perimeter() override;
//    int area() override;

  private:
//    int x, y, width, height;

};
#endif //ELLIPSE_H
