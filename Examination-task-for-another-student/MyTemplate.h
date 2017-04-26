#ifndef MYTEMPLATE_H
#define MYTEMPLATE_H

#include "CFloat.h"
#include "CInt.h"

template <class T>
class MyTemplate
{
public:
	MyTemplate(T *A1 = nullptr, T *A2 = nullptr, int size = NULL);
	~MyTemplate();
	void likeTerms();
	MyTemplate(const MyTemplate &obj);
	MyTemplate<T>& operator=(const MyTemplate<T> & obj); // Оператор присваивания
	
	friend std::ostream& operator<<(std::ostream& os, const MyTemplate<T>& obj) {

		os << "size = " << obj.m_sizeInput << std::endl;
		if (obj.m_sizeInput)
		{
			cout << "K1 = [";
			for (int i = 0; i < obj.m_sizeInput - 1; i++)
				os << obj.m_K1[i] << ",";
			os << obj.m_K1[obj.m_sizeInput - 1] << "]\n";


			cout << "A1 = [";
			for (int i = 0; i < obj.m_sizeInput - 1; i++)
				os << obj.m_A1[i] << ",";
			os << obj.m_A1[obj.m_sizeInput - 1] << "]\n";
		}

		if (obj.m_sizeOut)
		{
			cout << "K2 = [";
			for (int i = 0; i < obj.m_sizeOut - 1; i++)
				os << obj.m_K2[i] << ",";
			os << obj.m_K2[obj.m_sizeOut - 1] << "]\n";


			cout << "A2 = [";
			for (int i = 0; i < obj.m_sizeOut - 1; i++)
				os << obj.m_A2[i] << ",";
			os << obj.m_A2[obj.m_sizeOut - 1] << "]\n";
		}
		return os;
	}

	
private:
	T *m_A1; // Исходные данные 
	T *m_K1; // Исходные данные 
	int m_sizeInput; // Размер массива исходных данных 

	T *m_A2; // выходные данные
	T *m_K2; // выходные данные
	int m_sizeOut; // Размер выходного массива
};

template <class T>
MyTemplate<T>::MyTemplate(const MyTemplate &obj)
{
	this->m_sizeInput = obj.m_sizeInput;
	this->m_sizeOut = obj.m_sizeOut;

	if (obj.m_sizeInput)
	{
		this->m_A1 = new T[obj.m_sizeInput];
		this->m_K1 = new T[obj.m_sizeInput];
		for (int i = 0; i < m_sizeInput; i++)
		{
			this->m_A1[i] = obj.m_A1[i];
			this->m_K1[i] = obj.m_K1[i];
		}
	}

	if (obj.m_sizeOut)
	{
		this->m_A2 = new T[obj.m_sizeOut];
		this->m_K2 = new T[obj.m_sizeOut];
		for (int i = 0; i < m_sizeOut; i++)
		{
			this->m_A2[i] = obj.m_A2[i];
			this->m_K2[i] = obj.m_K2[i];
		}
	}
}

template <class T>
MyTemplate<T>::~MyTemplate()
{
	if (m_sizeInput)
	{
		delete[] m_A1;
		delete[] m_K1;
	}

	if (m_sizeOut)
	{
		delete[] m_A2;
		delete[] m_K2;
	}
}

template<class T>
void MyTemplate<T>::likeTerms()
{
	if (m_sizeOut > 0)
		std::cout << "Error! likeTerms for this object already used!" << std::endl;

	m_sizeOut = m_sizeInput;

	T *N = new T[m_sizeInput];

	for (int i = 0; i < m_sizeInput; i++)
		N[i] = T(0);

	/* Цикл создания массива уникальных не повторяющихся степеней ) */
	T *temp_k2 = new T[m_sizeInput];
	int k = 0;
	temp_k2[k] = m_K1[k];
	bool flag = true;
	for (int i = 1; i < m_sizeInput; i++)
	{
		for (int j = k; j >= 0; j--)
		{
			if (m_K1[i] == temp_k2[j])
			{
				flag = false;
				m_sizeOut--;
			}
		}
		if (flag)
		{
			k++;
			temp_k2[k] = m_K1[i];
		}
		flag = true;
	}

	T *temp;
	/* Цикл создание массива коэфициентов */
	for (int i = 0; i < m_sizeInput; i++)
	{
		for (int j = 0; j < m_sizeOut; j++)
		{
			if (m_K1[i] == temp_k2[j])
			{
				N[j] = N[j] + m_A1[i];
				
			}
		}
	}

	m_A2 = new T[m_sizeOut];
	m_K2 = new T[m_sizeOut];

	for (int i = 0; i < m_sizeOut; i++)
	{
		m_A2[i] = N[i];
		m_K2[i] = temp_k2[i];
	}

	delete[] temp_k2;
	delete[] N;
}


template <class T>
MyTemplate<T>::MyTemplate(T *A1, T *K1, int size) : m_sizeInput(size)
{
	if (size != NULL)
	{
		m_A1 = new T[size];
		m_K1 = new T[size];
	}
	for (int i = 0; i < size; i++)
	{
		m_A1[i] = A1[i];
		m_K1[i] = K1[i];
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
		this->m_A1 = new T[obj.m_sizeInput];
		this->m_K1 = new T[obj.m_sizeInput];
		for (int i = 0; i < m_sizeInput; i++)
		{
			this->m_A1[i] = obj.m_A1[i];
			this->m_K1[i] = obj.m_K1[i];
		}
	}

	if (obj.m_sizeOut)
	{
		this->m_A2 = new T[obj.m_sizeOut];
		this->m_K2 = new T[obj.m_sizeOut];
		for (int i = 0; i < m_sizeOut; i++)
		{
			this->m_A2[i] = obj.m_A2[i];
			this->m_K2[i] = obj.m_K2[i];
		}
	}

	return *this;
}


#endif