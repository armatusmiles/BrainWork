#include <iostream>
using std::cout;
using std::endl;

#define NULLIFY_THE_LIST beginList = nullptr; endList = nullptr; m_sizeList = 0, m_grow = 1
#define DEFAULT_VALUE -999999

template<class T>
class Node
{
public:
	T value;
	Node *next;
	Node *prev;
};

template<class T>
class ArrayLinkedList : public Node<T>
{
private:
	Node *beginList;
	Node *endList;
	int m_sizeList;
	int m_grow;
public:
	ArrayLinkedList(): m_grow(1) { NULLIFY_THE_LIST; }
	~ArrayLinkedList();

	int getSize()      { return m_sizeList; }
	void removeAll()   { this->~ArrayLinkedList(); }
	bool isEmpty()     { if (getUpperBound() == -1) return true; return false; }
	void freeExtra()   { setSize(getUpperBound() + 1, m_grow); }
	Node<T>* getData() { return beginList; }

	T& operator[](int index) { return getAt(index); }
	ArrayLinkedList<T>* operator=(ArrayLinkedList<T> &obj);

	/* Элемент будет вставлятся не первую свободную позицию в массиве
		при необходимости массив будет увеличиватся */
	void add(T value); 
	bool setSize(int size, int grow = 1);	
	int getUpperBound();
	T& getAt(int index);
	void setAt(int index, T new_value);
	void append(ArrayLinkedList<T> &obj);
	/* Если в массиве нет элемента для вставки он расширяется на m_grow элементов*/
	void insertAt(int position_index, T value);
	void removeAt(int position_index);
};

template<class T>
void ArrayLinkedList<T>::removeAt(int position_index)
{
	if (position_index > getUpperBound())
		return;

	Node<T> *iterator = beginList;
	for (int i = 0; i < position_index; i++)
		iterator = iterator->next;
	int counter = getUpperBound() - position_index;
	while (counter--)
	{
		iterator->value = iterator->next->value;
		iterator = iterator->next;
	}
	iterator->value = DEFAULT_VALUE;
}

template<class T>
void ArrayLinkedList<T>::insertAt(int position_index, T value)
{
	/* Если индекс для вставки больше последнего допустимого индекса
		элемент добавляю в конец массива */
	if (position_index > getUpperBound()) {
		add(value); return;
	}

	if( m_sizeList - 1 >= getUpperBound() )
		setSize(m_sizeList + m_grow, m_grow);

	Node<T> *iterator = endList;
	for (int i = m_sizeList - getUpperBound() - 1 ; i > 0; i--)
		iterator = iterator->prev;

	int count = getUpperBound() - position_index + 1;

	while (count--) {
		iterator->next->value = iterator->value;
		if(iterator->prev != nullptr)
			iterator = iterator->prev;
		else {
			iterator->value = value; return;
		}
	}
	iterator->next->value = value;

}

template<class T>
ArrayLinkedList<T>* ArrayLinkedList<T>::operator=(ArrayLinkedList<T> &obj)
{
	setSize(obj.m_sizeList, obj.m_grow);
	append(obj);
	return this;
}

template<class T>
void ArrayLinkedList<T>::append(ArrayLinkedList<T> &obj)
{
	Node<T> *iterator = obj.beginList;
	while (iterator)
	{
		add(iterator->value);
		iterator = iterator->next;
	}
}

template<class T>
void ArrayLinkedList<T>::setAt(int index, T new_value)
{
	Node<T> *temp = beginList;
	for (int i = 0; i < index; i++)
		temp = temp->next;
	temp->value = new_value;
}

template<class T>
T& ArrayLinkedList<T>::getAt(int index)
{
	if (index >= m_sizeList) {
		T null_obj;
		return null_obj;
	}

	Node<T> *temp = beginList;
	for (int i = 0; i < index; i++)
		temp = temp->next;
	
	return temp->value;
}


template<class T>
int ArrayLinkedList<T>::getUpperBound()
{
	int last_index = -1;
	int counter = 0;
	Node<T>*temp = beginList;
	while (temp) {
		if (temp->value != DEFAULT_VALUE)
			last_index = counter;
		
		temp = temp->next;
		counter++;
	}
	return last_index;
}

template<class T>
bool ArrayLinkedList<T>::setSize(int size, int grow)
{
	if (size < 1)
		return false;

	m_grow = grow;

	if (size < m_sizeList)
	{
		for (int i = m_sizeList - size; i--; i > 0)
		{
			Node<T> *temp = endList;
			endList = endList->prev;
			endList->next = nullptr;
			delete temp;
		}
		m_sizeList =  size;
		return true;
	}
	m_sizeList = size;

	Node<T> *last_element, *iterator = beginList;
	for (int i = 0; i < size; i++)
	{
		if (iterator == nullptr)
		{
			Node<T> *temp = new Node<T>;
			if (beginList == nullptr) {
				beginList = temp; beginList->prev = nullptr;
			}
			iterator = temp;
			iterator->value = DEFAULT_VALUE;
			iterator->next = nullptr;
			if (i) {
				iterator->prev = last_element;
				iterator->prev->next = iterator;
			}
		}
		last_element = iterator;
		iterator = iterator->next;
	}
	endList = last_element;
	return true;
}

template<class T>
void ArrayLinkedList<T>::add(T value)
{
	Node<T> * temp = beginList;
	while (temp) {
		if (temp->value == DEFAULT_VALUE) {
			temp->value = value;
			return;
		}
		temp = temp->next;
	}

	setSize(m_sizeList + m_grow, m_grow);
	add(value);
}

template<class T>
ArrayLinkedList<T>::~ArrayLinkedList() {
	Node *temp;
	while (beginList)
	{
		temp = beginList;
		beginList = beginList->next;
		delete temp;
	}
	NULLIFY_THE_LIST;
}