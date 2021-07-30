#include "shapeparser.h"


const QMap<string, Shape::ShapeType> SHAPE_TYPE_CONV
{
    {"Line", Shape::ShapeType::LINE},
    {"Polyline", Shape::ShapeType::POLYLINE},
    {"Polygon", Shape::ShapeType::POLYGON},
    {"Rectangle", Shape::ShapeType::RECTANGLE},
    {"Square", Shape::ShapeType::SQUARE},
    {"Ellipse", Shape::ShapeType::ELLIPSE},
    {"Circle", Shape::ShapeType::CIRCLE},
    {"Text", Shape::ShapeType::TEXT}
};

myVector<Shape*> LoadFile()
{
    ifstream fin;
    fin.open(":/shapes.txt");

    myVector<Shape*> shapeList;
    int id;
    string shapeType_s;
    int shapeType;

    while(fin)
    {
        //Ignore the line of whitespace above each shape.
        fin.ignore(10000, '\n');

        //Read in the shape's unique id
        fin.ignore(10000, ' ');
        fin >> id;

        //Read in the type of the shape
        fin.ignore(10000, ' ');
        getline(fin, shapeType_s);

        shapeType = SHAPE_TYPE_CONV[shapeType_s];

        //Depending on the type of the shape, call the appropriate Load... function to load said shape
        switch(shapeType)
        {
        case Shape::ShapeType::LINE:
            shapeList.push_back(LoadLine(fin, id));
            break;

        case Shape::ShapeType::POLYLINE:
            shapeList.push_back(LoadPolyline(fin, id));
            break;

        case Shape::ShapeType::POLYGON:
            shapeList.push_back(LoadPolygon(fin, id));
            break;

        case Shape::ShapeType::RECTANGLE:
            shapeList.push_back(LoadRectangle(fin, id));
            break;

        case Shape::ShapeType::SQUARE:
            shapeList.push_back(LoadSquare(fin, id));
            break;

        case Shape::ShapeType::ELLIPSE:
            shapeList.push_back(LoadEllipse(fin, id));
            break;

        case Shape::ShapeType::CIRCLE:
            shapeList.push_back(LoadCircle(fin, id));
            break;

        case Shape::ShapeType::TEXT:
            shapeList.push_back(LoadText(fin, id));
            break;

        default:; //Unknown shape type, return exception?
        }//end switch(shapeType)

    }//end while(fin)


    fin.close();

    return shapeList;
}

Shape* LoadLine(ifstream& fin, int id)
{
    int tempInt;
    string dimensions_s;
    string penColor;
    int penWidth;
    string penStyle;
    string penCapStyle;
    string penJoinStyle;

    Line* newLine = new Line {id, Shape::ShapeType::LINE};

    //Read in a string of ints for line dimensions in format x1, y1, x2, y2
    fin.ignore(10000, ' ');
    getline(fin, dimensions_s);

    //Remove the commas from the string of numbers
    dimensions_s.erase(remove(dimensions_s.begin(), dimensions_s.end(), ','), dimensions_s.end());

    //Create an input string stream object using the string of numbers in format x1 y1 x2 y2
    istringstream sstr(dimensions_s);

    //Read in pen color
    fin.ignore(10000, ' ');
    getline(fin, penColor);

    //Read in pen width
    fin.ignore(10000, ' ');
    fin >> penWidth;

    //Read in pen style
    fin.ignore(10000, ' ');
    getline(fin, penStyle);

    //Read in pen cap style
    fin.ignore(10000, ' ');
    getline(fin, penCapStyle);

    //Read in pen join style
    fin.ignore(10000, ' ');
    getline(fin, penJoinStyle);

    //Set the values of the new line being returned by the function
    newLine->setColor(getColor(penColor));
    newLine->setWidth(penWidth);
    newLine->setStyle(getPenStyle(penStyle));
    newLine->setCapStyle(getPenCapStyle(penCapStyle));
    newLine->setJoinStyle(getPenJoinStyle(penJoinStyle));

    //Read in the ints from the sstr object into tempInt, and then pass
    //	tempInt into the addDemension() function
    while(sstr >> tempInt)
    {
    newLine->addDimension(tempInt);
    }

    return newLine;
}

