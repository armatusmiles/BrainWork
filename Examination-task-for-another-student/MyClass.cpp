#include "MyClass.h"
#include <iostream>

MyClass::MyClass(Number **A1, Number **K1, const int size): m_sizeInput(size)
{
	if (size != NULL)
	{
		m_A1 = new Number*[m_sizeInput];
		m_K1 = new Number*[m_sizeInput];
	}
	for (int i = 0; i < m_sizeInput; i++)
	{
		m_A1[i] = A1[i]->Copy();
		m_K1[i] = K1[i]->Copy();
	}

	m_sizeOut = NULL;
}

MyClass::~MyClass()
{
	for (int i = 0; i < m_sizeInput; i++)
	{
		delete m_A1[i];
		delete m_K1[i];
	}
	delete m_A1;
	delete m_K1;

	if (m_sizeOut > 0)
	{
		for (int i = 0; i < m_sizeOut; i++)
		{
			delete m_A2[i];
			delete m_K2[i];
		}
		delete m_A2;
		delete m_K2;
	}
}


void MyClass::likeTerms()
{
	if (m_sizeOut > 0)
		std::cout << "Error! likeTerms for this object already used!" << std::endl;

	m_sizeOut = m_sizeInput;


	Number **N = new Number*[m_sizeInput];
	
	for (int i = 0; i < m_sizeInput; i++)
		N[i] = nullptr;


	/* ÷икл создани€ массива уникальных не повтор€ющихс€ степеней ) */
	Number **temp_k2 = new Number*[m_sizeInput];
	int k = 0;
	temp_k2[k] = m_K1[k]->Copy();
	bool flag = true;
	for (int i = 1; i < m_sizeInput; i++)
	{	
		for (int j = k; j >= 0; j--)
		{
			if (*m_K1[i] == *temp_k2[j])
			{
				flag = false;
				m_sizeOut--;
			}
		}
		if (flag)
		{
			k++;
			temp_k2[k] = m_K1[i]->Copy();
		}
		flag = true;
	}
	
	Number *temp; 
	/* ÷икл создание массива коэфициентов */
	for (int i = 0; i < m_sizeInput; i++)
	{
		for (int j = 0; j < m_sizeOut; j++)
		{
			if (*m_K1[i] == *temp_k2[j])
			{
				if (N[j] == nullptr)
					N[j] = m_A1[i]->Copy();
				else
				{
					temp = &(*N[j] + *m_A1[i]);
					delete N[j];
					N[j] = temp;
				}
			}
		}
	}


	m_A2 = new Number*[m_sizeOut];
	m_K2 = new Number*[m_sizeOut];

	for (int i = 0; i < m_sizeOut; i++)
	{
		m_A2[i] = N[i]->Copy();
		m_K2[i] = temp_k2[i]->Copy();
		delete temp_k2[i];
	}

	for (int i = 0; i < m_sizeInput; i++)
		delete N[i];


	delete[] temp_k2;
	delete[] N;
}

MyClass::MyClass(const MyClass &obj)
{
	this->m_sizeInput = obj.m_sizeInput;
	this->m_sizeOut = obj.m_sizeOut;

	if (obj.m_sizeInput)
	{
		this->m_A1 = new Number*[obj.m_sizeInput];
		this->m_K1 = new Number*[obj.m_sizeInput];
		for (int i = 0; i < m_sizeInput; i++)
		{
			this->m_A1[i] = obj.m_A1[i]->Copy();
			this->m_K1[i] = obj.m_K1[i]->Copy();
		}
	}

	if (obj.m_sizeOut)
	{
			this->m_A2 = new Number*[obj.m_sizeOut];
			this->m_K2 = new Number*[obj.m_sizeOut];
		for (int i = 0; i < m_sizeOut; i++)
		{
			this->m_A2[i] = obj.m_A2[i]->Copy();
			this->m_K2[i] = obj.m_K2[i]->Copy();
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
		this->m_A1 = new Number*[obj.m_sizeInput];
		this->m_K1 = new Number*[obj.m_sizeInput];
		for (int i = 0; i < m_sizeInput; i++)
		{
			this->m_A1[i] = obj.m_A1[i]->Copy();
			this->m_K1[i] = obj.m_K1[i]->Copy();
		}
	}

	if (obj.m_sizeOut)
	{
		this->m_A2 = new Number*[obj.m_sizeOut];
		this->m_K2 = new Number*[obj.m_sizeOut];
		for (int i = 0; i < m_sizeOut; i++)
		{
			this->m_A2[i] = obj.m_A2[i]->Copy();
			this->m_K2[i] = obj.m_K2[i]->Copy();
		}
	}

	return *this;
}


std::ostream& operator<<(std::ostream& os, const MyClass& obj) {
	char elem[50];

	os << "size = " << obj.m_sizeInput << std::endl;
	
	if (obj.m_sizeInput != 0) {
		
		os << "K1 = [";
		for (int i = 0; i < obj.m_sizeInput - 1; i++) {
			obj.m_K1[i]->ToString(elem);
			os << elem << ",";
		}
		obj.m_K1[obj.m_sizeInput - 1]->ToString(elem);
		os << elem << "]\n";

		os << "A1 = [";
		for (int i = 0; i < obj.m_sizeInput - 1; i++) {
			obj.m_A1[i]->ToString(elem);
			os << elem << ",";
		}
		obj.m_A1[obj.m_sizeInput - 1]->ToString(elem);
		os << elem << "]\n\n";
		
		if (obj.m_sizeOut != NULL)
		{
			os << "K2 = [";
			for (int i = 0; i < obj.m_sizeOut - 1; i++) {
				obj.m_K2[i]->ToString(elem);
				os << elem << ",";
			}
			obj.m_K2[obj.m_sizeOut - 1]->ToString(elem);
			os << elem << "]\n";

			os << "A2 = [";
			for (int i = 0; i < obj.m_sizeOut - 1; i++) {
				obj.m_A2[i]->ToString(elem);
				os << elem << ",";
			}
			obj.m_A2[obj.m_sizeOut - 1]->ToString(elem);
			os << elem << "]\n";
		}

	}
	return os;
}

