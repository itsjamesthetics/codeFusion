/*
    Developed by: James Ald Teves
    BS Computer Science

    Description: Multiplying two floating point numbers
*/

// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Main Function
int main()
{

    // Declarations
    float num1, num2, totalNum;
    char choice;

    do
    {

        printf("\n\t\tMultiplying Two Floating Point Numbers\n");

        // First input
        printf("\n\tEnter first number: ");
        scanf("%f", &num1); // Corrected format specifier

        // Clear input buffer
        while (getchar() != '\n')
            ;

        // Second input
        printf("\n\tEnter second number: ");
        scanf("%f", &num2); // Corrected format specifier

        // Clear input buffer
        while (getchar() != '\n')
            ;

        // Multiplication
        totalNum = num1 * num2;

        // Display result
        printf("\n\tThe product of the two numbers is: %.2f\n", totalNum);

        // Ask user if they want to perform another multiplication
        printf("\n\tDo you want to multiply another two numbers? (Y/N): ");
        choice = getchar();

    } while (tolower(choice == 'y'));
    return 0;
}