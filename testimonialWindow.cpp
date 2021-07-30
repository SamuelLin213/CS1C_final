#include "testimonialWindow.h"
#include <QLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

    testimonialWindow::testimonialWindow(QDialog *parent):
        QDialog(parent)
    {

       this->setWindowTitle(tr("Leave a testimonial"));

       nameLabel = new QLabel(this);
       nameLabel->move(50,80);
       nameLabel->setText("First Name: ");

       name = new QLineEdit(this);
       name->move(120,80);
       name->setPlaceholderText(tr("Your first name"));
       author = name->text().toStdString();

       messageLabel = new QLabel(this);
       messageLabel->move(50,130);
       messageLabel->setText("Testimonial: ");

       message = new QLineEdit(this);
       message->move(120,130);
       message->setPlaceholderText("Enter your message");
       description = message->text().toStdString();


       submitButton = new QPushButton(this);
       submitButton->move(80, 200);
       submitButton->setText("Submit");

       cancelButton = new QPushButton(this);
       cancelButton->move(170,200);
       cancelButton->setText("Cancel");

       connect(submitButton,&QPushButton::clicked,this,&testimonialWindow::submit);
       connect(cancelButton,&QPushButton::clicked,this,&testimonialWindow::close);
    }

   void testimonialWindow::submit()
   {
//       if(LoadTestimony(author).getAuthor()!=""){
//           return;
//       }
       ofstream fout;
       //Testimony* testimony = new Testimony(author, description);
       fout.open(":/testimonies.txt", std::fstream::app);

      fout << endl;

          fout << "Author: " << author << endl;
          fout << "Description: " << description << endl;
          //fout << testimony->print();

      fout.close();
      testimonialWindow::close();
   }


   testimonialWindow::Testimony LoadTestimony(string name)
    {
       {
           ifstream fin;
           fin.open("testimonies.txt");
           testimonialWindow::Testimony testimony = testimonialWindow::Testimony();
           string input;
           string author;
           string description;
           string shapeType;
           //int shapeTypeInt = 0;

           while(fin)
           {
           //Ignore the line of whitespace above each testimonies.
           fin.ignore(10000, '\n');

               //Read in the tesimony's email
               fin.ignore(10000, ' ');

               fin >> input;
               if(name==input){
                   fin.ignore(10000, ' ');

               fin >> author;
                fin.ignore(10000, ' ');

               fin >> description;

           fin.close();
           testimony = testimonialWindow::Testimony(author,description);
           return testimony;
               }


           }//end while(fin)
           fin.close();

           //returns an empty testimony if not found
           return testimony;
       }
    }
