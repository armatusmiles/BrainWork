#include <iostream>
#include "ArrayLinkedList.h"

typedef ArrayLinkedList<int> massInt;
using std::boolalpha;

int main()
{
	_CrtDumpMemoryLeaks();
	auto showMassive = [] (massInt &mas) {
		for (int i = 0; i <= mas.getUpperBound(); i++)
			cout << mas[i] << " ";
		cout << endl;
	};

	massInt massive;
	massInt massive2;
	massInt massive3;

	massive.setSize(5, 5);
	for (int i = 0; i < 4; i++)
		massive.add(i + 1);

	cout << "Massive = "; showMassive(massive);
	massive.freeExtra();
	cout << "size after freeExtra() == " << massive.getSize() << endl;
	cout << "getUpeerBount() == " << massive.getUpperBound() << endl;
	cout << boolalpha << "massive isEmpty? " << massive.isEmpty() << endl;
	massive.removeAll();
	cout << boolalpha << "massive isEmpty? " << massive.isEmpty() << endl;

	massive.setSize(10, 5);
	massive2.setSize(5, 5);

	for (int i = 0; i < 4; i++) {
		massive[i] = i + 1;
		massive2[i] = i + 10;
	}

	cout << "Massive = "; showMassive(massive);
	cout << "Massive2 = "; showMassive(massive2);
	massive.append(massive2);
	cout << "Massive after append massive2 = "; showMassive(massive);
	massive3 = massive;
	cout << "Massive3  = "; showMassive(massive3);
	massive3.insertAt(2, 999);
	cout << "Massive3  = "; showMassive(massive3);
	massive3.removeAt(2);
	cout << "Massive3  = "; showMassive(massive3);

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}