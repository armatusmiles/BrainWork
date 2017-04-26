#ifndef MYTEMPLATE_H
#define MYTEMPLATE_H

#include "CFloat.h"
#include "CInt.h"

template <class T>
class MyTemplate
{
public:
	MyTemplate(T *A1 = nullptr, int size = NULL);
	~MyTemplate();
	void likeTerms();
	MyTemplate(const MyTemplate &obj);
	MyTemplate<T>& operator=(const MyTemplate<T> & obj); // ќператор присваивани€
	
	friend std::ostream& operator<<(std::ostream& os, const MyTemplate<T>& obj) {

		for (int i = 0; i < obj.m_sizeInput; i++)
		{
			std::cout << obj.A[i] << " ";
		}
		std::cout << std::endl << std::endl;

		for (int i = 0; i < obj.m_sizeOut; i++)
		{
			std::cout << obj.B[i] << " ";
			std::cout << obj.C[i] << std::endl;
		}
		return os;
	}

	
private:
	/*»сходные данные, необходимые алгоритмам записываютс€ из конструктора*/
	T *A; // »сходные данные  
	int m_sizeInput; // –азмер массива исходных данных 

	T *C; // выходные данные
	T *B; // выходные данные
	int m_sizeOut;
};

template <class T>
MyTemplate<T>::MyTemplate(const MyTemplate &obj)
{
	this->m_sizeInput = obj.m_sizeInput;
	this->m_sizeOut = obj.m_sizeOut;

	if (obj.m_sizeInput)
	{
		this->A = new T[obj.m_sizeInput];
		for (int i = 0; i < m_sizeInput; i++)
		{
			this->A[i] = obj.A[i];
		}
	}

	this->B = new T[obj.m_sizeInput / 2];
	this->C = new T[obj.m_sizeInput / 2];

	if (obj.m_sizeOut)
	{
		for (int i = 0; i < m_sizeOut; i++)
		{
			this->B[i] = obj.B[i];
			this->C[i] = obj.C[i];
		}
	}
}

template <class T>
MyTemplate<T>::~MyTemplate()
{
	delete[] A;
	delete[] B;
	delete[] C;
}

template<class T>
void MyTemplate<T>::likeTerms()
{
	m_sizeOut = m_sizeInput / 2;

	T *A2 = new T[m_sizeInput];

	for (int i = 0; i < m_sizeInput; i++)
		A2[i] = A[i];

	// размерность массивов
	int n = m_sizeInput, z = m_sizeOut;

	//временные переменные
	T Nul = T(0);
	T min;
	T temp;

	// переменные дл€ хранени€ индексов
	int ind_1, ind_2, k = 0;

	while (n > 1)
	{
		min = T(10000);
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				temp = A2[i] - A2[j];
				if (temp < Nul)
				{
					temp = Nul - temp; //ѕолучаем модуль минусового числа
				}

				if (min > temp)
				{
					min = temp;
					ind_1 = i;
					ind_2 = j;
				}
			}
		}

		if (n == 2)
		{
			ind_1 = 0;
			ind_2 = 1;
		}

		if (A2[ind_1] > A2[ind_2])
		{
			B[k] = A2[ind_2];
			C[k] = A2[ind_1];
		}
		else
		{
			B[k] = A2[ind_1];
			C[k] = A2[ind_2];
		}
		++k;
		--n;

		if (ind_2 > ind_1)
			ind_2--;

		for (int j = ind_1; j < n; j++)
		{
			A2[j] = A2[j + 1];
		}

		--n;
		for (int j = ind_2; j < n; j++)
		{
			A2[j] = A2[j + 1];
		}
	}

	delete []A2;
}


template <class T>
MyTemplate<T>::MyTemplate(T *A1, int size) : m_sizeInput(size)
{
	if (size != NULL)
	{
		A = new T[size];
		B = new T[size / 2];
		C = new T[size / 2];

		for (int i = 0; i < size; i++)
			A[i] = A1[i];
	}

	m_sizeOut = NULL;
}

template<class T>
MyTemplate<T>& MyTemplate<T>::operator=(const MyTemplate<T> & obj)
{
	if (this->m_sizeInput > 0)
		this->~MyTemplate();

	this->m_sizeInput = obj.m_sizeInput;
	this->m_sizeOut = obj.m_sizeOut;

	if (obj.m_sizeInput)
	{
		this->A = new T[obj.m_sizeInput];
		for (int i = 0; i < m_sizeInput; i++)
		{
			this->A[i] = obj.A[i];
		}
	}

	this->B = new T[obj.m_sizeInput / 2];
	this->C = new T[obj.m_sizeInput / 2];

	if (obj.m_sizeOut)
	{
		for (int i = 0; i < m_sizeOut; i++)
		{
			this->B[i] = obj.B[i];
			this->C[i] = obj.C[i];
		}
	}

	return *this;
}


#endif