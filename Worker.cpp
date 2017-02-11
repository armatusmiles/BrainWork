#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <algorithm>
#include <fstream>
  
#define ERROR_SYNTX fin.close(); std::cerr << "Syntax error! Can't read file!"; exit(-1) 
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::sort;
using std::ofstream;
using std::ifstream;

class Worker
{
	int m_identificator;
	string m_name;
protected:
	double m_salary;
public:
	virtual ~Worker() { }
	Worker(int idt, string _name, double sal) : m_identificator(idt), m_name(_name), m_salary(sal) { }
	virtual int getAverageSalary() = 0;
	virtual void showInformation() {
		cout << "ID: " << m_identificator << endl << "Name: " << m_name << endl
			<< "Average Salary: " << getAverageSalary() << endl;
	}
	virtual bool operator>(Worker &obj);
	int getId() { return m_identificator; }
	string getName() { return m_name; }
	double getSalary() { return m_salary; }

};

class WorkerHours : public Worker
{
public:
	WorkerHours(int idt, string name, int sal) : Worker(idt, name, sal) { }
	int getAverageSalary() override { return 20.8 * 8 * m_salary; }
};

class WorkerMonth : public Worker
{
public:
	WorkerMonth(int idt, string name, int sal) : Worker(idt, name, sal) { }
	int getAverageSalary() override { return m_salary; }
};

class FabricWorkers
{
public:
	static Worker* getWorker() {
		int id = 0 + rand() % 100000;
		string name = "name";
		name.append(std::to_string(id));
		switch (0 + rand() % 2)
		{
		case 0:
			return new WorkerHours(id, name, 5 + rand() % 5);
			break;
		case 1:
			return new WorkerMonth(id, name, 1000 + rand() % 500);
			break;
		}
	}
};

class GroupWorkers
{
	typedef std::vector<Worker*>::iterator Iterator;
	vector<Worker*> m_objects;
public:
	void addWorker(Worker *w) { m_objects.push_back(w); }
	~GroupWorkers() { for (Worker *w : m_objects) delete w; }
	void sort() { std::sort(m_objects.begin(), m_objects.end(), [&](Worker* a, Worker* b) { return *a > *b; }); }
	void showAllWorkers() { for (auto s : m_objects) s->showInformation(); }
	void showTop5() { for (Iterator it = m_objects.begin(); it != m_objects.begin() + 5; ++it) (*it)->showInformation(); }
	void showLast3() { for (Iterator it = m_objects.end() - 3; it != m_objects.end(); ++it) (*it)->showInformation(); }
	void save();
	void load();
};

int main()
{
	srand(time(0));
	GroupWorkers workers;

	 /* Make random workers */
	/*for (int i = 0; i < 10; i++)
		workers.addWorker(FabricWorkers::getWorker());

	workers.sort();
	workers.showAllWorkers();
	cout << endl;
	cout << "TOP 5: " << endl;
	workers.showTop5();
	cout << endl;
	cout << "Last 3: " << endl;
	workers.showLast3();
	cout << endl;
	workers.save();*/
	

	 /* Load workers from file*/
	/*workers.load();
	workers.sort();
	workers.showAllWorkers();*/
}

void GroupWorkers::save()
{
	ofstream fout("saveWorkers.txt");
	for (Iterator it = m_objects.begin(); it != m_objects.end(); ++it)
	{
		fout << "Name: " << (*it)->getName() << endl;
		fout << "Identification: " << (*it)->getId() << endl;
		fout << "Salary: " << (*it)->getSalary() << endl;
	}
	fout.close();
}

bool Worker::operator>(Worker &obj)
{
	if (getAverageSalary() > obj.getAverageSalary())
		return true;
	if (getAverageSalary() == obj.getAverageSalary())
		if (strcmpi(m_name.c_str(), obj.m_name.c_str()) > 0)
			return true;
	return false;
}

void GroupWorkers::load() {

	auto isUint = [&](string s) {
		for (char c : s)
			if (!isdigit(c) && c != '.')
				return false;
		return true;
	};

	ifstream fin("saveWorkers.txt");
	if (!fin.is_open()) {
		std::cerr << "Can't find file!"; exit(-1);
	}
	string tmp, chk, id, name;
	double asVal;
	while (!fin.eof())
	{
		for (int i = 0; i < 3; i++)
		{
			getline(fin, tmp);
			if (tmp.empty()) break;
			chk = tmp.substr(0, 5);
			if (chk != "Name:" && chk != "Ident" && chk != "Salar" && !fin.eof()) {
				ERROR_SYNTX;
			}
			tmp.erase(0, tmp.find(' ') + 1);
			switch (i)
			{
			case 0: name = tmp; break;
			case 1: id = tmp; if (!isUint(tmp)) { ERROR_SYNTX; } break;
			case 2: if (!isUint(tmp)) { ERROR_SYNTX; }  asVal = std::stod(tmp); break;
			}			
		}
		if (!tmp.empty())
		{
			if (asVal < 100)
				m_objects.push_back(new WorkerHours(std::stoi(id), name, asVal));
			else
				m_objects.push_back(new WorkerMonth(std::stoi(id), name, asVal));
		}
	}
	fin.close();
}