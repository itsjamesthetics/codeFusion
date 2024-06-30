/*
	Developed by: James Ald Teves
	BS Compupter Science

	Instructor: Assist. Prof. Allan V. Credo
	Laboratory 3
	Description: This program enables you to increase and decrease temperature with a set value of 15 using OOP.
*/

#include <iostream>
#include <string>
#include <conio.h>
#define NEWLINE '\n';
using namespace std;

class Heater
{

private:
	int temperature, min, max, increment;

public:
	Heater()
	{

		int temperature, increment, minimum, maximum;
		int min = minimum;
		int max = maximum;
	}

	void Warmer()
	{

		int TempIncrease;
		int Increase = 5;
		int temperature = 15;
		TempIncrease = temperature + Increase;
		if (TempIncrease <= max)
		{
			cout << "\n Increased Temperature: " << TempIncrease << endl;
		}
	}

	void Cooler()
	{

		int TempDecrease;
		int Decrease = 5;
		int temperature = 15;
		TempDecrease = temperature - Decrease;
		if (TempDecrease >= min)
		{
			cout << "\n Decreased Temperature: " << TempDecrease << endl;
		}
	}

	int getTemp()
	{
		return temperature;
	}

	int setIncrement()
	{
		int i;
		if (i >= 0)
		{
			increment = i;
		}
	}
};

int main()
{

	Heater heater;

	cout << "\n\t\t Fixed Temperature: " << 15 << endl;
	cout << "\n\t\t\t Menu " << endl;
	cout << "\n 1. Increase Temperature " << endl;
	cout << "\n 2. Decrease Temperature " << endl;
	cout << "\n 3. View Data's Temperature " << endl;

	Heater object;
	int Choice;

	cout << "\n Select your Choice: " << endl;
	cin >> Choice;

	switch (Choice)
	{

	case 1:
		object.Warmer();
		break;
	case 2:
		object.Cooler();
		break;
	case 3:
		object.setIncrement();
		object.Warmer();
		object.Cooler();
		break;
	default:
		cout << "\n Invalid! Try 1-3 Choices only..." << endl;
		cout << "\n Try againn" << endl;
		cout << "\n\n" << endl;
		system("pause");
		system("cls");
		main();
		getch();
	}
	return 0;
}