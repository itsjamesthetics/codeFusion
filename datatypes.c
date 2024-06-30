#include <stdio.h>
#include <stdlib.h>

/*
	Developed by: James Ald Teves

	Silliman University
	Programming Assignment in CCS 2 - B

	Description: Grocery
*/

main()
{

	// User Input
	printf("Name: James\n");
	int x;
	x = 18;
	printf("Age is %d\n", x);
	printf("Grocery list:  \n");

	// First Item
	int a;
	a = 1;
	float b;
	b = 19.99;
	printf("%d Chippy %f\n", a, b);

	// Second Item
	int c;
	c = 5;
	float d;
	d = 100.25;
	printf("%d Lucky Me %f\n", c, d);

	// Third Item
	int e;
	e = 2;
	float f;
	f = 84.75;
	printf("%d Head and Shoulders %f\n", e, f);

	// Fourth Item
	int g;
	g = 2;
	float h;
	h = 40.24;
	printf("%d Green Cross Alcohol %f\n", g, h);

	// Last Item
	int i;
	i = 1;
	float j;
	j = 34.80;
	printf("%d Colgate Toothpaste %f\n", i, j);
}
