#include "canvas.h"
#include "Shapes.h"
#include "mainwindow.h"
#include <QPainter>
#include <QPainterPath>
#include <QTextEdit>
#include <QInputDialog>
#include <string>

canvas::canvas(QWidget *parent)
    : QWidget(parent)
    //, ui(new Ui::canvas)
{
    shapeList.push_back(new class Line(1, Shape::LINE));
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
    dynamic_cast<Line*>(shapeList[0])->setLine();

    shapeList[1]->addDimension(460);
    shapeList[1]->addDimension(90);
    shapeList[1]->addDimension(470);
    shapeList[1]->addDimension(20);
    shapeList[1]->addDimension(530);
    shapeList[1]->addDimension(40);
    shapeList[1]->addDimension(540);
    shapeList[1]->addDimension(80);

    shapeList[2]->addDimension(900);
    shapeList[2]->addDimension(90);
    shapeList[2]->addDimension(910);
    shapeList[2]->addDimension(20);
    shapeList[2]->addDimension(970);
    shapeList[2]->addDimension(40);
    shapeList[2]->addDimension(980);
    shapeList[2]->addDimension(80);

    shapeList[3]->addDimension(20);
    shapeList[3]->addDimension(200);
    shapeList[3]->addDimension(170);
    shapeList[3]->addDimension(100);

    shapeList[4]->addDimension(250);
    shapeList[4]->addDimension(150);
    shapeList[4]->addDimension(200);
    shapeList[4]->addDimension(200);

    shapeList[5]->addDimension(520);
    shapeList[5]->addDimension(200);
    shapeList[5]->addDimension(170);
    shapeList[5]->addDimension(100);

    shapeList[6]->addDimension(750);
    shapeList[6]->addDimension(150);
    shapeList[6]->addDimension(200);
    shapeList[6]->addDimension(200);

    shapeList[7]->addDimension(250);
    shapeList[7]->addDimension(425);
    shapeList[7]->addDimension(500);
    shapeList[7]->addDimension(50);
    dynamic_cast<Text*>(shapeList[7])->setText(QString::fromStdString("Class Project 2 - 2D Graphics Modeler"));

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}
void canvas::paintEvent(QPaintEvent *)
{
    painter = new QPainter(this);
    bool ok;

    //line, polyline
    int shapeId;
    std::vector<int> dimensionVector;

    for(int i = 0; i < (int)(shapeList.size()); i++)
    {
        shapeList[i]->draw(painter);
    }

    if(shapeToDraw == 1)
    {

        shapeId = QInputDialog::getInt(this, tr("Add shape"),
                                          tr("Enter id of shape:"),
                                          1, 1, 50, 1, &ok);

        for(int i = 1; i <= 2; i++)
        {
            int newX = QInputDialog::getInt(this, tr("New Coordinates"),
                                                 tr("New X:"),
                                                 0, 0, 850, 1, &ok);
            int newY = QInputDialog::getInt(this, tr("New Coordinates"),
                                            tr("New Y:"),
                                            0, 0, 475, 1, &ok);
            dimensionVector.push_back(newX);
            dimensionVector.push_back(newY);
            //coords[numCoords] = {newX, newY};
        }

        //loops through vector and assigns dimensions to int array
        int size = dimensionVector.size();
        int coordAr[size];
        for(int index = 0; index < size; index++)
        {
            coordAr[index] = dimensionVector[index];
        }

        shapeList.push_back(new class Line(shapeId, Shape::LINE));
        //applies new coords
        shapeList[shapeList.size()-1]->move(coordAr);

        moveShape();

    }
    else if(shapeToDraw == 2)
    {

    }
    else if(shapeToDraw == 3)
    {

    }
    else if(shapeToDraw == 4)
    {

    }
    else if(shapeToDraw == 5)
    {

    }
    else if(shapeToDraw == 6)
    {

    }
    else if(shapeToDraw == 7)
    {

    }
    else if(shapeToDraw == 8)
    {

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
