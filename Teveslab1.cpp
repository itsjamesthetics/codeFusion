/*
	Developed by: James Ald Teves
	BS Computer Science
	Comp Scie 23 - B

	Lab 1
	Instructor: Assist. Prof. Allan V. Credo
*/

// Preprocessor Directives
#include <iostream>
#include <conio.h>
#define NEWLINE '\n';
using namespace std;

// Functions declarations
double power(double n, int p = 2);

// Main Driver
int main(void)
{

	int newPow;
	int result = 1;
	int i;
	double integer;
	char choice;

	do
	{

		cout << "\n\t\t\t\t Find the Power of an Integer " << endl;
		cout << "\n\t Enter the number: " << endl;
		cin >> integer;
		cout << "\n\t Do you want to power (Y/N): " << endl;
		cin >> choice;

		if (choice == 'Y' || choice == 'y')
		{

			cout << "\n\t Enter power to be raise: " << endl;
			cin >> newPow;

			result = power(integer, newPow);
			cout << integer << " ^ " << newPow << " = " << result << endl;
		}

		else if (choice == 'N' || choice == 'n')
		{

			result = power(integer);
			cout << integer << " ^ " << " 2 " << " integer " << " = " << result << endl;
			getch();
			system("cls");
			main();
		}
		else
		{
			cout << "\n Invalid!" << endl;
			getch();
			system("cls");
			main();
		}

	} while (choice == 'Y' || choice == 'y');

	return 0;
}

double power(double n, int p)
{

	int i;
	double newNum;
	double plus;

	newNum = n;

	if (p >= 0)
	{

		for (i = 1; i < p; i++)
		{
			n = n * newNum;
		}
	}
	else if (p < 0)
	{

		plus = p * -1;
		for (i = 0; i < plus + 1; i++)
		{
			n = n / newNum;
		}
	}
	return n;
}