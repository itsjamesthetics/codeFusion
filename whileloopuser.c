#include <stdio.h>
#include <stdlib.h>

/*
	Developed by: James Ald Teves

	Silliman University
	Programming Assignment in CCS 2 - B

	Description: A while loop activity.
*/

int main(){
	
	//Initialization
	int first,second;
	
	//User Input
	printf("Enter first number: ");
	scanf("%i", &first);
	
	printf("Enter second number: ");
	scanf("%i", &second);
	
	//Condition if first is less than  second
	if(first < second){	
	
	//Condition for listing all in between numbers
	
		int a = first;
		printf("\nAll numbers between inputted value in ascending order:\n");
		while(a <= second)
		{
			printf("%i ",a);
			a++;
		}
			
	//Condition for even numbers
		int b = first;
		int sum = 0;
		printf("\n\nAll even numbers between inputted value in ascending order:\n");
		
		while(b <= second)
		{
			int c = b % 2;
			if( c == 0)
			{
				printf("%i ",b);
				sum = sum + b;
				b++;
			}
			else
			{
				b++;
			}
		}
		
		//Display sum of even number in between
		printf("\n\nThe sum of all the even numbers in between inputted values:\n");
		printf("%i ",sum);
		
	}

	//Condition if second is less than  first
	else
	{	
	//Condition for listing all in between numbers
		int a = second;
		printf("\nAll numbers between inputted value in ascending order:\n");
		
		while(a <= first)
		{
			printf("%i ",a);
			a++;
		}
	
	//Condition for even numbers	
		int b = second;
		int sum = 0;
		printf("\n\nAll even numbers between inputted value in ascending order:\n");
		
		while(b <= first)
		{
			int c = b % 2;
			if( c == 0)
			{
				printf("%i ",b);
				sum = sum + b;
				b++;
			}
			else
			{
				b++;
			}
		}
		
		//Display sum of even number in between
		printf("\n\nThe sum of all the even numbers in between inputted values:\n");
		printf("%i ",sum);
	}
}
