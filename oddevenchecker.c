/*
    Developed by: James Ald Teves
    BS Computer Science

    Description: This program will correctly calculate and display the sum, minimum, total of positive even numbers,
    and display each positive even number in the array.
*/

#include <stdio.h>
#include <stdlib.h>

// Function Definition
#define size 10
int sum(int a[size]);
int min(int a[size]);
int totalPositiveEven(int a[size]);
void displayPositiveEven(int a[size]);

int main()
{
    int ar[size];
    for (int x = 0; x < size; x++)
    {
        printf("Enter value in index[%d]: ", x);
        scanf("%d", &ar[x]);
    }

    printf("\nThe array elements are:\n");
    for (int x = 0; x < size; x++)
    {
        printf("%d\t", ar[x]);
    }

    printf("\nThe total number in an array is: %d", sum(ar));
    printf("\nThe minimum number in an array is: %d", min(ar));
    printf("\n*** List of all positive even numbers ***\n");
    printf("The total of positive even numbers in the array is: %d", totalPositiveEven(ar));
    printf("\nPositive Even Numbers:\n");
    displayPositiveEven(ar);
    // Add similar sections for other types of numbers as needed.

    return 0;
}

int sum(int a[size])
{
    int total = 0;
    for (int x = 0; x < size; x++)
    {
        total += a[x];
    }
    return total;
}

int min(int a[size])
{
    int minVal = a[0];
    for (int x = 1; x < size; x++)
    {
        if (a[x] < minVal)
        {
            minVal = a[x];
        }
    }
    return minVal;
}

int totalPositiveEven(int a[size])
{
    int total = 0;
    for (int x = 0; x < size; x++)
    {
        if (a[x] > 0 && a[x] % 2 == 0)
        {
            total += a[x];
        }
    }
    return total;
}

void displayPositiveEven(int a[size])
{
    for (int x = 0; x < size; x++)
    {
        if (a[x] > 0 && a[x] % 2 == 0)
        {
            printf("%d\t", a[x]);
        }
    }
}