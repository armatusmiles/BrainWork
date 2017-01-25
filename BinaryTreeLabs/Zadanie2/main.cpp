#include <iostream>
#include <string>
#include <fstream>
#include "BinaryTree.h"

using std::string;
using std::cout;
using std::endl;

struct ShareTaxi
{
	string regNumber;
	string nameDriver;
	string surnameDriver;
	int numberRoute;
	int countCapacity;

	ShareTaxi(): countCapacity(0) { }
	bool operator>(ShareTaxi const & obj)
	{
		if (strcmpi(regNumber.c_str(), obj.regNumber.c_str()) > 0)
			return true;
		return false;
	}

	bool operator<(ShareTaxi const & obj)
	{
		if (strcmpi(regNumber.c_str(), obj.regNumber.c_str()) < 0)
			return true;
		return false;
	}

	bool operator==(ShareTaxi const & obj)
	{
		if (strcmpi(regNumber.c_str(), obj.regNumber.c_str()) == 0)
			return true;
		return false;
	}

	friend ostream& operator<<(ostream &os, ShareTaxi &obj)
	{
		cout << "Reg. Number: " << obj.regNumber << endl;
		cout << "Name driver: " << obj.nameDriver << endl;
		cout << "Surname Driver: " << obj.surnameDriver << endl;
		cout << "Number route: " << obj.numberRoute << endl;
		cout << "Count capacity: " << obj.countCapacity << endl;
		cout << endl;
		return os;
	}

	friend istream& operator >> (istream& is, ShareTaxi &obj)
	{
		bool success = false;

		cout << "Input Reg. Number: ";
		getline(cin, obj.regNumber);
		cout << "Input Name driver: ";
		getline(cin, obj.nameDriver);
		cout << "Input Surname driver: ";
		getline(cin, obj.surnameDriver);
		cout << "Input Number route: ";

		while (!success)
		{
			cin >> obj.numberRoute;
			if (cin.good())
			{
				success = true;
			}
			else
			{
				cout << "Incorrect input! Try again!" << endl;
				cin.clear();
				while (cin.get() != '\n');
			}
		}

		cout << "Input Count Capacity: ";
		success = false;
		while (!success)
		{
			cin >> obj.countCapacity;
			if (cin.good())
			{
				success = true;
			}
			else
			{
				cout << "Incorrect input! Try again!" << endl;
				cin.clear();
				while (cin.get() != '\n');
			}
		}
		while (cin.get() != '\n');
		return is;
	} 
};

template<class T>
class BinaryTreeForShareTaxi : public BinaryTree<T>
{
	void printByNumbers(string number, Node<T> *ptr)
	{
		if (ptr != nullptr)
		{
			printByNumbers(number, ptr->left);
			printByNumbers(number, ptr->right);
			if(ptr->value.regNumber == number)
				cout << ptr->value;
		}
	}
	void printByNameDriver(string name, Node<T> *ptr)
	{
		if (ptr != nullptr)
		{
			printByNameDriver(name, ptr->left);
			printByNameDriver(name, ptr->right);
			if (ptr->value.nameDriver == name)
				cout << ptr->value;
		}
	}

	void printBySurnameDriver(string surname, Node<T> *ptr)
	{
		if (ptr != nullptr)
		{
			printBySurnameDriver(surname, ptr->left);
			printBySurnameDriver(surname, ptr->right);
			if (ptr->value.surnameDriver == surname)
				cout << ptr->value;
		}
	}

	void printByNumberRoute(int number, Node<T> *ptr)
	{
		if (ptr != nullptr)
		{
			printByNumberRoute(number, ptr->left);
			printByNumberRoute(number, ptr->right);
			if (ptr->value.numberRoute == number)
				cout << ptr->value;
		}
	}

	void printByCountCapacity(int number, Node<T> *ptr)
	{
		if (ptr != nullptr)
		{
			printByCountCapacity(number, ptr->left);
			printByCountCapacity(number, ptr->right);
			if (ptr->value.countCapacity == number)
				cout << ptr->value;
		}
	}

public:
	void searchByNumber(string number) { Node<T>* ptr = this->m_head; printByNumbers(number, ptr); }
	void searchByNameDriver(string name) { Node<T>* ptr = this->m_head; printByNameDriver(name, ptr); }
	void searchBySurnameDriver(string surname) { Node<T>* ptr = this->m_head; printBySurnameDriver(surname, ptr); }
	void searchByNumberRoute(int number) { Node<T>* ptr = this->m_head; printByNumberRoute(number, ptr); }
	void searchByCountCapacity(int number) { Node<T>* ptr = this->m_head; printByCountCapacity(number, ptr); }
	void saveSortTreeInFile(int count)
	{
		int i = 0;
		Node<T> *list = toList();
		ShareTaxi *mas = new ShareTaxi[count];
		while (list)
		{
			mas[i++] = list->value;
			list = list->left;
		}

		for (int j = 0; j < i; j++)
		{
			for (int jj = 0; jj < i - 1; jj++)
			{
				if (mas[jj] > mas[jj + 1])
					swap(mas[jj], mas[jj + 1]);
			}
		}

		ofstream fout;
		cout << "Input name file: ";
		string tmp;
		getline(cin, tmp);
		fout.open(tmp.append(".txt"));
		for (int j = 0; j < i; j++) {
			fout << "Reg. Number: " << mas[j].regNumber << endl;
			fout << "Name driver: " << mas[j].nameDriver << endl;
			fout << "Surname Driver: " << mas[j].surnameDriver << endl;
			fout << "Number route: " << mas[j].numberRoute << endl;
			fout << "Count capacity: " << mas[j].countCapacity << endl;
			fout << endl;
		}

		fout.close();
		cout << "File Saved!" << endl;

		delete[] mas;
	}

};