Shape* LoadPolyline(ifstream& fin, int id)
{
    int tempInt;
    string dimensions_s;
    string penColor;
    int penWidth;
    string penStyle;
    string penCapStyle;
    string penJoinStyle;

    Polyline* newPolyline = new Polyline {id, Shape::ShapeType::POLYLINE};

    //Reading in string of numbers in format x1, y1, ... xn, yn
    fin.ignore(10000, ' ');
    getline(fin, dimensions_s);

    //Remove the commas from the string of numbers
    dimensions_s.erase(remove(dimensions_s.begin(), dimensions_s.end(), ','), dimensions_s.end());

    //Create an input string stream object using the string of numbers in format x1 y1 ... xn yn
    istringstream sstr(dimensions_s);

    //Read in pen color
    fin.ignore(10000, ' ');
    getline(fin, penColor);

    //Read in pen width
    fin.ignore(10000, ' ');
    fin >> penWidth;

    //Read in pen style
    fin.ignore(10000, ' ');
    getline(fin, penStyle);

    //Read in pen cap style
    fin.ignore(10000, ' ');
    getline(fin, penCapStyle);

    //Read in pen join style
    fin.ignore(10000, ' ');
    getline(fin, penJoinStyle);

    //Set the values of the new polyline being returned by the function
    newPolyline->setColor(getColor(penColor));
    newPolyline->setWidth(penWidth);
    newPolyline->setStyle(getPenStyle(penStyle));
    newPolyline->setCapStyle(getPenCapStyle(penCapStyle));
    newPolyline->setJoinStyle(getPenJoinStyle(penJoinStyle));

    //Read in the ints from the sstr object into tempInt, and then pass
    //	tempInt into the addDemension() function
    while(sstr >> tempInt)
    {
    newPolyline->addDimension(tempInt);
    }

    return newPolyline;
}

Shape* LoadPolygon(ifstream& fin, int id)
{
    int tempInt;
    string dimensions_s;
    string penColor;
    int penWidth;
    string penStyle;
    string penCapStyle;
    string penJoinStyle;
    string brushColor;
    string brushStyle;

    Polygon* newPolygon = new Polygon {id, Shape::ShapeType::POLYGON};

    //Reading in string of numbers in format x1, y1, ... xn, yn
    fin.ignore(10000, ' ');
    getline(fin, dimensions_s);

    //Remove the commas from the string of numbers
    dimensions_s.erase(remove(dimensions_s.begin(), dimensions_s.end(), ','), dimensions_s.end());

    //Create an input string stream object using the string of numbers in format x1 y1 ... xn yn
    istringstream sstr(dimensions_s);

    //Read in pen color
    fin.ignore(10000, ' ');
    getline(fin, penColor);

    //Read in pen width
    fin.ignore(10000, ' ');
    fin >> penWidth;

    //Read in pen style
    fin.ignore(10000, ' ');
    getline(fin, penStyle);

    //Read in pen cap style
    fin.ignore(10000, ' ');
    getline(fin, penCapStyle);

    //Read in pen join style
    fin.ignore(10000, ' ');
    getline(fin, penJoinStyle);

    //Read in brush color
    fin.ignore(10000, ' ');
    getline(fin, brushColor);

    //Read in brush style
    fin.ignore(10000, ' ');
    getline(fin, brushStyle);

    //Set the values of the new polyline being returned by the function
    newPolygon->setColor(getColor(penColor));
    newPolygon->setWidth(penWidth);
    newPolygon->setStyle(getPenStyle(penStyle));
    newPolygon->setCapStyle(getPenCapStyle(penCapStyle));
    newPolygon->setJoinStyle(getPenJoinStyle(penJoinStyle));
    newPolygon->setBrush(getColor(brushColor), getBrushStyle(brushStyle));

    //Read in the ints from the sstr object into tempInt, and then pass
    //	tempInt into the addDemension() function
    while(sstr >> tempInt)
    {
    newPolygon->addDimension(tempInt);
    }

    return newPolygon;
}

