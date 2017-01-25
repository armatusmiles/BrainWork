#include <iostream>
#include <string>
#include <conio.h>
#include "BinaryTree.h"

using std::cout;
using std::endl;
using std::cin;
using std::ostream;

struct Dictionary
{
	string rus;
	string eng;
	int counter;

	Dictionary(): counter(0) {}
	bool operator>(Dictionary const & obj)
	{
		if (strcmpi(eng.c_str(), obj.eng.c_str()) > 0)
			return true;
		return false;
	}

	bool operator<(Dictionary const & obj)
	{
		if (strcmpi(eng.c_str(), obj.eng.c_str()) < 0)
			return true;
		return false;
	}

	bool operator==(Dictionary const & obj)
	{
		if (strcmpi(eng.c_str(), obj.eng.c_str()) == 0)
			return true;
		return false;
	}

	friend ostream& operator<< (ostream & os, const Dictionary &obj)
	{
		cout << "ENG: " << obj.eng << endl;
		cout << "RUS: " << obj.rus << endl;
		cout << endl;
		return os;
	}

	template<class T>
	static void showByCounter(Node<T>*list, int count, bool top)
	{
		Dictionary *mas = new Dictionary[count];
		int i = 0;
		while (list)
		{
			mas[i++] = list->value;
			list = list->left;
		}

		for (int j = 0; j < i; j++)
		{
			for (int jj = 0; jj < i - 1; jj++)
			{
				if (mas[jj].counter < mas[jj + 1].counter)
					swap(mas[jj], mas[jj + 1]);
			}
		}

		if(top)
			for (int i = 0; i < 3; i++)
			{
				cout << "Count = " << mas[i].counter << endl;
				cout << mas[i];
			}
		else
			for(int j = count - 1; j != count - 4; j--)
			{
				cout << "Count = " << mas[j].counter << endl;
				cout << mas[j];
			}

		delete[] mas;
	}

};


void initializationObjects(Dictionary* obj)
{
	obj[0].eng = "Home";
	obj[0].rus = "Dom";

	obj[1].eng = "Pen";
	obj[1].rus = "Ruchka";

	obj[2].eng = "Apple";
	obj[2].rus = "Yabloko";

	obj[3].eng = "Fish";
	obj[3].rus = "Ruba";

	obj[4].eng = "Hand";
	obj[4].rus = "Ruka";

	obj[5].eng = "Phone";
	obj[5].rus = "Telefon";

	obj[6].eng = "Finger";
	obj[6].rus = "Palec";

	obj[7].eng = "Author";
	obj[7].rus = "Avtor";

	obj[8].eng = "Card";
	obj[8].rus = "Kartochka";

	/* Повторяющиеся значение для проверки корректной работы бинарного дерева
	(где не должно быть повтора) */
	obj[9].eng = "Home";
	obj[9].rus = "Dom";

}

int main()
{
	_CrtDumpMemoryLeaks();
	setlocale(0, "");
	Dictionary objects[10];
	initializationObjects(objects);
	int count_objects = 0;
	BinaryTree<Dictionary> tree;

	for (int i = 0; i < 10; i++) {
		if(tree.insert(objects[i]))
			count_objects++;
	}
	Dictionary *tmp, objForSearch, top[3];
	char i;

	while (true)
	{
		cout << "Input \"1\" for search." << endl;
		cout << "Input \"2\" for show all word in dictionary" << endl;
		cout << "Input \"3\" for add words to dictionary" << endl;
		cout << "Input \"4\" for change translate" << endl;
		cout << "Input \"5\" for delete translate" << endl;
		cout << "Input \"6\" for show most popular words" << endl;
		cout << "Input \"7\" for show most unpopular words" << endl;
		cout << "Input \"q\" for exit" << endl;
		cin >> i;
		switch (i)
		{
		case 49:
			while (cin.get() != '\n');
			cout << "input word: ";
			getline(cin, objForSearch.eng);
			tmp = tree.search(objForSearch);
			if (tmp == nullptr)
				cout << "Not Found!" << endl;
			else {
				cout << "Translate: " << tmp->rus << endl;
				tmp->counter++;
			}
			continue;
		case 50:
			tree.printTree();
			continue;
		case 51:
		{
			while (cin.get() != '\n');
			Dictionary new_obj;
			cout << "Use only latin characters!" << endl;
			cout << "input word on ENG: ";
			getline(cin, new_obj.eng);
			cout << "input word on RUS: ";
			getline(cin, new_obj.rus);
			if(tree.insert(new_obj))
				count_objects++;
			continue;
		}
		case 52:
			while (cin.get() != '\n');
			cout << "Input word ( on ENG ) " << endl;
			getline(cin, objForSearch.eng);
			tmp = tree.search(objForSearch);
			if (tmp == nullptr)
				cout << "Not Found!" << endl;
			else {
				cout << "Input new translate ( RUS ) " << endl;
				getline(cin, tmp->rus);
			}
			continue;
		case 53:
			while (cin.get() != '\n');
			cout << "Input word ( on ENG ) for remove." << endl;
			getline(cin, objForSearch.eng);
			if (tree.remove(objForSearch)) {
				cout << "Word removed!" << endl;
				count_objects--;
			}
			else cout << "Not Found!" << endl;
			continue;
		case 54:
			Dictionary::showByCounter(tree.toList(), count_objects, true);
			continue;
		case 55:
		{
			Dictionary::showByCounter(tree.toList(), count_objects, false);
			continue;
		}
		default:
			break;
		}
		if (i == 'q')
			break;
		while (cin.get() != '\n');
	}
	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}


