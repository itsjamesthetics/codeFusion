#include <stdio.h>
#include <stdlib.h>

/*
	Developed by: James Ald Teves

	A program that uses to calculate BMI.
*/

// Main Method
int main (void)

{

	// Variable Declarations
	int age, h, ft, in, cm, w, lb, m, kg, mif, min;
	char choice, decision, loop;
	float BMI, useM, kglb;

	do
	{
		system("cls");
		printf("\n\nPlease answer the following question before your BMI can be calculated:\n");
		printf("\n   Are you a muscle builder, a long-distance athlete, or pregnant (Y/N)? ");
		scanf(" %c", &choice);

		// age
		if ((choice == 'N') || (choice == 'n'))
		{

			printf("\n   Please enter your age:");
			scanf("%d", &age);

			// age restrictions

			if ((age < 18) || (age > 65))
			{
				printf("\nSorry, the BMI can only be calculated for adults aged 18-65.");
				printf("\nDo you want to repeat the process (Y/N)?");
				scanf(" %c", &loop);
			}

			else if ((age >= 18) || (age <= 65))
			{

				// height
				printf("\nDo you want to enter your height in:\n");

				printf("1) feet and ");
				printf("inches");
				printf("\n2) centimeters\n");
				printf("\n     your choice:");
				scanf("%d", &h);

				if (h == 1)
				{

					printf("\nEnter your height in feet:");
					scanf("%d", &ft);
					printf("and inches:");
					scanf("%d", &in);

					mif = ft * 30.48;
					min = in * 2.54;
					m = mif + min;
					useM = m * 0.01;

					printf("conversion to meters is %.2f", useM);
				}

				else if (h == 2)
				{

					printf("\nEnter your height in centimeters:");
					scanf("\n%d", &cm);

					useM = cm * 0.01;
					printf("conversion to meters is %.2f\n", useM);
				}

				// weight

				printf("\n\nDo you want to enter your weight in:\n");

				printf("1) kilograms or\n");
				printf("2) pounds\n");
				printf("\n     your choice:");
				scanf("%d", &w);

				// choices

				if (w == 1)
				{

					printf("\nEnter your weight in kilograms:");
					scanf("%d", &kg);

					printf("conversion to kilograms is %d", kg);
					BMI = kg / (useM * useM);
					printf("\n\n Your BMI is %.2f ", BMI);

					if (BMI <= 18.5)
					{
						printf("and you are classified as Underweight.");
					}

					else if ((BMI >= 18.5) && (BMI <= 24.9))
					{
						printf("and you are classified as Normal weight.");
					}

					else if ((BMI >= 25) && (BMI <= 29.9))
					{
						printf("and you are classified as Overweight");
					}

					else if ((BMI >= 30) && (BMI <= 34.9))
					{
						printf("and you are classified as Obesity Class 1");
					}

					else if ((BMI >= 35) && (BMI <= 39.9))
					{
						printf("and you are classified as Obesity Class 2");
					}

					else if (BMI >= 40)
					{
						printf("and you are classified as Extreme Obesity Class 3 ");
					}
				}

				else if (w == 2)
				{

					printf("\nEnter your weight in pounds:");
					scanf("%d", &lb);

					kglb = lb * 0.453592;
					printf("conversion to kilograms is %.2f", kglb);

					BMI = kglb / (useM * useM);
					printf("\n\n Your BMI is %.2f ", BMI);

					if (BMI <= 18.5)
					{
						printf("and you are classified as Underweight.");
					}

					else if ((BMI >= 18.5) && (BMI <= 24.9))
					{
						printf("and you are classified as Normal weight.");
					}

					else if ((BMI >= 25) && (BMI <= 29.9))
					{
						printf("and you are classified as Overweight");
					}

					else if ((BMI >= 30) && (BMI <= 34.9))
					{
						printf("and you are classified as Obesity Class 1");
					}

					else if ((BMI >= 35) && (BMI <= 39.9))
					{
						printf("and you are classified as Obesity Class 2");
					}

					else if (BMI >= 40)
					{
						printf("and you are classified as Extreme Obesity Class 3 ");
					}
				}

				printf("\n\n\nDo you want to repeat the process (Y/N)?");
				scanf(" %c", &decision);
			}
		}

		else if ((choice == 'Y') || (choice == 'y'))
		{

			printf("Sorry, your Body Mass Index cannot be calculated.\n");
			printf("\nDo you want to repeat the process (Y/N)?");
			scanf(" %c", &decision);
		}

	}
	while ((decision == 'Y') || (decision == 'y'));
}
