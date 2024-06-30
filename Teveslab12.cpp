/*
    Programmed by: James Ald Teves
    BS Computer Science

    Instructor: Assist. Prof. Allan Credo
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
    Shape();
    Shape(double Ar, double Vol);
    void Display();

    void setArea(double Ar)
    {
        area = Ar;
    }

    void setVolume(double Vol)
    {
        volume = Vol;
    }
};

Shape::Shape() : area(0.00), volume(0.00) {}
Shape::Shape(double Ar, double Vol) : area(Ar), volume(Vol) {}

void Shape::Display()
{
    cout << "\n\t Area: " << area << endl;
    cout << "\n\t Volume: " << volume << endl;
}

class Point : public Shape
{
private:
    int positionA;
    int positionB;

public:
    Point();
    Point(int a, int b);

    void setPointA()
    {
        cout << "\n\t Set Point A: ";
        cin >> positionA;
    }

    void setPointB()
    {
        cout << "\n\t Set Point B: ";
        cin >> positionB;
    }

    void calculateArea()
    {                              // Assuming some calculation based on positionA and positionB
        double computedArea = 0.0; // Replace with actual calculation
        setArea(computedArea);
    }

    void calculateVolume()
    {                                // Assuming some calculation based on positionA and positionB
        double computedVolume = 0.0; // Replace with actual calculation
        setVolume(computedVolume);
    }

    void PointDisplay()
    {
        Shape::Display();
        cout << "\n\t Point A: " << positionA << endl;
        cout << "\n\t Point B: " << positionB << endl;
    }
};

Point::Point() : positionA(0), positionB(0) {}
Point::Point(int a, int b) : positionA(a), positionB(b) {}

int main()
{
    // Example usage
    Point myPoint;
    myPoint.setPointA();
    myPoint.setPointB();
    myPoint.calculateArea();
    myPoint.calculateVolume();
    myPoint.PointDisplay();

    return 0;
}