/*
    Description: Simulation about Polymorphism.
    Programmed by: James Ald Teves
    BS Computer Science

    Instructor: Assist. Prof. Allan V. Credo
    Star: December 9, 2022
    End: December 9, 2022
*/

// Preprocessor Directives
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define NEWLINE 'n';
using namespace std;

class Shape
{
protected:
    double area;
    double volume;

public:
    Shape() : area(0.00), volume(0.00) {}
    Shape(double Ar, double Vol) : area(Ar), volume(Vol) {}

    virtual void Display()
    {
        cout << "\n\t Area: " << area << endl;
        cout << "\n\t Volume: " << volume << endl;
    }

    virtual void calculateArea() = 0;
    virtual void calculateVolume() = 0;
};

class Point : public Shape
{
protected:
    int positionA;
    int positionB;

public:
    Point(int a = 0, int b = 0) : positionA(a), positionB(b) {}

    void setPositionA(int a)
    {
        positionA = a;
    }

    void setPositionB(int b)
    {
        positionB = b;
    }

    void calculateArea() override
    {
        // Specific logic for calculating area of a Point
        area = 0; // Point has no area
    }

    void calculateVolume() override
    {
        // Specific logic for calculating volume of a Point
        volume = 0; // Point has no volume
    }

    void Display() override
    {
        Shape::Display();
        cout << "\n\t Position A: " << positionA << endl;
        cout << "\n\t Position B: " << positionB << endl;
    }
};

class Circle : public Point
{
private:
    double radius;

public:
    Circle(double r = 0.0) : Point(), radius(r) {}

    void setRadius(double r)
    {
        radius = r;
    }

    void calculateArea() override
    {
        area = 3.14 * radius * radius;
    }

    void calculateVolume() override
    {
        volume = 0; // Circle has no volume
    }

    void Display() override
    {
        Point::Display();
        cout << "\n\t Radius: " << radius << endl;
    }
};

int main()
{
    Circle circle(5.0);
    circle.calculateArea();
    circle.calculateVolume();
    circle.Display();

    return 0;
}