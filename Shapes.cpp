#include "Shapes.h"
//using namespace std;

class Shape;

// **Constructor**
Shape::Shape(int id, ShapeType type)
  :id{id}, shape{type}
{
  //qpainter = shape;
  pen = Qt::SolidLine;
  brush = Qt::NoBrush;
//  dimensions = ;
  qpainter.setPen(pen);
  qpainter.setBrush(brush);
}

// **Pure virtual functions** - can't be implemented, since they're purely virtual, will transition to derived classes
//virtual void draw()
//{
//  GetQPainter().save(); //save original state of qpainter
//  GetQPainter().setPen(GetPen());
//  GetQPainter.setBrush(GetBrush());
//  GetQPainter.drawRect(0,0,10,5);
//  GetQPainter().restore(); //restore to the original state of qpainter
//}
//virtual void move()
//{
//  qpainter.save(); //save original state of qpainter
//  //qpainter.
//  qpainter.restore(); //restore to the original state of qpainter
//}
//virtual void perimeter() = 0;
//virtual void area() = 0;


//Accessors
QPainter& Shape::getPainter()
{
    return qpainter;
}

std::vector<int>& Shape::getDimensions()
{
    return dimensions;
}

Shape::ShapeType Shape::getShape() const
{
  return shape;
}

const QPen& Shape::getPen() const
{
  return pen;
}

const QBrush& Shape::getBrush() const
{
  return brush;
}
int Shape::getId()
{
    return id;
}

//Modifiers
void Shape::setPen(Qt::GlobalColor newColor)
{
  pen = QPen(newColor);
  qpainter.setPen(pen);
}

void Shape::setBrush(Qt::GlobalColor newColor, Qt::BrushStyle newStyle)
{
  brush = QBrush(newColor, newStyle);
  qpainter.setBrush(brush);
}

void Shape::setShape(ShapeType shape)
{
  this->shape = shape;
}

void Shape::addDimension(int dim)
{
    dimensions.push_back(dim);
}
void Shape::setColor(QColor color)
{
    pen.setColor(color);
}
void Shape::setWidth(int width)
{
    pen.setWidth(width);
}
void Shape::setStyle(Qt::PenStyle style)
{
    pen.setStyle(style);
}
void Shape::setCapStyle(Qt::PenCapStyle capStyle)
{
    pen.setCapStyle(capStyle);
}
void Shape::setJoinStyle(Qt::PenJoinStyle style)
{
    pen.setJoinStyle(style);
}
void Shape::setBrushColor(QColor color)
{
    brush.setColor(color);
}
void Shape::setBrushStyle(Qt::BrushStyle style)
{
    brush.setStyle(style);
}

//Overloaded operators
bool Shape::operator==(const Shape& rhs) const
{
    return(this->id == rhs.id);
}
bool Shape::operator<(const Shape& rhs) const
{
    return(this->id < rhs.id);
}