Shape* LoadRectangle(ifstream& fin, int id)
{
    int tempInt;
    string dimensions_s;
    string penColor;
    int penWidth;
    string penStyle;
    string penCapStyle;
    string penJoinStyle;
    string brushColor;
    string brushStyle;

    Rectangle* newRectangle = new Rectangle {id, Shape::ShapeType::RECTANGLE};

    //Reading in string of numbers in format x1, y1, l, w
    fin.ignore(10000, ' ');
    getline(fin, dimensions_s);

    //Remove the commas from the string of numbers
    dimensions_s.erase(remove(dimensions_s.begin(), dimensions_s.end(), ','), dimensions_s.end());

    //Create an input string stream object using the string of numbers in format x1 y1 l w
    istringstream sstr(dimensions_s);

    //Read in pen color
    fin.ignore(10000, ' ');
    getline(fin, penColor);

    //Read in pen width
    fin.ignore(10000, ' ');
    fin >> penWidth;

    //Read in pen style
    fin.ignore(10000, ' ');
    getline(fin, penStyle);

    //Read in pen cap style
    fin.ignore(10000, ' ');
    getline(fin, penCapStyle);

    //Read in pen join style
    fin.ignore(10000, ' ');
    getline(fin, penJoinStyle);

    //Read in brush color
    fin.ignore(10000, ' ');
    getline(fin, brushColor);

    //Read in brush style
    fin.ignore(10000, ' ');
    getline(fin, brushStyle);

    //Set the values of the new polylinlengthe being returned by the function
    newRectangle->setColor(getColor(penColor));
    newRectangle->setWidth(penWidth);
    newRectangle->setStyle(getPenStyle(penStyle));
    newRectangle->setCapStyle(getPenCapStyle(penCapStyle));
    newRectangle->setJoinStyle(getPenJoinStyle(penJoinStyle));
    newRectangle->setBrush(getColor(brushColor), getBrushStyle(brushStyle));

    //Read in the ints from the sstr object into tempInt, and then pass
    //	tempInt into the addDemension() function
    while(sstr >> tempInt)
    {
    newRectangle->addDimension(tempInt);
    }

    return newRectangle;
}

Shape* LoadSquare(ifstream& fin, int id)
{
    int tempInt;
    string dimensions_s;
    string penColor;
    int penWidth;
    string penStyle;
    string penCapStyle;
    string penJoinStyle;
    string brushColor;
    string brushStyle;

    Rectangle* newSquare = new Rectangle {id, Shape::ShapeType::SQUARE};

    //Reading in string of numbers in format x1, y1, l
    fin.ignore(10000, ' ');
    getline(fin, dimensions_s);

    //Remove the commas from the string of numbers
    dimensions_s.erase(remove(dimensions_s.begin(), dimensions_s.end(), ','), dimensions_s.end());

    //Create an input string stream object using the string of numbers in format x1 y1 l
    istringstream sstr(dimensions_s);

    //Read in pen color
    fin.ignore(10000, ' ');
    getline(fin, penColor);

    //Read in pen width
    fin.ignore(10000, ' ');
    fin >> penWidth;

    //Read in pen style
    fin.ignore(10000, ' ');
    getline(fin, penStyle);

    //Read in pen cap style
    fin.ignore(10000, ' ');
    getline(fin, penCapStyle);

    //Read in pen join style
    fin.ignore(10000, ' ');
    getline(fin, penJoinStyle);

    //Read in brush color
    fin.ignore(10000, ' ');
    getline(fin, brushColor);

    //Read in brush style
    fin.ignore(10000, ' ');
    getline(fin, brushStyle);

    //Set the values of the new polyline being returned by the function
    newSquare->setColor(getColor(penColor));
    newSquare->setWidth(penWidth);
    newSquare->setStyle(getPenStyle(penStyle));
    newSquare->setCapStyle(getPenCapStyle(penCapStyle));
    newSquare->setJoinStyle(getPenJoinStyle(penJoinStyle));
    newSquare->setBrush(getColor(brushColor), getBrushStyle(brushStyle));

    //Read in the ints from the sstr object into tempInt, and then pass
    //	tempInt into the addDemension() function
    while(sstr >> tempInt)
    {
    newSquare->addDimension(tempInt);
    }

    return newSquare;
}

