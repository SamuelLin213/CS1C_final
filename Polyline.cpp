#include "Polyline.h"
//using namespace std;

class Polyline;

Polyline::Polyline(int id, ShapeType type)
    :Shape(id, type)
{
}

void Polyline::draw(QPainter* shape)
{
    QVector<QPoint> points;
    for(int x = 0; x < int(getDimensions().size()); x+=2)
    {
        points.push_back(QPoint(getDimensions()[x], getDimensions()[x+1]));
    }

    shape->save(); //save original state of qpainter

    shape->setPen(getPen());
    shape->setBrush(getBrush());

    shape->drawPolyline(points);

    shape->restore(); //restore to the original state of qpainter
}
void Polyline::move(int dims_[])
{
    int elementNum = getDimensions().size();
    for(int i = 0; i < elementNum; i++)
    {
        getDimensions()[i] = dims_[i];
    }
}

//class Polyline;

//Polyline::Polyline(QPaintDevice* shape, int id, ShapeType type)
//:Shape(shape, id, type, 4)
//{
// points = nullptr;
// pointCount = 0;
//}
//Polyline::~Polyline()
//{
// delete points;
//}

//void Polyline::draw()
//{
//  GetPainter().save(); //save original state of qpainter
//  GetPainter().setPen(GetPen());
//  GetPainter().setBrush(GetBrush());
//  GetPainter().drawPolyline(points, pointCount); //draw a line based on previously set points
//  GetPainter().restore(); //restore to the original state of qpainter
//}

////moves the TOP(most recent) point in the STACK of points
//void Polyline::move(int x, int y)
//{
//  points.setX(x);
//  points.setY(y);
//}

////polyline points added as a STACK
//void Polyline::addPoint(QPoint point)
//{
//  if(points = nullptr) {points = point;}
//  else
//  {
//    QPoint* temp = new QPoint*;
//    temp = points;
//    points = point;
//    points->next = temp;
//    delete temp;
//  }
//  pointCount++;
//}
