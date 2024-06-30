#include <stdio.h>

/*
	Developed by: James Ald Teves

	Silliman University
	Programming Assignment in CCS 2 - B

	Description: Asterisk
*/

int main() {
	
	//Initialization
	int a, b, given;
	
	//UserInput
	printf("Enter an Integer: ");
	scanf("%d", &given);
	
	//Process
	for (a = 0; a < given; a++) {
		
		for (b = 0; b < given; b++) {
		printf("*");
		}
			
	printf("\n");
	}
}
