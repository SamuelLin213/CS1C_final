#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <QPainter>
#include <Qt>
#include <iostream>
#include <fstream>
#include "Shapes.h"
#include "Line.h"
#include "Polyline.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Text.h"
#include "vector.h"

using std::getline;
using std::string;
using std::cin;
using std::cout;
using std::ofstream;

//Unique functions for saving each shape type to the shapes.txt file.

/*! @brief Saves a line shape type to the shapes.txt file.

    Passed a pointer of type line.
    Converts the information in the object to strings / ints and
    outputs that information to the shapes.txt file in the
    proper format.

    @param line A pointer of type line
*/
void SaveLine(ofstream&, Line*);

/*! @brief Saves a polyline shape type to the shapes.txt file.
    Passed a pointer of type polyline.
    Converts the information in the object to strings / ints and
    outputs that information to the shapes.txt file in the
    proper format.

     @param line A pointer of type polyline
*/
void SavePolyline(ofstream&, Polyline*);

/*! @brief Saves a polygon shape type to the shapes.txt file.
    Passed a pointer of type polygon.
    Converts the information in the object to strings / ints and
    outputs that information to the shapes.txt file in the
    proper format.

     @param line A pointer of type polygon
*/
void SavePolygon(ofstream&, Polygon*);

/*! @brief Saves a rectangle shape type to the shapes.txt file.
    Passed a pointer of type rectangle.
    Converts the information in the object to strings / ints and
    outputs that information to the shapes.txt file in the
    proper format.

     @param line A pointer of type rectangle
*/
void SaveRectangle(ofstream&, Rectangle*);

/*! @brief Saves a square shape type to the shapes.txt file.
    Passed a pointer of type square.
    Converts the information in the object to strings / ints and
    outputs that information to the shapes.txt file in the
    proper format.

     @param line A pointer of type square
*/
void SaveSquare(ofstream&, Rectangle*);

/*! @brief Saves a ellipse shape type to the shapes.txt file.
    Passed a pointer of type ellipse.
    Converts the information in the object to strings / ints and
    outputs that information to the shapes.txt file in the
    proper format.

     @param line A pointer of type ellipse
*/
void SaveEllipse(ofstream&, Ellipse*);

/*! @brief Saves a circle shape type to the shapes.txt file.
    Passed a pointer of type circle.
    Converts the information in the object to strings / ints and
    outputs that information to the shapes.txt file in the
    proper format.

     @param line A pointer of type circle
*/
void SaveCircle(ofstream&, Ellipse*);

/*! @brief Saves a text shape type to the shapes.txt file.
    Passed a pointer of type text.
    Converts the information in the object to strings / ints and
    outputs that information to the shapes.txt file in the
    proper format.

     @param line A pointer of type text
*/
void SaveText(ofstream&, Text*);

//Getter functions to convert the data in the shapes back to strings
string convColor(QString color);
string convPenStyle(Qt::PenStyle style);
string convPenCapStyle(Qt::PenCapStyle style);
string convPenJoinStyle(Qt::PenJoinStyle style);
string convBrushStyle(Qt::BrushStyle style);
string convAlignment(Qt::Alignment alignment);
string convFontStyle(QFont::Style style);
string convFontWeight(int weight);

/*! @brief Function to save the shapeList vector by converting and outputing it's
   contents into the shapes.txt file.

   @param shapeList A vector of shapes to be put into the shape.txt file
   */
void SaveFile(const myVector<Shape*> shapeList);

#endif // SERIALIZER_H
