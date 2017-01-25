#include "CList.h"
#define SHOW_LISTS cout << iList << endl; cout << dList << endl; cout << cList << endl << endl
int main()
{
	_CrtDumpMemoryLeaks();  

	ÑList<int> iList;
	ÑList<double> dList;
	ÑList<char*> cList;
	char buff[10][3];
	
	for (int i = 0; i < 10; i++)
	{
		buff[i][0] = i + 65;
		buff[i][1] = i + 65;
		buff[i][2] = '\0';
		iList.add(i + 1);
		dList.add(i + 1.5);
		cList.add(buff[i]);
	}

	SHOW_LISTS;
	
	iList.eraseLastItems(2);
	dList.eraseFirstItems(2);
	cList.eraseAllItemsEvenPositions();

	SHOW_LISTS;
	
	iList.eraseAllItemsOddPositions();
	dList.eraseAllItemsMultiple(3);
	cList.reverseFirstAndLast();

	SHOW_LISTS;

	iList.add(3);
	iList.add(3);

	iList.delAllItemByValue(3);
	dList.invertionList();
	cList.nonArithmeticalShiftRight(2);
	SHOW_LISTS;

	dList.nonArithmeticalShiftLeft(1);
	cout << dList << endl;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}
