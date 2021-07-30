#ifndef SHAPEPARSER_H
#define SHAPEPARSER_H

#include <QPainter>
#include <Qt>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
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
using std::ifstream;
using std::istringstream;
using std::remove;
/*! \file */
/*! \file ShapeParser.h */
/** @file ShapeParser.h */

/*!
    @brief The types of shapes are defined through an enum here
*/

//Unique functions for loading each shape type.

/*! @brief Loads a line.

    Passed the input file stream object so it can read from the shapes.txt file
    and the line id.
    Reads in the remaining line information needed from the file
    and returns a pointer to a line object created within the function.

    @param ifsteam& The input file stream object
    @param id The line id

    @return a pointer to a line object
*/
Shape* LoadLine(ifstream&, int id);

/*! @brief Loads a polyline.

    Passed the input file stream object so it can read from the shapes.txt file
    and the polyline id.
    Reads in the remaining polyline information needed from the file
    and returns a pointer to a polyline object created within the function.

    @param ifsteam& The input file stream object
    @param id The polyline id

    @return a pointer to a polyline object
*/
Shape* LoadPolyline(ifstream&, int id);

/*! @brief Loads a polygon.

    Passed the input file stream object so it can read from the shapes.txt file
    and the polygon id.
    Reads in the remaining polygon information needed from the file
    and returns a pointer to a polygon object created within the function.

    @param ifsteam& The input file stream object
    @param id The polygon id

    @return a pointer to a polygon object
*/
Shape* LoadPolygon(ifstream&, int id);

/*! @brief Loads a rectangle.

    Passed the input file stream object so it can read from the shapes.txt file
    and the rectangle id.
    Reads in the remaining rectangle information needed from the file
    and returns a pointer to a rectangle object created within the function.

    @param ifsteam& The input file stream object
    @param id The rectangle id

    @return a pointer to a rectangle object
*/
Shape* LoadRectangle(ifstream&, int id);

/*! @brief Loads a square.

    Passed the input file stream object so it can read from the shapes.txt file
    and the square id.
    Reads in the remaining square informGlobalation needed from the file
    and returns a pointer to a square object created within the function.

    @param ifsteam& The input file stream object
    @param id The square id

    @return a pointer to a square object
*/
Shape* LoadSquare(ifstream&, int id);

/*! @brief Loads a ellipse.

    Passed the input file stream object so it can read from the shapes.txt file
    and the ellipse id.
    Reads in the remaining ellipse information needed from the file
    and returns a pointer to a ellipse object created within the function.

    @param ifsteam& The input file stream object
    @param id The ellipse id

    @return a pointer to a ellipse object
*/
Shape* LoadEllipse(ifstream&, int id);

/*! @brief Loads a circle.

    Passed the input file stream object so it can read from the shapes.txt file
    and the circle id.
    Reads in the remaining circle information needed from the file
    and returns a pointer to a circle object created within the function.

    @param ifsteam& The input file stream object
    @param id The circle id

    @return a pointer to a circle object
*/
Shape* LoadCircle(ifstream&, int id);


/*! @brief Loads a text.

    Passed the input file stream object so it can read from the shapes.txt file
    and the text id.
    Reads in the remaining text information needed from the file
    and returns a pointer to a text object created within the function.

    @param ifsteam& The input file stream object
    @param id The text id

    @return a pointer to a text object
*/
Shape* LoadText(ifstream&, int id);

/*! @brief Getter functions to convert the string input from the shapes.txt file
   into the QT GlobalColor being passed into the setter functions for each shape.

    @param string String input to be parsed
  */
Qt::GlobalColor getColor(const string&);
/*! @brief Getter functions to convert the string input from the shapes.txt file
   into the QT PenStyle being passed into the setter functions for each shape.

   @param string String input to be parsed
  */
Qt::PenStyle getPenStyle(const string&);
/*! @brief Getter functions to convert the string input from the shapes.txt file
   into the QT PenCapStyle being passed into the setter functions for each shape.

   @param string String input to be parsed
  */
Qt::PenCapStyle getPenCapStyle(const string&);
/*! @brief Getter functions to convert the string input from the shapes.txt file
   into the Q PenJoinStyle being passed into the setter functions for each shape.

   @param string String input to be parsed
  */
Qt::PenJoinStyle getPenJoinStyle(const string&);
/*! @brief Getter functions to convert the string input from the shapes.txt file
   into the QT BrushStyle being passed into the setter functions for each shape.

   @param string String input to be parsed
  */
Qt::BrushStyle getBrushStyle(const string&);
/*! @brief Getter functions to convert the string input from the shapes.txt file
   into the QT AlignmentFlag being passed into the setter functions for each shape.

   @param string String input to be parsed
  */
Qt::Alignment getAlignment(const string&);
/*! @brief Getter functions to convert the string input from the shapes.txt file
   into the QFont Style being passed into the setter functions for each shape.

   @param string String input to be parsed
  */
QFont::Style getFontStyle(const string&);
/*! @brief Getter functions to convert the string input from the shapes.txt file
   into the QFont Weight being passed into the setter functions for each shape.

   @param string String input to be parsed
  */
QFont::Weight getFontWeight(const string&);

/*! @brief Function to return a vector of shape* using the shapes.txt file as input.
*/
myVector<Shape*> LoadFile();

#endif // SHAPEPARSER_H
