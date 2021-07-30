#include "serializer.h"

void SaveFile(const myVector<Shape*> shapeList)
{
    ofstream fout;
    fout.open("shapes.txt");

    for(size_t i = 0; i < shapeList.size(); i++)
    {
        fout << endl;

        fout << "ShapeId: " << shapeList[i]->getId() << endl;

        switch(shapeList[i]->getShape())
        {
        case Shape::ShapeType::LINE:
            SaveLine(fout, static_cast<Line*>(shapeList[i]));
            break;

        case Shape::ShapeType::POLYLINE:
            SavePolyline(fout, static_cast<Polyline*>(shapeList[i]));
            break;

        case Shape::ShapeType::POLYGON:
            SavePolygon(fout, static_cast<Polygon*>(shapeList[i]));
            break;

        case Shape::ShapeType::RECTANGLE:
            SaveRectangle(fout, static_cast<Rectangle*>(shapeList[i]));
            break;

        case Shape::ShapeType::SQUARE:
            SaveSquare(fout, static_cast<Rectangle*>(shapeList[i]));
            break;

        case Shape::ShapeType::ELLIPSE:
            SaveEllipse(fout, static_cast<Ellipse*>(shapeList[i]));
            break;

        case Shape::ShapeType::CIRCLE:
            SaveCircle(fout, static_cast<Ellipse*>(shapeList[i]));
            break;

        case Shape::ShapeType::TEXT:
            SaveText(fout, static_cast<Text*>(shapeList[i]));
            break;

        default:; //Unknown shape type, return exception?
        }//end switch(shapeList[i].getShapeType()
    }//end for(...)

    fout.close();
}

void SaveLine(ofstream& fout, Line* lineObj)
{
    fout << "ShapeType: " << "Line" << endl
         << "ShapeDimensions: " << lineObj->getDimensions()[0];

    for(size_t i = 1; i < lineObj->getDimensions().size(); i++)
    {
        fout << ", " << lineObj->getDimensions()[i];
    }

    fout << endl;

    fout << "PenColor: " << convColor(lineObj->getPen().color().name()) << endl
         << "PenWidth: " << lineObj->getPen().width() << endl
         << "PenStyle: " << convPenStyle(lineObj->getPen().style()) << endl
         << "PenCapStyle: " << convPenCapStyle(lineObj->getPen().capStyle()) << endl
         << "PenJoinStyle: " << convPenJoinStyle(lineObj->getPen().joinStyle()) << endl;
}

void SavePolyline(ofstream& fout, Polyline* polylineObj)
{
    fout << "ShapeType: " << "Polyline" << endl
         << "ShapeDimension QPaintDevice* pDevice = new QPaintDevices: " << polylineObj->getDimensions()[0];

    for(size_t i = 1; i < polylineObj->getDimensions().size(); i++)
    {
        fout << ", " << polylineObj->getDimensions()[i];
    }

    fout << endl;

    fout << "PenColor: " << convColor(polylineObj->getPen().color().name()) << endl
         << "PenWidth: " << polylineObj->getPen().width() << endl
         << "PenStyle: " << convPenStyle(polylineObj->getPen().style()) << endl
         << "PenCapStyle: " << convPenCapStyle(polylineObj->getPen().capStyle()) << endl
         << "PenJoinStyle: " << convPenJoinStyle(polylineObj->getPen().joinStyle()) << endl;
}

void SavePolygon(ofstream& fout, Polygon* polygonObj)
{
    fout << "ShapeType: " << "Polygon" << endl
         << "ShapeDimensions: " << polygonObj->getDimensions()[0];

    for(size_t i = 1; i < polygonObj->getDimensions().size(); i++)
    {
        fout << ", " << polygonObj->getDimensions()[i];
    }

    fout << endl;

    fout << "PenColor: " << convColor(polygonObj->getPen().color().name()) << endl
         << "PenWidth: " << polygonObj->getPen().width() << endl
         << "PenStyle: " << convPenStyle(polygonObj->getPen().style()) << endl
         << "PenCapStyle: " << convPenCapStyle(polygonObj->getPen().capStyle()) << endl
         << "PenJoinStyle: " << convPenJoinStyle(polygonObj->getPen().joinStyle()) << endl
         << "BrushColor: " << convColor(polygonObj->getBrush().color().name()) << endl
         << "BrushStyle: " << convBrushStyle(polygonObj->getBrush().style()) << endl;
}

