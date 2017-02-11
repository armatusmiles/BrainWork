#include <iostream>
#include <conio.h>
#include <ctime>
#include <random>
#include "Airplane.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int key;
	Airplane plane = Airplane::getInstance();
	cout << "For start move you mast add minimum Two Dispatchers\n";
	cout << "For add dispatcher input \"1\"\n";
	cout << "For remove dispatcher input \"2\"\n";

	while (plane.getCountActiveDispatchers() < 2)
			plane.addDispatcher();

	cout << "Ok. you have two dispatcher. For start pree \"Enter\"\n";

	while (1) {

		if(_kbhit())
		{
			int i = _getch();
			i == 224 ? i = _getch() : 1;
			plane.wheel(i);
			system("cls");
			cout << "Speed: " << plane.getSpeed() << endl;
			cout << "Height: " << plane.getHeight() << endl;
			if(plane.getSpeed() > 50)
			{
				plane.printRecomendationHeight();
				plane.checkPenalty();
			}			
		}

		if ( plane.getSpeed1000() && plane.getHeight() == 0 )
			break;

	}

	cout << "You Result: " << endl;
	plane.showResult();

}


