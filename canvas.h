#ifndef CANVAS_H
#define CANVAS_H

#include <QMainWindow>
#include <QtGui>
#include <QList>
#include <QObject>
#include <QtCore>
#include <QWidget>
#include "Shapes.h"
#include "vector.h"

class canvas : public QWidget
{
    Q_OBJECT

public:
    explicit canvas(QWidget *parent = nullptr);

    void drawLine();
    void drawPolyline();
    void drawPolygon();
    void drawRectangle();
    void drawSquare();
    void drawEllipse();
    void drawCircle();
    void drawText();
    void moveShape();
    void removeShape();
    void addShape();
    QPainter* getPainter();

    myVector<Shape*> shapeList;
protected:
    // Function used to close an event
    void paintEvent(QPaintEvent *e) override;
    QPainter *painter;

    QVector<QPoint> points;
    QVector<QPoint> points2;
};

#endif // CANVAS_H
