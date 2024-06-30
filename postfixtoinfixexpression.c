/*
	Developed by: James Ald Teves
	BS Computer Science
	Instructor: Dr. Chuchi S. Montenegro

	Description: Converting from Postfix to Infix expression using Stacks.
	Started: February 13, 2023
	End: February 16, 2023;
*/

// Directives Preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <ctype.h>
#define S 25

// Stack Functions
void Push(char);
char Pop();
bool isFull();

// Utility Functions
void ConvertToInfix(char postExp[]);
bool isOperand(char);
bool isOperator(char);
float EvaluatePostfix(char postExp[]);

// Global Stack
char Stack[S];
int top = -1;

// Push
void Push(char ch)
{
	Stack[++top] = ch;
}

// Pop
char Pop()
{
	return Stack[top--];
}

// Conversion
void Convert(char postExp[])
{

	int length, i, k = 0;
	char Temp[S];
	strrev(postExp);
	length = strlen(postExp);

	for (i = 0; i < 50; i++)
		Stack[i] = '\0';

	printf("\n\t The Infix Expression is: ");
	for (i = 0; i < length; i++)
	{
		if (postExp[i] == '+' || postExp[i] == '-' || postExp[i] == '*' || postExp[i] == '/')
		{
			Push(postExp[i]);
		}
		else
		{
			Temp[k++] = postExp[i];
			Temp[k++] = Pop();
		}
	}

	Temp[k] = postExp[top--];
	strrev(Temp);
	puts(Temp);
}

// Solve
float Solve(char postExp[])
{

	float total = 0, Infix[S], Operator_1, Operator_2;
	int i, sTop = -1;

	for (i = 0; i < strlen(postExp); i++)
	{
		if (isOperand(postExp[i]))
		{
			sTop++;
			Infix[sTop] = postExp[i] - '0';
		}
		else if (isOperator(postExp[i]))
		{
			Operator_2 = Infix[sTop--];
			Operator_1 = Infix[sTop--];

			switch (postExp[i])
			{

			case '+':
				total = Operator_1 + Operator_2;
				break;

			case '-':
				total = Operator_1 - Operator_2;
				break;

			case '*':
				total = Operator_1 * Operator_2;
				break;

			case '/':
				total = Operator_1 / Operator_2;
				break;

			default:
				printf("\n\t The Expression is Invalid! ");
				getch();
			}
			Infix[++sTop] = total;
		}
		else if (postExp[i] == ' ' || postExp[i] == '\0')
		{
		}
		else
		{
			printf("\n\t Invalid Expression! ");
			getch();
		}
	}
	printf("\n\t The Result is %.2f ", Infix[sTop]);
	getch();
}

// Check if Operand
bool isOperand(char Operand)
{

	bool isOperand = false;
	if (isdigit(Operand))
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Check if Operator
bool isOperator(char Operator)
{
	return Operator == '+' || Operator == '-' || Operator == '*' || Operator == '/';
}

// Main Driver
int main()
{

	char postExp[S], newString[S];
	printf("\n\t Enter Postfix Expression: ");
	gets(postExp);
	strcpy(newString, postExp);
	Convert(postExp);
	Solve(newString);
	return 0;
}