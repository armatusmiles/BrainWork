#include <iostream>
using std::cout;
using std::endl;

#define NULLIFY_THE_LIST beginList = nullptr; endList = nullptr; m_sizeList = 0
#define CHECK_LIST_SIZE_AND_N if(n > m_sizeList || n <= 0) return false; else if ( n == m_sizeList ) { this->~�List(); return true; }
#define CHECK_SIZE if(m_sizeList < 2) return false

template<class T>
class Node
{
public:
	T value;
	Node *next;
	Node *prev;
};

template<class T>
class �List : public Node<T>
{
private:
	Node *beginList;
	Node *endList;
	int m_sizeList;
	void eraseItemsByPositions(bool odd, int number = 0);
	friend std::ostream& operator<< (std::ostream& os, const �List<T>& obj)
	{
		Node<T>*temp = obj.beginList;
		while (temp) {
			cout << temp->value << " ";
			temp = temp->next;
		}
		delete temp;
		return os;
	}
	
public:
	�List() { NULLIFY_THE_LIST; }

	~�List() {
		Node *temp;
		while (beginList)
		{
			temp = beginList;
			beginList = beginList->next;
			delete temp;
		}
		NULLIFY_THE_LIST;
	}

	int getSizeList() { return m_sizeList; }
	void add(T t);
	bool delItemByValue(T value);
	
	bool eraseLastItems(int n); // 1. �����, ��������� �� ������ ��������� N ���������.
	bool eraseFirstItems(int n); // 2. �����, ��������� �� ������ ������ N ���������.

								 /* 3. �����, ��������� �� ������ ��� ��������, ������� �� ������ ��������. ��������� ��������� ������ �������� � 0.*/
	bool eraseAllItemsEvenPositions() { CHECK_SIZE;  eraseItemsByPositions(false);  return true; }

	/* 4. �����, ��������� �� ������ ��� ��������, ������� �� �������� ��������. ��������� ��������� ������ �������� � 0. */
	bool eraseAllItemsOddPositions() { CHECK_SIZE; eraseItemsByPositions(true);  return true; }

	/* 5. �����, ��������� �� ������ ������ N�� �� ����� �������. ��������� ��������� ������� � 1 */
	bool eraseAllItemsMultiple(int n) { if (n > m_sizeList || n < 2) return false; eraseItemsByPositions(false, n); return true; }

	/* 6.  �����, �������� ������� ������ � ��������� ������� ������. */
	bool reverseFirstAndLast() {
		CHECK_SIZE; T temp = beginList->value; beginList->value = endList->value;
		endList->value = temp; return true;
	}

	/* 7. �������� � ������ ������ CList �����, ��������� �� ������ ��� �������� �� ��������� N */
	void delAllItemByValue(T value) { while (delItemByValue(value)); }

	/* 8. �����, ������������� �������� ������ ������������ �� ��������� ��������� */
	bool invertionList();

	/* 9. �����, ���������� ���������� ������ ������ �� N ��������. */
	bool nonArithmeticalShiftRight(int countShift); 

	/* 10. �����, ���������� ���������� ������ ����� �� N �������� */
	bool nonArithmeticalShiftLeft(int countShift); 
};


template<class T>
bool �List<T>::nonArithmeticalShiftLeft(int countShift)
{
	CHECK_SIZE;

	while (countShift--)
	{
		Node<T> *iterator = beginList;
		T temp_value = beginList->value;
		while (iterator->next)
		{
			iterator->value = iterator->next->value;
			iterator = iterator->next;
		}
		endList->value = temp_value;
	}
	return true;
}

template<class T>
bool �List<T>::nonArithmeticalShiftRight(int countShift)
{
	CHECK_SIZE;

	if (countShift < 1)
		return false;
	
	while (countShift--)
	{
		Node<T> *iterator = endList;
		T temp_value = endList->value;
		while (iterator->prev)
		{
			iterator->value = iterator->prev->value;
			iterator = iterator->prev;
		}
		beginList->value = temp_value;
	}
	return true;	
}

template<class T>
bool �List<T>::invertionList()
{
	CHECK_SIZE;
	Node<T> *temp_begin = beginList, *temp_end = endList;
	T temp_value;
	for (int i = m_sizeList / 2; i--; i > 0)
	{
		temp_value = temp_begin->value;
		temp_begin->value = temp_end->value;
		temp_end->value = temp_value;
		temp_begin = temp_begin->next;
		temp_end = temp_end->prev;
	}
	return true;
}

template<class T>
void �List<T>::eraseItemsByPositions(bool odd, int number)
{
	if (!m_sizeList)
		return;

	int n, i;
	if (!number) {  
		n = 2; i = 0;    
	}
	else { 
		n = number; i = 1; 
	}

	int temp_list_size = m_sizeList;
	Node<T> *temp, *iterator = beginList;

	do {

		if (odd && (i % n) || !odd && !(i % n))
		{
			temp = iterator;
			iterator = iterator->next;
			delItemByValue(temp->value);
			continue;
		}

		iterator = iterator->next;

		if (i == temp_list_size)
			break;

	} while (iterator && ++i);
}

template<class T>
bool �List<T>::eraseFirstItems(int n)
{
	CHECK_LIST_SIZE_AND_N;

	Node<T>*temp;

	for (int i = 0; i < n; i++)
	{
		temp = beginList;
		beginList = beginList->next;
		beginList->prev = nullptr;
		delete temp;
		m_sizeList--;
	}

	return true;
}

template<class T>
bool �List<T>::eraseLastItems(int n)
{
	CHECK_LIST_SIZE_AND_N;

	Node<T>*temp;

	for (int i = 0; i < n; i++)
	{
		temp = endList;
		endList = endList->prev;
		endList->next = nullptr;
		delete temp;
		m_sizeList--;
	}

	return true;
}

template<class T>
void �List<T>::add(T t)
{
	m_sizeList++;
	Node<T> *temp = new Node<T>;
	temp->value = t;
	temp->next = nullptr;

	if (beginList == nullptr && endList == nullptr) // first add
	{
		temp->prev = nullptr;
		beginList = temp;
		endList = temp;
		return;
	}

	temp->prev = endList;
	endList->next = temp;
	endList = temp;
}

template<class T>
bool �List<T>::delItemByValue(T value)
{
	Node<T>*temp = beginList;
	while (temp) {
		if (temp->value == value)
		{
			if (temp == beginList)
			{
				beginList = beginList->next;
				m_sizeList-- > 1 ? beginList->prev = nullptr : 0;
				delete temp;
				return true;
			}
			else if (temp == endList)
			{
				endList = endList->prev;
				endList->next = nullptr;
				delete temp;
				m_sizeList--;
				return true;
			}
			else
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				delete temp;
				m_sizeList--;
				return true;
			}
		}
		temp = temp->next;
	}
	delete temp;
	return false;
}



