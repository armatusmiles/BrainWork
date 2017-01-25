#include <iostream>
#include <ctime>

using namespace std;

template<class T>
class Node
{
public:
	T value;
	Node *next;
	Node *prev;
};

template<class T>
class List : public Node<T>
{
private:
	Node *beginList;
	Node *endList;
public:
	List() {
		beginList = nullptr;
		endList = nullptr;
	}
	~List() {
		Node *temp;
		while (beginList)
		{
			temp = beginList;
			beginList = beginList->next;
			delete temp;
		}
	}
	void add(T t);
	void showList();
	bool delItemByValue(T value);
	void removeFirstElement();
	T getLastElementValue() { return endList->value; }
	T getFirstElementValue() { return beginList->value; }
	List<T>* clone();

	List<T>* operator+(List<T> &obj);
	List<T>* operator*(List<T> &obj);
};

template<class T>
void List<T>::removeFirstElement()
{
	if (beginList == endList)
	{
		Node<T>*temp = beginList;
		delete temp;
		beginList = endList = nullptr;
	}
	else if (beginList != nullptr)
	{
		Node<T>*temp = beginList;
		beginList = beginList->next;
		beginList->prev = nullptr;
		delete temp;
	}
}

template<class T>
void List<T>::add(T t)
{
	if (beginList == nullptr && endList == nullptr) // first add
	{
		Node<T> *temp = new Node<T>;
		temp->value = t;
		temp->prev = nullptr;
		temp->next = nullptr;
		beginList = temp;
		endList = temp;
		return;
	}

	Node<T> *temp = new Node<T>;
	temp->value = t;
	temp->prev = endList;
	temp->next = nullptr;
	endList->next = temp;
	endList = temp;
}

template<class T>
bool List<T>::delItemByValue(T value)
{
	Node<T>*temp = beginList;
	while (temp) {
		if (temp->value == value)
		{
			if (temp == beginList)
			{
				beginList = beginList->next;
				beginList->prev = nullptr;
				delete temp;
				return true;
			}
			else if (temp == endList)
			{
				endList = endList->prev;
				endList->next = nullptr;
				delete temp;
				return true;
			}
			else
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				delete temp;
				return true;
			}
		}
		temp = temp->next;
	}
	delete temp;
	return false;
}

template<class T>
void List<T>::showList()
{
	Node<T>*temp = beginList;
	while (temp) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
	delete temp;
}

template<class T>
List<T>* List<T>::clone()
{
	List<T> *new_list = new List<T>;
	Node<T> * temp = beginList;
	while (temp)
	{
		new_list->add(temp->value);
		temp = temp->next;
	}
	return new_list;
}

template<class T>
List<T>* List<T>::operator+(List<T> &obj)
{
	List<T> *new_list = new List<T>;
	Node<T> * temp = beginList;
	while (temp)
	{
		new_list->add(temp->value);
		temp = temp->next;
	}

	temp = obj.beginList;
	while (temp)
	{
		new_list->add(temp->value);
		temp = temp->next;
	}
	return new_list;
}

template<class T>
List<T>* List<T>::operator*(List<T> &obj)
{
	List<T> *new_list = new List<T>;
	Node<T> *temp = this->beginList;

	auto check = [&](T value) -> bool {
		Node<T> *iterator = new_list->beginList;
		while (iterator)
		{
			if (iterator->value == value)
				return false;
			iterator = iterator->next;
		}
		return true;
	};

	while (temp)
	{
		Node<T> *temp2 = obj.beginList;
		while (temp2)
		{
			if (temp->value == temp2->value)
				if (check(temp->value))
					new_list->add(temp->value);

			temp2 = temp2->next;
		}
		temp = temp->next;
	}

	return new_list;
}

int main()
{
	_CrtDumpMemoryLeaks();

	srand(time(0));
	List<int> obj_1, obj_2;

	for (int i = 0; i < 10; i++)
	{
		obj_1.add(1 + rand() % 10);
		obj_2.add(1 + rand() % 10);
	}

	cout << "obj_1 = "; obj_1.showList();
	cout << "obj_2 = "; obj_2.showList();

	List<int>* obj_3 = obj_1.clone();
	cout << "obj_3(clone obj_1) = "; obj_3->showList();
	delete obj_3;

	List<int>* obj_4 = obj_1 + obj_2;
	cout << "obj_4 ( obj_1 + obj_2 ) = "; obj_4->showList();
	delete obj_4;

	List<int>* obj_5 = obj_1 * obj_2;
	cout << "obj_5 ( obj_1 * obj_2 ) = "; obj_5->showList();
	delete obj_5;

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}