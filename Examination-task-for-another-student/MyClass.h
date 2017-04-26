#ifndef MYCLASS_H
#define MYCLASS_H

#include "Number.h"
#include "Int.h"
#include "Float.h"

class MyClass 
{
public:
	MyClass(Number **A1 = nullptr, Number **K1 = nullptr, const int size = NULL);
	MyClass(const MyClass &obj); // ����������� ����������� 
	~MyClass(); // ���������� �� ��������� 
	friend std::ostream& operator<<(std::ostream&, const MyClass&); //�������� ������
	void likeTerms(); // �������� ��������
	MyClass& operator=(const MyClass &obj);
private:
	
	/*�������� ������, ����������� ���������� ������������ �� ������������*/
	Number **m_A1; // �������� ������ 
	Number **m_K1; // �������� ������ 
	int m_sizeInput; // ������ ������� �������� ������ 

	Number **m_A2; // �������� ������
	Number **m_K2; // �������� ������
	int m_sizeOut; // ������ ��������� �������
	
};	


#endif