void fillShareTaxiInform(ShareTaxi *obj)
{
	obj[0].regNumber = "AC2840IO";
	obj[0].nameDriver = "Viktor";
	obj[0].surnameDriver = "Pavlenko";
	obj[0].numberRoute = 10;
	obj[0].countCapacity = 26;

	obj[1].regNumber = "AC3019AO";
	obj[1].nameDriver = "Oleg";
	obj[1].surnameDriver = "Harlamov";
	obj[1].numberRoute = 15;
	obj[1].countCapacity = 36;

	obj[2].regNumber = "AC2543OA";
	obj[2].nameDriver = "Grigoriy";
	obj[2].surnameDriver = "Skovoroda";
	obj[2].numberRoute = 3;
	obj[2].countCapacity = 24;

	obj[3].regNumber = "AC1154KA";
	obj[3].nameDriver = "Oleskandr";
	obj[3].surnameDriver = "Skripka";
	obj[3].numberRoute = 9;
	obj[3].countCapacity = 29;

	obj[4].regNumber = "BO5379KP";
	obj[4].nameDriver = "Vlad";
	obj[4].surnameDriver = "Gricenko";
	obj[4].numberRoute = 19;
	obj[4].countCapacity = 24;
	
	obj[5].regNumber = "AC4583AO";
	obj[5].nameDriver = "Vasiliy";
	obj[5].surnameDriver = "Garmash";
	obj[5].numberRoute = 28;
	obj[5].countCapacity = 29;

	obj[6].regNumber = "AC2244AO";
	obj[6].nameDriver = "Valentin";
	obj[6].surnameDriver = "Makruha";
	obj[6].numberRoute = 24;
	obj[6].countCapacity = 36;

	obj[7].regNumber = "AC1313AO";
	obj[7].nameDriver = "Oleksiy";
	obj[7].surnameDriver = "Goncharenko";
	obj[7].numberRoute = 12;
	obj[7].countCapacity = 22;

	obj[8].regNumber = "AC2805AO";
	obj[8].nameDriver = "Igor";
	obj[8].surnameDriver = "Rasteryaev";
	obj[8].numberRoute = 18;
	obj[8].countCapacity = 26;

	obj[9].regNumber = "AC4786AO";
	obj[9].nameDriver = "Misha";
	obj[9].surnameDriver = "Kruglov";
	obj[9].numberRoute = 1;
	obj[9].countCapacity = 29;
}
int main()
{

	ShareTaxi obj[10];
	BinaryTreeForShareTaxi<ShareTaxi> tree;
	fillShareTaxiInform(obj);
	int count_objects = 0;
	for (int i = 0; i < 10; i++)
		if (tree.insert(obj[i]))
			count_objects++;
	
	tree.printTree();
	char i;
	int number;
	string temp;
	while (true)
	{
		cout << "Input \"1\" for search by Reg. Number " << endl;
		cout << "Input \"2\" for search by Name driver " << endl;
		cout << "Input \"3\" for search by Surname driver " << endl;
		cout << "Input \"4\" for search by number route " << endl;
		cout << "Input \"5\" for search by count capacity " << endl;
		cout << "Input \"6\" for save Information on txt file" << endl;
		cout << "Input \"7\" for show all taxi" << endl;
		cout << "Input \"8\" for add taxi" << endl;
		cout << "Input \"9\" for remove" << endl;
		cout << "Input \"q\" for exit" << endl;
		cin >> i;
		switch (i)
		{
		case 49:
			while (cin.get() != '\n');
			cout << "Input number: ";
			getline(cin, temp);
			cout << "Find Taxi: " << endl;
			tree.searchByNumber(temp);
			continue;
		case 50:
			while (cin.get() != '\n');
			cout << "Input name: ";
			getline(cin, temp);
			cout << "Find Taxi: " << endl;
			tree.searchByNameDriver(temp);
			continue;
		case 51:
			while (cin.get() != '\n');
			cout << "Input surname: ";
			getline(cin, temp);
			cout << "Find Taxi: " << endl;
			tree.searchBySurnameDriver(temp);
			continue;
		case 52:
			while (cin.get() != '\n');
			cout << "Input number route: ";
			cin >> number;
			cout << "Find Taxi: " << endl;
			tree.searchByNumberRoute(number);
			continue;
		case 53:
			while (cin.get() != '\n');
			cout << "Input count capacity: ";
			cin >> number;
			cout << "Find Taxi: " << endl;
			tree.searchByCountCapacity(number);
			continue;
		case 54:
			while (cin.get() != '\n');
			tree.saveSortTreeInFile(count_objects);
			continue;
		case 55:
			tree.printTree();
			continue;
		case 56:
		{
			while (cin.get() != '\n');
			ShareTaxi new_obj;
			cin >> new_obj;
			if (tree.insert(new_obj))
			{
				cout << "Information added!" << endl;
				count_objects++;
			}
		}
			continue;
		case 57:
		{
			cout << "Input Reg. Number: " << endl;
			while (cin.get() != '\n');
			ShareTaxi new_obj;
			getline(cin, new_obj.regNumber);
			if (tree.remove(new_obj))
				cout << "Information deleted!" << endl;
			continue;
		}
		case 'q':
			exit(-1);
		default:
			break;
		}
	}
}