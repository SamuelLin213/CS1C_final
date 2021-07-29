#ifndef TEXT_H
#define TEXT_H

#include "Shapes.h"
//using namespace std;

class Text: public Shape
{
  public:
    Text(int id = -1, ShapeType type = NONE);
    Text();
    ~Text();

    void draw(QPainter* shape) override;
    void move(int[]) override;
    int perimeter() override { return 0; }
    int area() override { return 0; }

    void setText(const QString &Text);
    void setTColor(const QColor &c);
    void setAlignment(Qt::Alignment a);
    void setPointSize(qreal s);
    void setFontFamily(const QString &fontFamily);
    void setFontStyle(QFont::Style style);
    void setFontWeight(int weight);

    QFont getFont();
    QTextEdit& getText();
  private:
    QTextEdit text;
    QFont font;
};

#endif // TEXT_H