Shape* LoadEllipse(ifstream& fin, int id)
{
    int tempInt;
    string dimensions_s;
    string penColor;
    int penWidth;
    string penStyle;
    string penCapStyle;
    string penJoinStyle;
    string brushColor;
    string brushStyle;

    Ellipse* newEllipse = new Ellipse {id, Shape::ShapeType::ELLIPSE};

    //Reading in string of numbers in format x1, y1, a, b
    fin.ignore(10000, ' ');
    getline(fin, dimensions_s);

    //Remove the commas from the string of numbers
    dimensions_s.erase(remove(dimensions_s.begin(), dimensions_s.end(), ','), dimensions_s.end());

    //Create an input string stream object using the string of numbers in format x1 y1 a b
    istringstream sstr(dimensions_s);

    //Read in pen color
    fin.ignore(10000, ' ');
    getline(fin, penColor);

    //Read in pen width
    fin.ignore(10000, ' ');
    fin >> penWidth;

    //Read in pen style
    fin.ignore(10000, ' ');
    getline(fin, penStyle);

    //Read in pen cap style
    fin.ignore(10000, ' ');
    getline(fin, penCapStyle);

    //Read in pen join style
    fin.ignore(10000, ' ');
    getline(fin, penJoinStyle);

    //Read in brush color
    fin.ignore(10000, ' ');
    getline(fin, brushColor);

    //Read in brush style
    fin.ignore(10000, ' ');
    getline(fin, brushStyle);

    //Set the values of the new polyline being returned by the function
    newEllipse->setColor(getColor(penColor));
    newEllipse->setWidth(penWidth);
    newEllipse->setStyle(getPenStyle(penStyle));
    newEllipse->setCapStyle(getPenCapStyle(penCapStyle));
    newEllipse->setJoinStyle(getPenJoinStyle(penJoinStyle));
    newEllipse->setBrush(getColor(brushColor), getBrushStyle(brushStyle));

    //Read in the ints from the sstr object into tempInt, and then pass
    //	tempInt into the addDemension() function
    while(sstr >> tempInt)
    {
    newEllipse->addDimension(tempInt);
    }

    return newEllipse;
}

Shape* LoadCircle(ifstream& fin, int id)
{
    int tempInt;
    string dimensions_s;
    string penColor;
    int penWidth;
    string penStyle;
    string penCapStyle;
    string penJoinStyle;
    string brushColor;
    string brushStyle;

    Ellipse* newCircle = new Ellipse {id, Shape::ShapeType::CIRCLE};

    //Reading in string of numbers in format x1, y1, a, b
    fin.ignore(10000, ' ');
    getline(fin, dimensions_s);

    //Remove the commas from the string of numbers
    dimensions_s.erase(remove(dimensions_s.begin(), dimensions_s.end(), ','), dimensions_s.end());

    //Create an input string stream object using the string of numbers in format x1 y1 a b
    istringstream sstr(dimensions_s);

    //Read in pen color
    fin.ignore(10000, ' ');
    getline(fin, penColor);

    //Read in pen width
    fin.ignore(10000, ' ');
    fin >> penWidth;

    //Read in pen style
    fin.ignore(10000, ' ');
    getline(fin, penStyle);

    //Read in pen cap style
    fin.ignore(10000, ' ');
    getline(fin, penCapStyle);

    //Read in pen join style
    fin.ignore(10000, ' ');
    getline(fin, penJoinStyle);

    //Read in brush color
    fin.ignore(10000, ' ');
    getline(fin, brushColor);

    //Read in brush style
    fin.ignore(10000, ' ');
    getline(fin, brushStyle);

    //Set the values of the new polyline being returned by the function
    newCircle->setColor(getColor(penColor));
    newCircle->setWidth(penWidth);
    newCircle->setStyle(getPenStyle(penStyle));
    newCircle->setCapStyle(getPenCapStyle(penCapStyle));
    newCircle->setJoinStyle(getPenJoinStyle(penJoinStyle));
    newCircle->setBrush(getColor(brushColor), getBrushStyle(brushStyle));

    //Read in the ints from the sstr object into tempInt, and then pass
    //	tempInt into the addDemension() function
    while(sstr >> tempInt)
    {
    newCircle->addDimension(tempInt);
    }

    return newCircle;
}

Shape* LoadText(ifstream& fin, int id)
{
    int tempInt;
    string dimensions_s;
    string text_s;
    string textColor;
    string textAlignment;
    qreal textPointSize;
    string textFontFamily;
    string textFontStyle;
    string textFontWeight;

    Text* newText = new Text {id, Shape::ShapeType::TEXT};

    //Reading in string of numbers in format x1, y1, l, w
    fin.ignore(10000, ' ');
    getline(fin, dimensions_s);

    //Remove the commas from the string of numbers
    dimensions_s.erase(remove(dimensions_s.begin(), dimensions_s.end(), ','), dimensions_s.end());

    //Create an input string stream object using the string of numbers in format x1 y1 l w
    istringstream sstr(dimensions_s);

    //Read in text string
    fin.ignore(10000, ' ');
    getline(fin, text_s);
    QString text_qs = QString::fromStdString(text_s);

    //Read in text color
    fin.ignore(10000, ' ');
    getline(fin, textColor);

    //Read in text allignment
    fin.ignore(10000, ' ');
    getline(fin, textAlignment);

    //Read in text point size
    fin.ignore(10000, ' ');
    fin >> textPointSize;

    //Read in text font family
    fin.ignore(10000, ' ');
    getline(fin, textFontFamily);
    QString fontFamily_qs = QString::fromStdString(textFontFamily);

    //Read in text font style
    fin.ignore(10000, ' ');
    getline(fin, textFontStyle);

    //Read in textFontWeight
    fin.ignore(10000, ' ');
    getline(fin, textFontWeight);

    //Set the values of the new polyline being returned by the function
    newText->setText(text_qs);
    newText->setTColor(getColor(textColor));
    newText->setAlignment(getAlignment(textAlignment));
    newText->setPointSize(textPointSize);
    newText->setFontFamily(fontFamily_qs);
    newText->setFontStyle(getFontStyle(textFontStyle));
    newText->setFontWeight(getFontWeight(textFontWeight));

    //Read in the ints from the sstr object into tempInt, and then pass
    //	tempInt into the addDemension() function
    while(sstr >> tempInt)
    {
    newText->addDimension(tempInt);
    }

    return newText;
}

