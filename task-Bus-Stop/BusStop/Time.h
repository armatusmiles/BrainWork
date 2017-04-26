#pragma once
#include <iostream>


using namespace std;
class Time
{
	int hours, min;
public:
	Time() : hours(0), min(0) {}

	void addMinute();
	void printTime();
	int getCurrentHour() { return hours; }
	int getTimeInMinutes() const;
};

int Time::getTimeInMinutes() const
{
	int timeInMin = min;
	int h = hours;
	while (h--)
		timeInMin += 60;
	return timeInMin;
}

void Time::addMinute()
{
	if (++min > 59)
	{
		min = 0;
		if (++hours > 23)
			hours = 0;
	}
}

void Time::printTime()
{
	if (hours < 10)
		cout << "0";

	cout << hours << ":";

	if (min < 10)
		cout << "0";

	cout << min << endl;
}