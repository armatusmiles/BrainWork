#ifndef __AIRPLANE__
#define __AIRPLANE__

#include "Dispatcher.h"
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::endl;

enum KEY { KEY_UP = 72, KEY_DOWN = 80, KEY_LEFT = 75, KEY_RIGHT = 77, CTRL_LEFT = 115, CTRL_RIGHT = 116, CTRL_TOP = 141, 
		   CTRL_BOT = 145, KEY_1 = 49, KEY_2 = 50 } ;

class Airplane
{
	vector<Dispather*> dispatchers;
	Airplane(): speed(0), height(0), speed1000(false) { } 
	int speed, height;
	bool speed1000;
public:
	static Airplane& getInstance() { static Airplane obj; return obj; }
	int getSpeed() { return speed; }
	int getHeight() { return height;}
	int getCountActiveDispatchers() { int count = 0; for(auto d : dispatchers) if(d->active) count++; return count; }
	bool getSpeed1000() { return speed1000; }
	void checkPenalty();
	void printRecomendationHeight();
	void wheel(int k);
	void addDispatcher();
	void removeDispatcher();
	void showResult();
};

void Airplane::showResult()
{
	int sum = 0;
	for(auto d : dispatchers)
	{
		cout << "Dispatcher " << d->getName() 
			<< ". penalty points: " << d->getPenaltyPoints() << endl; 
		sum += d->getPenaltyPoints();
	}

	cout << "Sum penalty point: " << sum << endl;
	if(sum < 1000)
		cout << "Examenation passed. Good Work!" << endl;
	else 
		cout << "Examination is failed. Try Again!" << endl;
}

void Airplane::checkPenalty()
{
	int diff;
	for(auto d : dispatchers)
	{
		diff = abs(height - d->getRecomendHeight(speed));
		if ( diff >= 300 && diff <= 600 )
		{
			d->addPenaltyPoint(25);
			cout << "You get 25 penalty points! From " << d->getName() << endl;
		}

		else if ( diff >= 600 && diff <= 1000 ) 
		{
			d->addPenaltyPoint(50);
			cout << "You get 50 penalty points! From " << d->getName() << endl;
		}

		else if ( diff > 1000 )
		{
			cout << "Plane crahsed! You lose!" << endl;
			exit(1);
		}

		if ( speed > 1000 )
		{
			cout << "You get 100 penalty points! From " << d->getName() << endl;
			cout << "You have  hight speed! " << endl;
			d->addPenaltyPoint(50);
		}
	}

	if( speed == 1000 )
		speed1000 = true;
}

void Airplane::printRecomendationHeight()
{
	for(auto d : dispatchers) 
		if( d->active ) 
			cout << d->name << ": "	<< d->getRecomendHeight(speed) << endl;
}

void Airplane::removeDispatcher()
{
	if(dispatchers.size() <= 2 )
	{
		cout << "Error you have <= 2 Dispatchers\n";
		system("pause");
		return;
	}
	cout << "Input a name Dispatcher: ";
	string name;
	getline(std::cin,name);

	for(auto d : dispatchers)
	{
		if (d->getName() == name)
			d->active = false;
	}
}

void Airplane::addDispatcher()
{
	cout << "Input a name Dispatcher: ";
	string name;
	getline(std::cin,name);
	dispatchers.push_back(new Dispather(name));
}

void Airplane::wheel(int k)
{
	switch (k)
	{
		case KEY_UP: height += 250; break;
		case KEY_DOWN: height >= 250 ? height -= 250 : 1; break;
		case KEY_LEFT: speed >= 50 ? speed -= 50 : 1; break;
		case KEY_RIGHT: speed += 50; break;
		case CTRL_LEFT: speed >= 150 ? speed -= 150 : 1; break; 
		case CTRL_RIGHT: speed += 150; break;
		case CTRL_TOP: height += 500; break;
		case CTRL_BOT: height >= 500 ? height -= 500 : 1; break;
		case KEY_1: addDispatcher(); break;
		case KEY_2: removeDispatcher(); break;
	}
}

#endif