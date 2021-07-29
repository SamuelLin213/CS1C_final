#ifndef POLYLINE_H
#define POLYLINE_H

#include "Shapes.h"
//using namespace std;

class Polyline: public Shape
{
  public:
    Polyline(int id = -1, ShapeType type = NONE);
    Polyline();
    ~Polyline() {}

    void draw(QPainter* shape) override;
    void move(int[]) override;
    int perimeter() override { return 0;}
    int area() override { return 0; }


//    Polyline(QPaintDevice* shape = nullptr, int id = -1, ShapeType type = NONE);
//    ~Polyline();

//    void draw() override;
//    void move(int, int) override;

//    void addPoint(QPoint point);

  private:
    QPoint* points;
    int pointCount;

};
#endif //POLYLINE_H
