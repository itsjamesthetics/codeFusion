/*
	Developed by: James Ald Teves
	BS Computer Science

	Instructor: Assist. Prof. Allan V. Credo
	Laboratory 6
	Description: This program uses constructor and it enables you to input two Distance, which will together be added in the Display.
*/

// Preprocessor Directives
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#define NEWLINE '\n'
using namespace std;

class Distance
{

	int feet;
	int inches;

public:
	Distance();
	Distance(int ft, int in);
	Distance AddDistance(Distance d2);
	void Display();

	bool isGreater(Distance d2)
	{

		return this->feet;
		if (feet > d2.feet)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isSmaller(Distance d2)
	{

		return this->feet;
		if (feet < d2.feet)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isGreaterEqual(Distance d2)
	{

		return this->feet;
		if (feet >= d2.feet)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isSmallerEqual(Distance d2)
	{

		return this->feet;
		if (feet <= d2.feet)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isEquall(Distance d2)
	{

		return this->feet;
		if (feet == d2.feet)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isNotEqual(Distance d2)
	{

		return this->feet;
		if (feet != d2.feet)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

Distance::Distance() : feet(0), inches(0) {}
Distance::Distance(int ft, int in) : feet(ft), inches(in) {}

Distance Distance::AddDistance(Distance d2)
{

	Distance temp;
	temp.feet = this->feet + d2.feet;
	temp.inches = this->inches + d2.inches;
	if (temp.inches > 12)
	{
		temp.inches = temp.inches - 12;
		temp.feet++;
	}
	return temp;
}

void Distance::Display()
{

	cout << "\n\t Added Distance" << endl;
	cout << "\n\t Feet: " << feet << endl;
	cout << "\t Inches: " << inches << endl;
}

int main()
{

	Distance d1(5, 10);
	Distance d2(5, 5);
	Distance d3;

	d3 = d1.AddDistance(d2);
	d3.Display();

	if (d1.isGreater(d2))
	{
		cout << "\n\t Distance 1 is greater than Distance 2" << endl;
	}

	return 0;
}