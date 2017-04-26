#include <iostream>
#include "Time.h"

using std::cout;
using std::cin;
using std::endl;

class InputInformation
{
	int average_spawn_passenger[4];
	int average_spawn_bus[4];
	int getIndexSpawn(Time &time);
public:
	InputInformation(); 
	void setSpawn(int *mas); 
	int getCurrentSpawnPassenger(Time &time) { return average_spawn_passenger[getIndexSpawn(time)]; }
	int getCurrentSpawnBus(Time &time) { return average_spawn_bus[getIndexSpawn(time)];  }
};

int InputInformation::getIndexSpawn(Time &time)
{
	if (time.getCurrentHour() >= 0 && time.getCurrentHour() <= 5)
		return 0;
	else if (time.getCurrentHour() >= 6 && time.getCurrentHour() <= 11)
		return 1;
	else if (time.getCurrentHour() >= 12 && time.getCurrentHour() <= 17)
		return 2;
	else if (time.getCurrentHour() >= 18 && time.getCurrentHour() <= 23)
		return 3;
	else return -1;
}



InputInformation::InputInformation()
{
	cout << "Input information about spawn passenger: " << endl;
	setSpawn(average_spawn_passenger);
	cout << "Input information about spawn bus: " << endl;
	setSpawn(average_spawn_bus);
}

void InputInformation::setSpawn(int *mas)
{
	cout << "Input average spawn in Night" << endl;
	cin >> mas[0];
	cout << "Input average spawn in Morning" << endl;
	cin >> mas[1];
	cout << "Input average spawn in Day" << endl;
	cin >> mas[2];
	cout << "Input average spawn in Evening" << endl;
	cin >> mas[3];
}