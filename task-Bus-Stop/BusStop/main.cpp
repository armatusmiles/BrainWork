#include <conio.h>
#include <ctime>
#include "InputInformation.h"
#include "Time.h"
#include <Windows.h>
#include <list>

using std::cout;
using std::endl;
using std::cin;

/*
—оздать имитационную модель "остановка маршрутных такси". 
Ќеобходимо вводить следующую информацию: 
среднее врем€ между по€влени€ми пассажиров на остановке в разное врем€ суток,
среднее врем€ между по€влени€ми маршруток на остановке в разное врем€ суток. 
Ќеобходимо определить: среднее врем€ пребывание человека на остановке, 
достаточный интервал времени между приходами маршруток, 
чтобы на остановке находилось не более N людей одновременно.
 оличество свободных мест в маршрутке €вл€етс€ случайной величиной.
*/


/*
	[0] - Night		00:00 - 05:59
	[1] - Morning    6:00 - 11:59
	[2] - Day	    12:00 - 17:59
	[3] - Evening   18:00 - 23:59
*/

double getAverageTimeInStopBus(list<Time*> history);

int main()
{
	_CrtDumpMemoryLeaks();
	srand(time(0));
	InputInformation inputInfrom;			
	Time *currentTime = new Time;
	list<Time*> timePassengerOnStopBus;
	list<Time*> historyTimePassengerOnStopBus;
	int count_spawn_passenger = 0;
	int count_spawn_bus = 0;
	int numberOfEmptySeats;
	int N = 4;

	/* интервал времени между приходами маршруток,
	чтобы на остановке находилось не более N людей одновременно.*/

	int x = 0; 

	while (!_kbhit())
	{	
		if (++count_spawn_passenger == inputInfrom.getCurrentSpawnPassenger(*currentTime))
		{
			timePassengerOnStopBus.push_back(new Time());
			count_spawn_passenger = 0;
		}

		if (timePassengerOnStopBus.size() == N)
			x = timePassengerOnStopBus.front()->getTimeInMinutes();

		if (++count_spawn_bus == inputInfrom.getCurrentSpawnBus(*currentTime))
		{
			numberOfEmptySeats = 5 + rand() % 5;
			while ( numberOfEmptySeats-- >= 0 && !timePassengerOnStopBus.empty())
			{
				historyTimePassengerOnStopBus.push_back(timePassengerOnStopBus.front());
				timePassengerOnStopBus.pop_front();
			}
			count_spawn_bus = 0;
		}

		for (auto s : timePassengerOnStopBus)
			s->addMinute();
		
		currentTime->addMinute();
		
		cout << "Current time: ";
		currentTime->printTime();
		cout << "Current spawn Passenger: " << inputInfrom.getCurrentSpawnPassenger(*currentTime) << endl;
		cout << "Current spawn Bus: " << inputInfrom.getCurrentSpawnBus(*currentTime) << endl;
		cout << "Current count passenger in Bus-Stop: " << timePassengerOnStopBus.size() << endl;

		Sleep(10);
		system("cls");
	}

	for (auto s : timePassengerOnStopBus)
		delete s;

	cout << "Average time passenger on bus-stop: " <<
		getAverageTimeInStopBus(historyTimePassengerOnStopBus) << "minutes" << endl;
	cout << "X = " << x << endl;

	delete currentTime;


	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
}

double getAverageTimeInStopBus(list<Time*> history)
{
	int size = history.size();
	int sum = 0;
	while (!history.empty())
	{
		sum += history.front()->getTimeInMinutes();
		delete history.front();
		history.pop_front();
	}

	return double(sum) / double(size);	
}