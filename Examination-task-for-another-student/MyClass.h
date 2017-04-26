#ifndef MYCLASS_H
#define MYCLASS_H

#include "Number.h"
#include "Int.h"
#include "Float.h"

class MyClass 
{
public:
	MyClass(Number **A1 = nullptr, Number **K1 = nullptr, const int size = NULL);
	MyClass(const MyClass &obj); // Конструктор копирования 
	~MyClass(); // Деструктор по умолчанию 
	friend std::ostream& operator<<(std::ostream&, const MyClass&); //Оператор вывода
	void likeTerms(); // Алгоритм подсчета
	MyClass& operator=(const MyClass &obj);
private:
	
	/*Исходные данные, необходимые алгоритмам записываются из конструктора*/
	Number **m_A1; // Исходные данные 
	Number **m_K1; // Исходные данные 
	int m_sizeInput; // Размер массива исходных данных 

	Number **m_A2; // выходные данные
	Number **m_K2; // выходные данные
	int m_sizeOut; // Размер выходного массива
	
};	


#endif
