#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>


class loginWindow : public QDialog
{
         Q_OBJECT
public:
         explicit loginWindow(QDialog *parent = 0);

public slots:
         void login();
private:
         QLabel *usernameLabel;
         QLabel *passwordLabel;
         QLineEdit *username;
         QLineEdit *password;
         QPushButton *loginButton;
         QPushButton *exitButton;
};

#endif