void SaveRectangle(ofstream& fout, Rectangle* rectangleObj)
{
    fout << "ShapeType: " << "Rectangle" << endl
         << "ShapeDimensions: " << rectangleObj->getDimensions()[0];

    for(size_t i = 1; i < rectangleObj->getDimensions().size(); i++)
    {
        fout << ", " << rectangleObj->getDimensions()[i];
    }

    fout << endl;

    fout << "PenColor: " << convColor(rectangleObj->getPen().color().name()) << endl
         << "PenWidth: " << rectangleObj->getPen().width() << endl
         << "PenStyle: " << convPenStyle(rectangleObj->getPen().style()) << endl
         << "PenCapStyle: " << convPenCapStyle(rectangleObj->getPen().capStyle()) << endl
         << "PenJoinStyle: " << convPenJoinStyle(rectangleObj->getPen().joinStyle()) << endl
         << "BrushColor: " << convColor(rectangleObj->getBrush().color().name()) << endl
         << "BrushStyle: " << convBrushStyle(rectangleObj->getBrush().style()) << endl;
}

void SaveSquare(ofstream& fout, Rectangle* squareObj)
{
    fout << "ShapeType: " << "Square" << endl
         << "ShapeDimensions: " << squareObj->getDimensions()[0];

    for(size_t i = 1; i < squareObj->getDimensions().size(); i++)
    {
        fout << ", " << squareObj->getDimensions()[i];
    }

    fout << endl;

    fout << "PenColor: " << convColor(squareObj->getPen().color().name()) << endl
         << "PenWidth: " << squareObj->getPen().width() << endl
         << "PenStyle: " << convPenStyle(squareObj->getPen().style()) << endl
         << "PenCapStyle: " << convPenCapStyle(squareObj->getPen().capStyle()) << endl
         << "PenJoinStyle: " << convPenJoinStyle(squareObj->getPen().joinStyle()) << endl
         << "BrushColor: " << convColor(squareObj->getBrush().color().name()) << endl
         << "BrushStyle: " << convBrushStyle(squareObj->getBrush().style()) << endl;
}

void SaveEllipse(ofstream& fout, Ellipse* ellipseObj)
{
    fout << "ShapeType: " << "Ellipse" << endl
         << "ShapeDimensions: " << ellipseObj->getDimensions()[0];

    for(size_t i = 1; i < ellipseObj->getDimensions().size(); i++)
    {
        fout << ", " << ellipseObj->getDimensions()[i];
    }

    fout << endl;

    fout << "PenColor: " << convColor(ellipseObj->getPen().color().name()) << endl
         << "PenWidth: " << ellipseObj->getPen().width() << endl
         << "PenStyle: " << convPenStyle(ellipseObj->getPen().style()) << endl
         << "PenCapStyle: " << convPenCapStyle(ellipseObj->getPen().capStyle()) << endl
         << "PenJoinStyle: " << convPenJoinStyle(ellipseObj->getPen().joinStyle()) << endl
         << "BrushColor: " << convColor(ellipseObj->getBrush().color().name()) << endl
         << "BrushStyle: " << convBrushStyle(ellipseObj->getBrush().style()) << endl;
}

void SaveCircle(ofstream& fout, Ellipse* circleObj)
{
    fout << "ShapeType: " << "Circle" << endl
         << "ShapeDimensions: " << circleObj->getDimensions()[0];

    for(size_t i = 1; i < circleObj->getDimensions().size(); i++)
    {
        fout << ", " << circleObj->getDimensions()[i];
    }

    fout << endl;

    fout << "PenColor: " << convColor(circleObj->getPen().color().name()) << endl
         << "PenWidth: " << circleObj->getPen().width() << endl
         << "PenStyle: " << convPenStyle(circleObj->getPen().style()) << endl
         << "PenCapStyle: " << convPenCapStyle(circleObj->getPen().capStyle()) << endl
         << "PenJoinStyle: " << convPenJoinStyle(circleObj->getPen().joinStyle()) << endl
         << "BrushColor: " << convColor(circleObj->getBrush().color().name()) << endl
         << "BrushStyle: " << convBrushStyle(circleObj->getBrush().style()) << endl;
}

