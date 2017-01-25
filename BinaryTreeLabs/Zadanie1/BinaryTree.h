#include <iostream>
using namespace std;

template<class T>
struct Node
{
	T value;
	Node *left;
	Node *right;
};

template<class T>
class BinaryTree
{
	Node<T> *m_head;
	Node<T> *endList;
	void freeMemory(Node<T> *ptr);
	void r_printTree(Node<T> *ptr);
	void makeList(Node<T> *ptr);
	void freeListMemory();
public:
	BinaryTree() { m_head = nullptr; endList = nullptr; }
	~BinaryTree() { freeMemory(m_head); if (endList != nullptr) freeListMemory(); }
	bool insert(T value);
	T* search(T value);
	void printTree() { Node<T>*ptr = m_head; r_printTree(ptr); }
	bool remove(T value);
	Node<T>* toList();
};

template<class T>
void BinaryTree<T>::freeListMemory()
{
	Node<T> *tmp;
	while (endList)
	{
		tmp = endList;
		endList = endList->left;
		delete tmp;
	}
}

template<class T>
Node<T>* BinaryTree<T>::toList()
{
	if (endList != nullptr)
		freeListMemory();
	
	endList = nullptr;  
	Node<T> *ptr = m_head; 
	makeList(ptr); 
	return endList;
}

template<class T>
void BinaryTree<T>::makeList(Node<T> *ptr)
{
	if (ptr != nullptr)
	{
		makeList(ptr->left);
		makeList(ptr->right);

		Node<T> *tmp = new Node<T>;
		tmp->value = ptr->value;
		if (endList == nullptr) {
			tmp->left = nullptr;
			tmp->right = nullptr;
			endList = tmp;
			return;
		}
		tmp->left = endList;
		tmp->right = nullptr;
		endList->right = tmp;
		endList = tmp;
	}
}


template<class T>
bool BinaryTree<T>::remove(T value)
{
	if (m_head == nullptr)
		return false;

	Node<T> *prev, *iterator = m_head;
	while (true)
	{
		if (value > iterator->value)
		{
			if (iterator->right != nullptr) {
				prev = iterator;
				iterator = iterator->right;
				continue;
			}
			else return false;
		}
		else if (value < iterator->value)
		{
			if (iterator->left != nullptr) {
				prev = iterator;
				iterator = iterator->left;
				continue;
			}
			else return false;

		}
		else if (value == iterator->value)
		{

			if (iterator->right == nullptr && iterator->left == nullptr)
			{
				prev->right == iterator ? prev->right = nullptr : prev->left = nullptr;
				delete iterator;
				return true;
			}
			else if (iterator->right == nullptr) 
			{
				prev->right == iterator ? prev->right = iterator->left : 
					prev->left = iterator->left;
				delete iterator;
				return true;
			}
			else if (iterator->left == nullptr) 
			{
				prev->right == iterator ? prev->right = iterator->right :
					prev->left = iterator->right;
				delete iterator;
				return true;
			}
			else 
			{
				Node<T> * ptmp = nullptr;
				prev = ptmp = iterator->right; 
				while (ptmp->left) 
				{
					prev = ptmp;
					ptmp = ptmp->left;
				}
				iterator->value = ptmp->value; 

				prev->left = ptmp->right; 

				if (ptmp == prev)
				{
					if (!prev->right) 
						iterator->right = nullptr;
					else
						iterator->right = prev->right; 
				}
				delete ptmp;
			}
			return true;
		}		
	}
	return false;
}

template<class T>
void BinaryTree<T>::r_printTree(Node<T> *ptr)
{
	if (ptr != nullptr)
	{
		r_printTree(ptr->left);
		r_printTree(ptr->right);
		cout << ptr->value;
	}
}

template<class T>
T* BinaryTree<T>::search(T value)
{
	if (m_head == nullptr)
		return nullptr;

	Node<T>* iterator = m_head;
	while (true)
	{
		if (value > iterator->value) 
		{
			if (iterator->right != nullptr) {
				iterator = iterator->right;
				continue;
			}
			else return nullptr;
		}
		else if (value < iterator->value) 
		{
			if (iterator->left != nullptr) {
				iterator = iterator->left;
				continue;
			}
			else return nullptr;
			
		}
		else if (value == iterator->value)
			return &iterator->value;

	}
	return nullptr;
}

template<class T>
void BinaryTree<T>::freeMemory(Node<T> *ptr)
{
	if (ptr != nullptr)
	{
		freeMemory(ptr->left);
		freeMemory(ptr->right);
		delete ptr;
	}
}
template<class T>
bool BinaryTree<T>::insert(T value)
{

	if (m_head == nullptr) { //first add
		Node<T> *temp = new Node<T>;
		temp->left = nullptr;
		temp->right = nullptr;
		temp->value = value;
		m_head = temp; return true;
	}

	Node<T>* iterator = m_head;
	while (true)
	{
		if (value > iterator->value) {
			if (iterator->right != nullptr) {
				iterator = iterator->right;
				continue;
			}
			else {
				Node<T>*temp = new Node<T>;
				iterator->right = temp;
				temp->value = value;
				temp->left = nullptr;
				temp->right = nullptr;
				return true;
				break;
			}
		}
		else if (value < iterator->value)
		{
			if (iterator->left != nullptr) {
				iterator = iterator->left;
				continue;
			}
			else {
				Node<T>*temp = new Node<T>;
				iterator->left = temp;
				temp->value = value;
				temp->left = nullptr;
				temp->right = nullptr;
				return true;
				break;
			}
		}
		else break;
	}
	return false;
}