#include "contactWindow.h"
#include <QLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

contactWindow::contactWindow(QDialog *parent) :
    QDialog(parent)
{
        QGridLayout *mainLayout = new QGridLayout;
        setLayout(mainLayout);

        this->setWindowTitle(tr("Contact us"));

        this->resize(300, 300);

        //scene = new QGraphicsScene(this);

//        emailLabel->setText("Email us at support@meltedicecream.com!");

        teamLabel = new QLabel(this);
        teamLabel->move(50,225);
        teamLabel->setText("Development team: Melted Ice Cream\nEmail us at support@meltedicecream.com!");
        mainLayout->addWidget(teamLabel, 0, 0, 1, 1);

        QPixmap image(":/logo.png");
        QLabel *imageLbl = new QLabel();
        imageLbl->setPixmap(image);
        mainLayout->addWidget(imageLbl, 1, 0, 3, 3);

//        okButton = new QPushButton(this);
//        okButton->move(120,275);
//        okButton->setText("Ok");


//        connect(okButton,&QPushButton::clicked,this,&contactWindow::close);

}
