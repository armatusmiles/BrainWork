#include <iostream>
#include <string>
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
	void showReverseList();
	bool delItemByValue(T value);
};

int main()
{
	List<string>*list = new List<string>;
	list->add("First");
	list->add("Second");
	list->add("Third");
	list->add("Fourth");
	list->showList();
	list->delItemByValue("Third");
	cout << endl; list->showList();

	cout << endl;
	list->showReverseList();

	delete list;
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
		cout << temp->value << endl;
		temp = temp->next;
	}
	delete temp;
}

template<class T>
void List<T>::showReverseList()
{
	Node<T>*temp = endList;
	while (temp) {
		cout << temp->value << endl;
		temp = temp->prev;;
	}
	delete temp;
}