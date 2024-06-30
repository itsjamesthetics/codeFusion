/*
    Developed by: James Ald Teves
    BS Computer Science
    Instructor: Assist. Prof. Allan V. Credo

    Start: November 29, 2022
    End: November 29, 2022
*/

// Preprocessor Directives
#include <iostream>
#include <conio.h>
#define NEWLINE 'n';
#define PI 3.14
using namespace std;

class Point
{

protected:
    int x;
    int y;

public:
    Point();
    Point(int Xcoord, int Ycoord);
    void Display();

    void setX(int Xcoord)
    {
        x = Xcoord;
    }
    void setY(int Ycoord)
    {
        y = Ycoord;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
};

Point::Point() : x(0), y(0) {}
Point::Point(int Xcoord, int Ycoord) : x(Xcoord), y(Ycoord) {}
void Point::Display()
{
    cout << "\n\t X Coordinate: " << x;
    cout << " Y Coordinate: " << y << endl;
}

class Circle : public Point
{

protected:
    double radius;

public:
    Circle() : Point(0, 0)
    {

        radius = 0.00;
    }

    Circle(double r, int Xcoord, int Ycoord) : Point(x, y)
    {

        radius = r;
        x = Xcoord;
        y = Ycoord;
    }

    Circle(double r, Point center)
    {

        radius = r;
        x = center.getX();
        y = center.getY();
    }

    void setRadius(int rad)
    {
        radius = rad;
    }

    int getRadius()
    {
        return radius;
    }

    double area()
    {
        return PI * radius * radius;
    }

    double Circumference()
    {
        return 2 * PI * radius;
    }

    void DisplayArea();
    void DisplayCircumference();
};

void Circle::DisplayArea()
{
    cout << "\n\t Area: " << Circle::area() << endl;
}

void Circle::DisplayCircumference()
{
    cout << "\n\t Circumference: " << Circle::Circumference() << endl;
}

int main()
{

    Point p(4, 3);
    Point d(4, 9);
    Circle c(2.5, 4, 5);
    Circle z(3.00, d);

    cout << "\n\t Point Coordinates: " << endl;
    p.Display();
    cout << "\n\t Center Coordinates: " << endl;
    c.Display();
    c.DisplayArea();
    c.DisplayCircumference();
    cout << "\n\t Other Coordinates: " << endl;
    d.Display();
    z.DisplayArea();
    z.DisplayCircumference();

    return 0;
}
