/*	Developed by: James Ald Teves
    BS Computer Science
    Pointer Calculator

    Description: This programs enables you to make a calculator or
    perform operations using a function(s).
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

// Function Declaration
void Addition(int a, int b);
void Multiplication(int a, int b);
void Division(int a, int b);
void Subtraction(int a, int b);

int main()
{
    int firstNum, secNum;
    char cont;

    do
    {
        printf("\n Enter first integer: ");
        scanf("%d", &firstNum);
        printf("\n Enter second integer: ");
        scanf("%d", &secNum);

        printf("\n\t Results: ");
        printf("\n Addition: ");
        Addition(firstNum, secNum);
        printf("\n Multiplication: ");
        Multiplication(firstNum, secNum);
        if (secNum != 0)
        {
            printf("\n Division: ");
            Division(firstNum, secNum);
        }
        else
        {
            printf("\n Division: Undefined (divisor is 0)");
        }
        printf("\n Subtraction: ");
        Subtraction(firstNum, secNum);

        printf("\n\n Do you want to continue? (Y/N): ");
        scanf(" %c", &cont);
    } while (toupper(cont) == 'Y');

    return 0;
}

void Addition(int a, int b)
{
    printf("%d", a + b);
}

void Multiplication(int a, int b)
{
    printf("%d", a * b);
}

void Division(int a, int b)
{
    printf("%d", a / b);
}

void Subtraction(int a, int b)
{
    printf("%d", a - b);
}