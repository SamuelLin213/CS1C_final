#ifndef CONTACTWINDOW_H
#define CONTACTWINDOW_H

#include <QLabel>
#include <QtGui>
#include <QDialog>
#include <QPushButton>

class contactWindow: public QDialog
{
    Q_OBJECT
    public:
        explicit contactWindow(QDialog *parent = 0);

    private:
        QLabel *teamLabel;
        QPushButton *okButton;
        QImage *logo;
        QPainter painter;
};

#endif // CONTACTWINDOW_H
