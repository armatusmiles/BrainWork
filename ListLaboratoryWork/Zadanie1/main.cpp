#include <iostream>
#include "MyList.h"

using namespace std;


template<class T>
class Queue
{
private:
	List<T> m_list;
	int m_size;
public:
	Queue() : m_size(0) {}
	bool empty() { return !m_size; }
	void push_back(T element) { m_size++; m_list.add(element); }
	void showQueue() { m_list.showList(); }
	void pop_front() { if (m_size) m_size--; m_list.removeFirstElement(); }
	int size() { return m_size; }
	T back()  { if (m_size) return m_list.getLastElementValue();   return T(); }
	T front() { if (m_size) return m_list.getFirstElementValue();  return T(); }
};

int main()
{
	_CrtDumpMemoryLeaks();
	Queue<string>obj;
	obj.push_back("first");
	obj.push_back("second");
	obj.push_back("third");
	obj.showQueue(); cout << endl;

	obj.pop_front();
	obj.pop_front();
	obj.showQueue(); cout << endl;

	obj.push_back("fourth");
	obj.showQueue(); cout << endl;

	obj.pop_front();
	obj.pop_front();

	cout << boolalpha;
	cout << "Is empty? " << obj.empty() << endl;
	obj.push_back("Five");
	cout << "Is empty? " << obj.empty() << endl;

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}


