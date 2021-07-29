#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include "loginWindow.h"
#include "contactWindow.h"

class canvas;

//QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
//QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void drawLine();
    void drawPolyline();
    void drawPolygon();
    void drawRectangle();
    void drawSquare();
    void drawEllipse();
    void drawCircle();
    void drawText();
    void login();
    void contactUs();
    void testimonal();
    void move();
    void remove();
    void add();

private:
//    Ui::MainWindow *ui;
    canvas *renderArea;
    QPushButton *buttonContact;
    QPushButton *buttonTestimonial;
    QPushButton *buttonLine;
    QPushButton *buttonPolyline;
    QPushButton *buttonPolygon;
    QPushButton *buttonRectangle;
    QPushButton *buttonSquare;
    QPushButton *buttonEllipse;
    QPushButton *buttonCircle;
    QPushButton *buttonText;
    QPushButton *buttonLogin;
    QPushButton *buttonAdd;
    QPushButton *buttonMove;
    QPushButton *buttonRemove;
};
#endif // MAINWINDOW_H
