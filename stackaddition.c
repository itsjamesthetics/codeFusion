/*
	Programmed by: James Ald Teves
	BS Computer Science
	COMPSCI 22 - A
	Instructor: Dr. Chuchi S. Montenegro

	Description: Addition of large numbers using stack operation.
	Started: February 6, 2023
	End: February 9, 2023
*/

// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

// Main Driver
int main()
{

	// Local Variable Declaration
	int topStack1[255], topStack2[255], Sum[255];
	char Stack1[255], Stack2[255];
	int L1, L2;
	int carry = 0;

	// User Input
	printf("\n\t Enter First Integers: ");
	scanf("%s", &Stack1);
	fflush(stdin);

	printf("\n\t Enter Second Integers: ");
	scanf("%s", &Stack2);
	fflush(stdin);

	// Character to Integer Conversion
	for (L1 = 0; Stack1[L1] != '\0'; L1++)
		topStack1[L1] = Stack1[L1] - '0';

	for (L2 = 0; Stack2[L2] != '\0'; L2++)
		topStack2[L2] = Stack2[L2] - '0';

	int k = 0;
	int i = L1 - 1;
	int j = L2 - 1;

	for (; i >= 0 && j >= 0; i--, j--, k++)
	{
		Sum[k] = (topStack1[i] + topStack2[j] + carry) % 10;
		carry = (topStack1[i] + topStack2[j] + carry) / 10;
	}
	if (L1 > L2)
	{
		while (i >= 0)
		{
			Sum[k] = (topStack1[i] + carry) % 10;
			carry = (topStack1[i--] + carry) / 10;
		}
	}
	else if (L1 < L2)
	{
		while (j >= 0)
		{
			Sum[k++] = (topStack2[j] + carry) % 10;
			carry = (topStack2[j--] + carry) / 10;
		}
	}
	else
	{
		if (carry > 0)
			Sum[k++] = carry;
	}

	// Display
	printf("\n\t The result: ");
	for (k--; k >= 0; k--)
	{
		printf("%d", Sum[k]);
	}

	return 0;
}