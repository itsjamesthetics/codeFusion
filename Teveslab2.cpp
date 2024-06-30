/*
	Developed by: James Ald Teves
	BS Computer Science
	Comp Scie 23 - B
	Laboratory 2

	Instructor: Assist. Prof. Allan V. Credo
	Date Programmed: September 27, 2022
	Date Finished: September 27, 2022
	Description: This program enables you to solve Rectangle's Area and Parameter by inputting specified Width and Length.
*/

// Preprocessor Directives
#include <iostream>
#include <conio.h>
#define NEWLINE '\n'
using namespace std;

// Class name
class Rectangle
{

	float length, width, Area, Perimeter;

public:
	Rectangle()
	{

		width = 1;
		length = 1;
		Area = 0;
		Perimeter = 0;
	}

	void setWidth()
	{

		cout << "\n\t Set the width of Rectangle: " << endl;
		cin >> width;

		if ((width <= 0.00 || width >= 20.0))
		{
			cout << "\n\t\tInvalid Inputted Data... " << endl;
			cout << "\t\tTry again... " << endl;
			setWidth();
			getch();
		}
	}
	double getWidth()
	{
		return width;
	}

	void setLength()
	{
		cout << "\n\t Set the lenght of the Rectangle: " << endl;
		cin >> length;

		if ((length <= 0.00 || length >= 20.0))
		{
			cout << "\n\t\tInvalid Inputted Data... " << endl;
			cout << "\t\tTry again... " << endl;
			setLength();
			getch();
		}
	}

	double getLength()
	{
		return length;
	}

	void Calculate()
	{
		Area = length * width;
		Perimeter = 2 * (length + width);
	}

	void ViewDisplay()
	{
		cout << "\n\t Area of the Rectangle is: " << Area << endl;
		cout << "\n\t Perimeter of the Rectangle is: " << Perimeter << endl;
	}
};

// Main Driver
int main()
{

	Rectangle rec;
	char again;

	rec.setWidth();
	rec.getWidth();
	rec.setLength();
	rec.getLength();
	rec.Calculate();
	rec.ViewDisplay();

Try:
	cout << "\n\t Try again? (Y/N): " << endl;
	cin >> again;

	if ((again == 'Y' || again == 'y'))
	{
		main();
		getch();
	}

	else if ((again == 'N' || again == 'n'))
	{
		cout << "\n\t Program Terminated! " << endl;
		exit(1);
	}

	else
	{
		cout << "\n\t Invalid! " << endl;
		cout << "\n\t Try again..." << endl;
		goto Try;
	}

	return 0;
}