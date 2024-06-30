#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

/*
	Developed by: James Ald Teves

	A simple program that uses a do while loop that also
	has a user input to manipulate and display data in ascending order.
*/

int main()
{

	//Initialization of variables first and second
	int first, second;

	//User Input
	printf("Enter first number: ");
	scanf("%i", &first);

	printf("Enter second number: ");
	scanf("%i", &second);

	//Condition if first is less than  second
	if (first < second)
	{

		//Condition for listing all in between numbers
		int a = first;
		printf("\nAll numbers between inputted value in ascending order:\n");
		do
		{
			printf("%i ", a);
			a++;
		} while (a <= second);

		//Condition for even numbers
		int b = first;
		int sum = 0;
		printf("\n\nAll even numbers between inputted value in ascending order:\n");

		do
		{
			int c = b % 2;
			if (c == 0)
			{
				printf("%i ", b);
				sum = sum + b;
				b++;
			}
			else
			{
				b++;
			}
		} while (b <= second);

		//Display sum of even number in between
		printf("\n\nThe sum of all the even numbers in between inputted values:\n");
		printf("%i ", sum);
	}

	//Condition if second is less than  first
	else
	{
		//Condition for listing all in between numbers

		int a = second;
		printf("\nAll numbers between inputted value in ascending order:\n");
		do
		{
			printf("%i ", a);
			a++;
		} while (a <= first);

		//Condition for even numbers

		int b = second;
		int sum = 0;
		printf("\n\nAll even numbers between inputted value in ascending order:\n");
		do
		{
			int c = b % 2;
			if (c == 0)
			{
				printf("%i ", b);
				sum = sum + b;
				b++;
			}
			else
			{
				b++;
			}
		} while (b <= first);

		//Display sum of even number in between
		printf("\n\nThe sum of all the even numbers in between inputted values:\n");
		printf("%i ", sum);
	}
}