Qt::GlobalColor getColor(const string& objColor)
{
    if(objColor == "white")
    {
        return Qt::white;
    }
    else if(objColor == "black")
    {
        return Qt::black;
    }
    else if(objColor == "red")
    {
        return Qt::red;
    }
    else if(objColor == "green")
    {
        return Qt::green;
    }
    else if(objColor == "blue")
    {
        return Qt::blue;
    }
    else if(objColor == "cyan")
    {
        return Qt::cyan;
    }
    else if(objColor == "magenta")
    {
        return Qt::magenta;
    }
    else if(objColor == "yellow")
    {
        return Qt::yellow;
    }
    else if(objColor == "gray")
    {
        return Qt::gray;
    }
}

Qt::PenStyle getPenStyle(const string& style){
    if(style == "NoPen")
    {
        return Qt::NoPen;
    }
    else if(style == "SolidLine")
    {
        return Qt::SolidLine;
    }
    else if(style == "DashLine")
    {
        return Qt::DashLine;
    }
    else if(style == "DotLine")
    {
        return Qt::DotLine;
    }
    else if(style == "DashDotLine")
    {
        return Qt::DashDotLine;
    }
    else if(style == "DashDotDotLine")
    {
        return Qt::DashDotDotLine;
    }
}

Qt::PenCapStyle getPenCapStyle(const string& style){
    if(style == "FlatCap")
    {
        return Qt::FlatCap;
    }
    else if(style == "SquareCap")
    {
        return Qt::SquareCap;
    }
    else if(style == "RoundCap")
    {
        return Qt::RoundCap;
    }
}

Qt::PenJoinStyle getPenJoinStyle(const string& style){
    if(style == "MiterJoin")
    {
        return Qt::MiterJoin;
    }
    else if(style == "BevelJoin")
    {
        return Qt::BevelJoin;
    }
    else if(style == "RoundJoin")
    {
        return Qt::RoundJoin;
    }
}

Qt::BrushStyle getBrushStyle(const string& style){
    if(style == "SolidPattern")
    {
        return Qt::SolidPattern;
    }
    else if(style == "HorPattern")
    {
        return Qt::HorPattern;
    }
    else if(style == "VerPattern")
    {
        return Qt::VerPattern;
    }
    else if(style == "NoBrush")
    {
        return Qt::NoBrush;
    }
}

Qt::Alignment getAlignment(const string& alignment)
{
    if(alignment == "AlignLeft")
    {
        return Qt::AlignLeft;
    }
    else if(alignment == "AlignRight")
    {
        return Qt::AlignRight;
    }
    else if(alignment == "AlignTop")
    {
        return Qt::AlignTop;
    }
    else if(alignment == "AlignBottom")
    {
        return Qt::AlignBottom;
    }
    else if(alignment == "AlignCenter")
    {
        return Qt::AlignCenter;
    }
}

QFont::Style getFontStyle(const string& style){
    if(style == "StyleNormal")
    {
        return QFont::StyleNormal;
    }
    else if(style == "StyleItalic")
    {
        return QFont::StyleItalic;
    }
    else if(style == "StyleOblique")
    {
        return QFont::StyleOblique;
    }
}

QFont::Weight getFontWeight(const string& style){
    if(style == "Thin")
    {
        return QFont::Thin;
    }
    else if(style == "Light")
    {
        return QFont::Light;
    }
    else if(style == "Normal")
    {
        return QFont::Normal;
    }
    else if(style == "Bold")
    {
        return QFont::Bold;
    }
}

