/*
	Developed by: James Ald Teves
	BS Computer Science

	Description: This is a demonstration on how to successfully login a correct credentials,
	using strings in C.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NAMESIZE 50

int main()
{

	char username[NAMESIZE], newUsername[NAMESIZE];
	char password[NAMESIZE], newPassword[NAMESIZE];

	printf("\n\t\t Hello! Welcome to MyScar Corporation. ");
	printf("\n\t Please Sign Up");
	printf("\n Username: ");
	gets(username);
	printf("\n Password: ");
	gets(password);

	printf("\n\t LOGIN ");
	printf("\n\t Enter username: ");
	gets(newUsername);
	printf("\n\t Enter password: ");
	gets(newPassword);

	if ((username == newUsername && password == newPassword))
	{
		printf("\n\t Succesfully Login! ");
	}
	else
	{
		printf("\n\t Login Failed! ");
	}
}
