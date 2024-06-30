/*
	Developed by: James Ald Teves
	BS Computer Science
	Instructor: Assist. Prof. Allan V. Credo

	Laboratory 4
	Description: This is a modified program that enables you to increase and decrease temperature with whatever detail's you want using OOP.
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

		int temperature, increment, min, max;
	}

	void Warmer()
	{

		int max = 80;
		int min = 5;
		int newTemp;
		int TempIncrease;
		int temperature = 15;
		cout << "\n Enter the value to increase temperature: " << endl;
		cin >> TempIncrease;
		newTemp = temperature + TempIncrease;

		if (newTemp <= max)
		{
			cout << "\n The Increased Temperature: " << newTemp << endl;
		}

		else if ((newTemp < min || newTemp > max))
		{
			cout << "\n Invalid... Too high or low! " << endl;
			cout << "\n Please Try again... " << endl;
			cout << "\n\n"
				 << endl;
			system("pause");
			system("cls");
			Warmer();
			getch();
			return;
		}

		else
		{
			cout << "\n Invalid! " << endl;
		}
	}

	void Cooler()
	{

		int max = 80;
		int min = 5;
		int newTemp;
		int TempDecrease;
		int temperature = 15;

		cout << "\n Enter the value to decrease temperature: " << endl;
		cin >> TempDecrease;
		newTemp = temperature - TempDecrease;

		if (newTemp >= min)
		{
			cout << "\n The Decreased Temperature: " << newTemp << endl;
		}

		else if ((newTemp < min || newTemp > max))
		{
			cout << "\n Invalid... Too high or low! " << endl;
			cout << "\n Please Try again... " << endl;
			cout << "\n\n"
				 << endl;
			system("pause");
			system("cls");
			Cooler();
			getch();
			return;
		}

		else
		{
			cout << "\n Invalid! " << endl;
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

	cout << "\n\t\t Fixed Temperature: " << 15 << endl;
	cout << "\n\t\t\t Menu " << endl;
	cout << "\n 1. Increase Temperature (Max: 80/ Min: 5) " << endl;
	cout << "\n 2. Decrease Temperature (Max: 80/ Min: 5) " << endl;
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
		cout << "\n\n"
			 << endl;
		system("pause");
		system("cls");
		main();
		getch();
	}
	return 0;
}