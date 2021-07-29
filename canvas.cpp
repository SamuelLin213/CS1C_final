#include "canvas.h"
#include "Shapes.h"
#include "mainwindow.h"
#include <QPainter>
#include <QPainterPath>
#include <QTextEdit>

canvas::canvas(QWidget *parent)
    : QWidget(parent)
    //, ui(new Ui::canvas)
{
    shapeList.push_back(new Line(1, Shape::LINE));
    shapeList.push_back(new class Polyline(2, Shape::POLYLINE));
    shapeList.push_back(new class Polygon(3, Shape::POLYGON));
    shapeList.push_back(new class Rectangle(4, Shape::RECTANGLE));
    shapeList.push_back(new class Rectangle(5, Shape::SQUARE));
    shapeList.push_back(new class Ellipse(6, Shape::ELLIPSE));
    shapeList.push_back(new class Ellipse(7, Shape::CIRCLE));
    shapeList.push_back(new class Text(8, Shape::TEXT));

    shapeList[0]->addDimension(20);
    shapeList[0]->addDimension(90);
    shapeList[0]->addDimension(100);
    shapeList[0]->addDimension(20);
    shapeList[0]->setPen(Qt::black);
    shapeList[0]->setBrush(Qt::black, Qt::SolidPattern);
//    shapeList[0]->setLine();

    shapeList[1]->addDimension(460);
    shapeList[1]->addDimension(90);
    shapeList[1]->addDimension(470);
    shapeList[1]->addDimension(20);
    shapeList[1]->addDimension(530);
    shapeList[1]->addDimension(40);
    shapeList[1]->addDimension(540);
    shapeList[1]->addDimension(80);
    shapeList[1]->setPen(Qt::black);
    shapeList[1]->setBrush(Qt::black, Qt::SolidPattern);

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}
void canvas::paintEvent(QPaintEvent *)
{
    painter = new QPainter(this);
//    QVector<QPoint> points;
//    QVector<QPoint> points2;

    for(int i = 0; i < 2; i++)
    {
        shapeList[i]->draw(painter);
    }


    switch(shapeToDraw)
    {
        case 1:
            //painter->drawLine(this);
            break;
        case 2:
//            points.push_back(QPoint(460, 90));
//            points.push_back(QPoint(470, 20));
//            points.push_back(QPoint(530, 40));
//            points.push_back(QPoint(540, 80));

//            painter->drawPolyline(points);
            break;
        case 3:
            points2.push_back(QPoint(900, 90));
            points2.push_back(QPoint(910, 20));
            points2.push_back(QPoint(970, 40));
            points2.push_back(QPoint(980, 80));

            painter->drawPolygon(points2);
            break;
        case 4:
            painter->drawRect(20, 200, 170, 100);
            break;
        case 5:
            painter->drawRect(250, 150, 200, 200);
            break;
        case 6:
            painter->drawEllipse(520, 200, 170, 100);
            break;
        case 7:
            painter->drawEllipse(750, 150, 200, 200);
            break;
        case 8:
            painter->drawText(250, 425, 500, 50, 0, tr("Class Project 2 - 2D Graphics Modeler"));
            break;
    }
}
QPainter* canvas::getPainter()
{
    return painter;
}
void canvas::drawLine()
{
    shapeToDraw = 1;
    update();
}
void canvas::drawPolyline()
{
    shapeToDraw = 2;
    update();
}
void canvas::drawPolygon()
{
    shapeToDraw = 3;
    update();
}
void canvas::drawRectangle()
{
    shapeToDraw = 4;
    update();
}
void canvas::drawSquare()
{
    shapeToDraw = 5;
    update();
}
void canvas::drawEllipse()
{
    shapeToDraw = 6;
    update();
}
void canvas::drawCircle()
{
    shapeToDraw = 7;
    update();
}
void canvas::drawText()
{
    shapeToDraw = 8;
    update();
}
void canvas::moveShape()
{
    update();
}
void canvas::removeShape()
{
    update();
}
void canvas::addShape()
{
    update();
}
