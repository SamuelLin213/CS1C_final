#include "Line.h"
//using namespace std;

class Line;

//Constructor
Line::Line(int id, ShapeType type)
    :Shape(id, type)
{
}

//Mutators
void Line::setLine()
{
  QPoint p1(getDimensions()[0], getDimensions()[1]);
  QPoint p2(getDimensions()[2], getDimensions()[3]);
  line.setPoints(p1, p2);
}

//Accessors
QLine& Line::GetLine()
{
  return line;
}

//virtual functions
void Line::draw(QPainter* shape)
{
//  QPoint p1(getDimensions()[0], getDimensions()[1]);
//  QPoint p2(getDimensions()[2], getDimensions()[3]);
//  line.setPoints(p1, p2);

  shape->save(); //save original state of qpainter
  shape->setPen(getPen());
  shape->setBrush(getBrush());
  shape->drawLine(line); //draw a line based on previously set points
  shape->restore(); //restore to the original state of qpainter

}

void Line::move(int dims[])
{
    getDimensions()[0] = dims[0];
    getDimensions()[1] = dims[1];
    getDimensions()[2] = dims[2];
    getDimensions()[3] = dims[3];

    this->setLine();
}
