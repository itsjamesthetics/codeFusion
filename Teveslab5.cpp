/*
	Developed by: James Ald Teves
	BS Computer Science

	Instructor: Assist. Prof. Allan V. Credo
	Laboratory 5
*/

// Preprocessor Directives
#include <iostream>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
using namespace std;

// Class
class Time
{

	// Objects
	int hrs;
	int mins;
	int secs;

public:
	Time()
	{

		// Initialize to 0
		hrs = 0;
		mins = 0;
		secs = 0;
	}

	// Parameters
	Time(int hours, int minutes, int seconds)
	{

		hrs = hours;
		mins = minutes;
		secs = seconds;
	}

	// SETTER and GETTER
	int setHours(int hours)
	{
		hrs = hours;
	}

	int getHours()
	{
		return hrs;
	}

	int setMinutes(int minutes)
	{
		mins = minutes;
	}

	int getMinutes()
	{
		return mins;
	}

	int setSeconds(int seconds)
	{
		secs = seconds;
	}

	int getSeconds()
	{
		return secs;
	}

	void AddTime(Time t1, Time t2)
	{

		int addtime = 0;
		secs = t1.getSeconds() + t2.getSeconds();
		if ((secs > 59))
		{
			secs -= 60;
			addtime++;
		}

		mins = t1.getMinutes() + t2.getMinutes() + addtime;
		addtime = 0;
		if ((mins > 59))
		{
			mins -= 60;
			addtime++;
		}

		hrs = t1.getHours() + t2.getHours() + addtime;
		if ((hrs >= 24))
		{
			hrs -= 24;
			cout << hrs << mins << secs << endl;
		}
	}

	void show()
	{
		cout << " H:" << hrs << " M:" << mins << " S:" << secs << endl;
	}
};

// Main Driver
int main(void)
{

	// Objects
	Time t1(1, 35, 35);
	Time t2(4, 45, 15);
	Time t3;

	cout << "TIME 1: ";
	t1.show();
	cout << "TIME 2: ";
	t2.show();

	cout << endl << "Time Added Successfully! " << endl;
	t3.AddTime(t1, t2);
	t3.show();

	return 0;
}