#ifndef __DISPATCHER__
#define __DISPATCHER__
#include <random>

using std::string;
class Airplane;

class Dispather
{
	friend Airplane;
	string name;
	int corrections, penalty_point;
protected:
	bool active;																																																											
	Dispather(string _name): active(true), name(_name),penalty_point(0) { 
		
		std::default_random_engine generator;
		generator.seed(std::random_device()());
		std::uniform_int_distribution<int> distribution(-200,200);
		corrections = distribution(generator);

	}
	int getRecomendHeight(int speed ) { return 7*speed - corrections; }
	string getName() { return name; } 
	void addPenaltyPoint(int p) { penalty_point += p; } 
	int getPenaltyPoints() { return penalty_point; }
};

#endif 