void SaveText(ofstream& fout, Text* textObj)
{
    fout << "ShapeType: " << "Text" << endl
         << "ShapeDimensions: " << textObj->getDimensions()[0];

    for(size_t i = 1; i < textObj->getDimensions().size(); i++)
    {
        fout << ", " << textObj->getDimensions()[i];
    }

    fout << endl;

    fout << "TextString: " << textObj->getText().toPlainText().toLocal8Bit().constData() << endl
         << "TextColor: " << convColor(textObj->getText().textColor().name()) << endl
         << "TextAlignment: " << convAlignment(textObj->getText().alignment()) << endl
         << "TextPointSize: " << textObj->getText().fontPointSize() << endl
         << "TextFontFamily: " << textObj->getText().fontFamily().toLocal8Bit().constData() << endl
         << "TextFontStyle: " << convFontStyle(textObj->getFont().style()) << endl
         << "TextFontWeight: " << convFontWeight(textObj->getFont().weight()) << endl;
}


string convColor(QString color)
{
    string objColor;

    objColor = color.toLocal8Bit().constData();

    if(objColor == "#ffffff")
    {
        return "white";
    }
    else if(objColor == "#000000")
    {
        return "black";
    }
    else if(objColor == "#ff0000")
    {
        return "red";
    }
    else if(objColor == "#00ff00")
    {
        return "green";
    }
    else if(objColor == "#0000ff")
    {
        return "blue";
    }
    else if(objColor == "#00ffff")
    {
        return "cyan";
    }
    else if(objColor == "#ff00ff")
    {
        return "magenta";
    }
    else if(objColor == "#ffff00")
    {
        return "yellow";
    }
    else if(objColor == "a0a0a4")
    {
        return "gray";
    }
}

string convPenStyle(Qt::PenStyle style){

  switch(style){
      case Qt::NoPen: return "NoPen";
      case Qt::SolidLine: return "SolidLine";
      case Qt::DashLine: return "DashLine";
      case Qt::DotLine: return "DotLine";
      case Qt::DashDotLine: return "DashDotLine";
      case Qt::DashDotDotLine: return "DashDotDotLine";

  }
}

string convPenCapStyle(Qt::PenCapStyle style){
    switch(style){
      case Qt::FlatCap: return "FlatCap";
      case Qt::SquareCap: return "SquareCap";
      case Qt::RoundCap: return "RoundCap";
    }
}

string convPenJoinStyle(Qt::PenJoinStyle style){
switch(style){
      case Qt::MiterJoin: return "MiterJoin";
      case Qt::BevelJoin: return "BevelJoin";
      case Qt::RoundJoin: return "RoundJoin";
    }
}

string convBrushStyle(Qt::BrushStyle style){
switch(style){
      case Qt::SolidPattern: return "SolidPattern";
      case Qt::HorPattern: return "HorPattern";
      case Qt::VerPattern: return "VerPattern";
      case Qt::NoBrush: return "NoBrush";
    }
}
string convAlignment(Qt::Alignment alignment)
{
switch(alignment){
    case Qt::AlignLeft: return "AlignLeft";
    case Qt::AlignRight: return "AlignRight";
    case Qt::AlignTop: return "AlignTop";
    case Qt::AlignBottom: return "AlignBottom";
    case Qt::AlignCenter: return "AlignCenter";
    }
}

string convFontStyle(QFont::Style style){
switch(style){
    case QFont::StyleNormal: return "StyleNormal";
    case QFont::StyleItalic: return "StyleItalic";
    case QFont::StyleOblique: return "StyleOblique";
    }
}

string convFontWeight(int weight){
switch(weight){
      case QFont::Thin: return "Thin";
      case QFont::Light: return "Light";
      case QFont::Normal: return "Normal";
      case QFont::Bold: return "Bold";
    }
}
