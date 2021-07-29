#ifndef LINE_H
#define LINE_H

#include "Shapes.h"
#include <QLine>
//using namespace std;

class Line: public Shape
{
  public:
    Line(int id = -1, ShapeType type = NONE);
    Line();
    ~Line() {}

    //Accessors
    QLine& GetLine();

    //Mutators
    void setLine();

    void draw(QPainter* shape) override;
    void move(int[]) override;
    int area() override { return 0;}
    int perimeter() override { return 0; }

  private:
    QLine line;
    QPoint beginPoint;
    QPoint endPoint;
};

#endif // LINE_H
