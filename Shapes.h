#ifndef SHAPES_H
#define SHAPES_H

//general includes
#include <iostream>
#include <iomanip>
#include <string>
//#include "vector.h"

//for Shape class
#include <Qt>
#include <QPainter>
#include <QPaintDevice>
#include <QPen>

//for Text class
#include <QTextEdit>
#include <QString>
#include <QColor>
#include <QFont>

//for Polyline class
#include <QPoint>

//using namespace std;


class Shape
{
    public:
      enum ShapeType {LINE, POLYLINE, POLYGON, RECTANGLE, SQUARE, ELLIPSE, TEXT, CIRCLE, NONE};

      //constructors
      Shape(int id = -1, ShapeType type = NONE);
      Shape();

      //destructor
      virtual ~Shape() {}

      //pure virtual functions
      virtual void draw(QPainter*) = 0;
      virtual void move(int[]) = 0;
      virtual int perimeter() = 0;
      virtual int area() = 0;

      //overloaded operators
      bool operator==(const Shape& rhs) const;
      bool operator<(const Shape& rhs) const;

      //accessors
      const QPen& getPen() const;
      const QBrush& getBrush() const;
      ShapeType getShape() const;
      std::vector<int>& getDimensions();
      QPainter& getPainter();
      int getId();

      //mutators
      void setPen(Qt::GlobalColor);
      void setBrush(Qt::GlobalColor, Qt::BrushStyle);
      void setShape(ShapeType shape);

      //shape properties mutators
      void addDimension(int dim);
      void setColor(const QColor color);
      void setWidth(int width);
      void setStyle(Qt::PenStyle style);
      void setCapStyle(Qt::PenCapStyle capStyle);
      void setJoinStyle(Qt::PenJoinStyle style);
      void setBrushColor(QColor color);
      void setBrushStyle(Qt::BrushStyle style);

      //disabling copy constructor and copy assignment operator
      Shape(const Shape &s) = delete;
      Shape& operator=(const Shape &s) = delete;

    private:
      QPainter qpainter;
      int id;
      ShapeType shape;
      QPen pen;
      QBrush brush;
      std::vector<int> dimensions; //vector of ints
      int index {0}; //defaults to 0
};

#endif // SHAPES_H
