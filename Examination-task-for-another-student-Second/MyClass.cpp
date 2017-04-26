#include "MyClass.h"
#include <iostream>

MyClass::MyClass(Number **A1, const int size): m_sizeInput(size)
{
	if (size != NULL)
	{
		A = new Number*[m_sizeInput];
		B = new Number*[m_sizeInput / 2];
		C = new Number*[m_sizeInput / 2];
	}
	
	for (int i = 0; i < m_sizeInput; i++)
		A[i] = A1[i]->Copy();
	
	m_sizeOut = NULL;
}



MyClass::~MyClass()
{

	for (int i = 0; i < m_sizeInput; i++)
		delete A[i];
	delete A;

	for (int i = 0; i < m_sizeOut; i++)
	{
		delete B[i];
		delete C[i];
	}
	delete B;
	delete C;
}


void MyClass::likeTerms()
{
	m_sizeOut = m_sizeInput / 2;

	Number **A2 = new Number*[m_sizeInput];
	
	for (int i = 0; i < m_sizeInput; i++)
		A2[i] = A[i]->Copy();

	// размерность массивов
	int n = m_sizeInput, z = m_sizeOut;

	//временные переменные
	Number *Nul = &(*A2[0] - *A2[0]);
	Number *min;
	Number *temp;
	Number *temp2;

	// переменные для хранения индексов
	int ind_1, ind_2, k = 0;

	while (n > 1)
	{
		min = A2[0]->Copy();
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				temp = &(*A2[i] - *A2[j]);
				if (*temp < *Nul)
				{
					temp2 = &((*Nul) - (*temp)); //Получаем модуль минусового числа
					delete temp;
					temp = temp2;
				}

				if (*min > *temp)
				{
					delete min;
					min = temp->Copy();
					ind_1 = i;
					ind_2 = j;
				}
				delete temp;
			}
		}
		delete min;

		if (n == 2)
		{
			ind_1 = 0;
			ind_2 = 1;
		}


		if (*A2[ind_1] > *A2[ind_2])
		{
			B[k] = A2[ind_2]->Copy();
			C[k] = A2[ind_1]->Copy();
		}
		else
		{
			B[k] = A2[ind_1]->Copy();
			C[k] = A2[ind_2]->Copy();
		}
		++k;
		--n;

		if (ind_2 > ind_1)
				ind_2--;

		for (int j = ind_1; j < n; j++)
		{
			delete A2[j];
			A2[j] = A2[j + 1]->Copy();
		}

		--n;
		for (int j = ind_2; j < n; j++)
		{
			delete A2[j];
			A2[j] = A2[j + 1]->Copy();
		}
	}

	for (int i = 0; i < m_sizeInput; i++)
		delete A2[i];

	delete Nul;
	delete A2;
}

MyClass::MyClass(const MyClass &obj)
{	
	this->m_sizeInput = obj.m_sizeInput;
	this->m_sizeOut = obj.m_sizeOut;

	if (obj.m_sizeInput)
	{
		this->A = new Number*[obj.m_sizeInput];
		
		for (int i = 0; i < m_sizeInput; i++)
		{
			this->A[i] = obj.A[i]->Copy();
		}
	}

	this->B = new Number*[obj.m_sizeInput / 2];
	this->C = new Number*[obj.m_sizeInput / 2];
	if (obj.m_sizeOut)
	{
		for (int i = 0; i < m_sizeOut; i++)
		{
			this->B[i] = obj.B[i]->Copy();
			this->C[i] = obj.C[i]->Copy();
		}
	}
	
}

MyClass& MyClass::operator=(const MyClass &obj)
{
	if(this->m_sizeInput > 0) 
		this->~MyClass(); 

	this->m_sizeInput = obj.m_sizeInput;
	this->m_sizeOut = obj.m_sizeOut;

	if (obj.m_sizeInput)
	{
		this->A = new Number*[obj.m_sizeInput];

		for (int i = 0; i < m_sizeInput; i++)
		{
			this->A[i] = obj.A[i]->Copy();
		}
	}

	this->B = new Number*[obj.m_sizeInput / 2];
	this->C = new Number*[obj.m_sizeInput / 2];
	if (obj.m_sizeOut)
	{
		for (int i = 0; i < m_sizeOut; i++)
		{
			this->B[i] = obj.B[i]->Copy();
			this->C[i] = obj.C[i]->Copy();
		}
	}

	return *this;
}


std::ostream& operator<<(std::ostream& os, const MyClass& obj) {

	char elem[50];

	for (int i = 0; i < obj.m_sizeInput; i++)
	{
		obj.A[i]->ToString(elem);
		std::cout << elem << " ";
	}
	std::cout << std::endl << std::endl;

	for (int i = 0; i < obj.m_sizeOut; i++)
	{
		obj.B[i]->ToString(elem);
		std::cout << elem << " ";
		obj.C[i]->ToString(elem);
		std::cout << elem << std::endl;
	}
	return os;
}