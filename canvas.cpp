#include "canvas.h"
#include "Shapes.h"
#include "mainwindow.h"
#include "shapeparser.h"
#include <QPainter>
#include <QPainterPath>
#include <QTextEdit>
#include <QInputDialog>
#include <string>

canvas::canvas(QWidget *parent)
    : QWidget(parent)
    //, ui(new Ui::canvas)
{
    //shapeList = LoadFile();
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

    for(int i = 0; i < (int)(shapeList.size()); i++)
    {
        shapeList[i]->draw(painter);
    }
}
QPainter* canvas::getPainter()
{
    return painter;
}
void canvas::drawLine()
{
    bool ok;
    int shapeId;
    std::vector<int> dimensionVector;

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
    }

    shapeList.push_back(new class Line(shapeId, Shape::LINE));
    //applies new coords
    for(int i = 0; i < 4; i++)
    {
        shapeList[shapeList.size()-1]->addDimension(dimensionVector[i]);
    }
    dynamic_cast<Line*>(shapeList[shapeList.size()-1])->setLine();

    update();
}
void canvas::drawPolyline()
{
    bool ok;
    int shapeId;
    int numPoints;
    std::vector<int> dimensionVector;

    shapeId = QInputDialog::getInt(this, tr("Add shape"),
                                      tr("Enter id of shape:"),
                                      1, 1, 50, 1, &ok);
    numPoints = QInputDialog::getInt(this, tr("Points"),
                                     tr("Number of points to move(default 1):"),
                                     1, 1, 50, 1, &ok);


    for(int i = 0; i < numPoints; i++)
    {
        int newX = QInputDialog::getInt(this, tr("New Coordinates"),
                                             tr("New X:"),
                                             0, 0, 850, 1, &ok);
        int newY = QInputDialog::getInt(this, tr("New Coordinates"),
                                        tr("New Y:"),
                                        0, 0, 475, 1, &ok);
        dimensionVector.push_back(newX);
        dimensionVector.push_back(newY);
    }

    shapeList.push_back(new class Polyline(shapeId, Shape::POLYLINE));
    //applies new coords
    for(int i = 0; i < (int)(dimensionVector.size()); i++)
    {
        shapeList[shapeList.size()-1]->addDimension(dimensionVector[i]);
    }

    update();
}
void canvas::drawPolygon()
{
    bool ok;
    int shapeId;
    int numPoints;
    std::vector<int> dimensionVector;

    shapeId = QInputDialog::getInt(this, tr("Add shape"),
                                      tr("Enter id of shape:"),
                                      1, 1, 50, 1, &ok);
    numPoints = QInputDialog::getInt(this, tr("Points"),
                                     tr("Number of points to move(default 1):"),
                                     1, 1, 50, 1, &ok);


    for(int i = 0; i < numPoints; i++)
    {
        int newX = QInputDialog::getInt(this, tr("New Coordinates"),
                                             tr("New X:"),
                                             0, 0, 850, 1, &ok);
        int newY = QInputDialog::getInt(this, tr("New Coordinates"),
                                        tr("New Y:"),
                                        0, 0, 475, 1, &ok);
        dimensionVector.push_back(newX);
        dimensionVector.push_back(newY);
    }

    shapeList.push_back(new class Polygon(shapeId, Shape::POLYGON));
    //applies new coords
    for(int i = 0; i < (int)(dimensionVector.size()); i++)
    {
        shapeList[shapeList.size()-1]->addDimension(dimensionVector[i]);
    }

    update();
}
void canvas::drawRectangle()
{
    bool ok;
    int shapeId;
    std::vector<int> dimensionVector;

    shapeId = QInputDialog::getInt(this, tr("Add shape"),
                                      tr("Enter id of shape:"),
                                      1, 1, 50, 1, &ok);

    int newX = QInputDialog::getInt(this, tr("New Coordinates"),
                                         tr("New X:"),
                                         0, 0, 850, 1, &ok);
    int newY = QInputDialog::getInt(this, tr("New Coordinates"),
                                    tr("New Y:"),
                                    0, 0, 475, 1, &ok);
    dimensionVector.push_back(newX);
    dimensionVector.push_back(newY);

    newX = QInputDialog::getInt(this, tr("New dimensions"),
                                             tr("New length:"),
                                             0, 0, 850, 1, &ok);
    newY = QInputDialog::getInt(this, tr("New dimensions"),
                                        tr("New width:"),
                                        0, 0, 475, 1, &ok);
    dimensionVector.push_back(newX);
    dimensionVector.push_back(newY);

    shapeList.push_back(new class Rectangle(shapeId, Shape::RECTANGLE));
    //applies new coords
    for(int i = 0; i < 4; i++)
    {
        shapeList[shapeList.size()-1]->addDimension(dimensionVector[i]);
    }

    update();
}
void canvas::drawSquare()
{
    bool ok;
    int shapeId;
    std::vector<int> dimensionVector;

    shapeId = QInputDialog::getInt(this, tr("Add shape"),
                                      tr("Enter id of shape:"),
                                      1, 1, 50, 1, &ok);

    int newX = QInputDialog::getInt(this, tr("New Coordinates"),
                                         tr("New X:"),
                                         0, 0, 850, 1, &ok);
    int newY = QInputDialog::getInt(this, tr("New Coordinates"),
                                    tr("New Y:"),
                                    0, 0, 475, 1, &ok);
    dimensionVector.push_back(newX);
    dimensionVector.push_back(newY);

    newX = QInputDialog::getInt(this, tr("New dimensions"),
                                             tr("New length:"),
                                             0, 0, 850, 1, &ok);
    dimensionVector.push_back(newX);
    dimensionVector.push_back(newX);

    shapeList.push_back(new class Rectangle(shapeId, Shape::SQUARE));
    //applies new coords
    for(int i = 0; i < 4; i++)
    {
        shapeList[shapeList.size()-1]->addDimension(dimensionVector[i]);
    }

    update();
}
void canvas::drawEllipse()
{
    bool ok;
    int shapeId;
    std::vector<int> dimensionVector;

    shapeId = QInputDialog::getInt(this, tr("Add shape"),
                                      tr("Enter id of shape:"),
                                      1, 1, 50, 1, &ok);

    int newX = QInputDialog::getInt(this, tr("New Coordinates"),
                                         tr("New X:"),
                                         0, 0, 850, 1, &ok);
    int newY = QInputDialog::getInt(this, tr("New Coordinates"),
                                    tr("New Y:"),
                                    0, 0, 475, 1, &ok);
    dimensionVector.push_back(newX);
    dimensionVector.push_back(newY);

    newX = QInputDialog::getInt(this, tr("New axis"),
                                             tr("New semi-major axis:"),
                                             0, 0, 850, 1, &ok);
    newY = QInputDialog::getInt(this, tr("New axis"),
                                        tr("New semi-minor axis:"),
                                        0, 0, 475, 1, &ok);
    dimensionVector.push_back(newX);
    dimensionVector.push_back(newY);

    shapeList.push_back(new class Ellipse(shapeId, Shape::ELLIPSE));
    //applies new coords
    for(int i = 0; i < 4; i++)
    {
        shapeList[shapeList.size()-1]->addDimension(dimensionVector[i]);
    }

    update();
}
void canvas::drawCircle()
{
    bool ok;
    int shapeId;
    std::vector<int> dimensionVector;

    shapeId = QInputDialog::getInt(this, tr("Add shape"),
                                      tr("Enter id of shape:"),
                                      1, 1, 50, 1, &ok);

    int newX = QInputDialog::getInt(this, tr("New Coordinates"),
                                         tr("New X:"),
                                         0, 0, 850, 1, &ok);
    int newY = QInputDialog::getInt(this, tr("New Coordinates"),
                                    tr("New Y:"),
                                    0, 0, 475, 1, &ok);
    dimensionVector.push_back(newX);
    dimensionVector.push_back(newY);

    newX = QInputDialog::getInt(this, tr("New dimension"),
                                             tr("New radius:"),
                                             0, 0, 850, 1, &ok);
    dimensionVector.push_back(newX);
    dimensionVector.push_back(newX);

    shapeList.push_back(new class Ellipse(shapeId, Shape::CIRCLE));
    //applies new coords
    for(int i = 0; i < 4; i++)
    {
        shapeList[shapeList.size()-1]->addDimension(dimensionVector[i]);
    }

    update();
}
void canvas::drawText()
{
    bool ok;
    int shapeId;
    std::vector<int> dimensionVector;

    shapeId = QInputDialog::getInt(this, tr("Add shape"),
                                      tr("Enter id of shape:"),
                                      1, 1, 50, 1, &ok);


    int newX = QInputDialog::getInt(this, tr("New Coordinates"),
                                         tr("New X:"),
                                         0, 0, 850, 1, &ok);
    int newY = QInputDialog::getInt(this, tr("New Coordinates"),
                                    tr("New Y:"),
                                    0, 0, 475, 1, &ok);
    dimensionVector.push_back(newX);
    dimensionVector.push_back(newY);

    newX = QInputDialog::getInt(this, tr("New dimensions"),
                                             tr("New length:"),
                                             0, 0, 850, 1, &ok);
    newY = QInputDialog::getInt(this, tr("New dimensions"),
                                        tr("New width:"),
                                        0, 0, 475, 1, &ok);
    dimensionVector.push_back(newX);
    dimensionVector.push_back(newY);

    shapeList.push_back(new class Text(shapeId, Shape::TEXT));
    //applies new coords
    for(int i = 0; i < 4; i++)
    {
        shapeList[shapeList.size()-1]->addDimension(dimensionVector[i]);
    }
    QString text = QInputDialog::getText(this, tr("Get message"),
                                         tr("Text to display:"), QLineEdit::Normal,
                                         tr("your message"), &ok);

    dynamic_cast<Text*>(shapeList[shapeList.size()-1])->setText(text);

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
