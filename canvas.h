#ifndef CANVAS_H
#define CANVAS_H

#include <QMainWindow>
#include <QtGui>
#include <QList>
#include <QObject>
#include <QtCore>
#include <QWidget>
#include "ui_mainwindow.h"

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
    QPainter* getPainter();

    int shapeToDraw = 0;

protected:
    // Function used to close an event
    void paintEvent(QPaintEvent *e) override;
    QPainter *painter;
};

#endif // CANVAS_H
