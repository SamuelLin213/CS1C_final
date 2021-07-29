#include "Ellipse.h"
//using namespace std;

Ellipse::Ellipse(int id, ShapeType type)
    :Shape(id, type)
{
}

void Ellipse::draw(QPainter* shape)
{
    shape->save();

    shape->save(); //save original state of qpainter

    shape->setPen(getPen());
    shape->setBrush(getBrush());

    if(isCircle())
        shape->drawEllipse(getDimensions()[0],getDimensions()[1],getDimensions()[2],getDimensions()[2]);
    else
        shape->drawEllipse(getDimensions()[0],getDimensions()[1],getDimensions()[2],getDimensions()[3]);

    shape->restore(); //restore to the original state of qpainter
}
void Ellipse::move(int dims_[])
{
    getDimensions()[0] = dims_[0];
    getDimensions()[1] = dims_[1];
}
int Ellipse::perimeter()
{
    if(!isCircle())
    {
        int a = getDimensions()[2];
        int b = getDimensions()[3];
        int h = pow(a-b, 2)/pow(a+b, 2);

        int perimeter = (int)(3.14 * (a + b) * (1 + ( (3 * h) / (10 + sqrt(4 - 3 * h)) ) ));
        return perimeter;
    }
    else
        return (int)(2 * 3.14 * getDimensions()[2]);
}
int Ellipse::area()
{
    if(!isCircle())
    {
        return (int)(3.14 * getDimensions()[2] * getDimensions()[3]);
    }
    else
        return (int)(3.14 * pow(getDimensions()[2], 2));

}
bool Ellipse::isCircle()
{
    if(getDimensions().size() == 3 || this->getShape() == Shape::CIRCLE)
    {
        return true;
    }
    return false;
}





//class Ellipse;

//// **Constructor**
//Ellipse::Ellipse(QPaintDevice* shape, int id, ShapeType type)
//  : Shape(shape, id, type, 4)
//{
//}

//Ellipse::~Ellipse()
//{
//}

////virtual functions
//void Ellipse::draw()
//{
//    GetPainter().save(); //save original state of qpainter
//    GetPainter().setPen(GetPen());
//    GetPainter().setBrush(GetBrush());
//    GetPainter().drawEllipse(GetDimensions()[0], GetDimensions()[1], GetDimensions()[2], GetDimensions()[3]);

//    GetPainter().restore(); //restore to the original state of qpainter
//}

//void Ellipse::move(int x_, int y_)
//{
//    GetDimensions()[0] = x_;
//    GetDimensions()[1]= y_;
//}

//int Ellipse::perimeter()
//{
//    return((2 * GetDimensions()[2]) + (2 * GetDimensions()[3]));
//}

//int Ellipse::area()
//{
//    return (GetDimensions()[2] * GetDimensions()[3]);
//}
