#ifndef MYCLASS_H
#define MYCLASS_H

#include "Number.h"
#include "Int.h"
#include "Float.h"

class MyClass 
{
public:
	MyClass(Number **A1 = nullptr,  const int size = NULL);
	MyClass(const MyClass &obj); // ����������� ����������� 
	~MyClass(); // ���������� �� ��������� 
	friend std::ostream& operator<<(std::ostream&, const MyClass&); //�������� ������
	void likeTerms(); // �������� ��������
	MyClass& operator=(const MyClass &obj);
private:
	
	/*�������� ������, ����������� ���������� ������������ �� ������������*/
	Number **A; // �������� ������  
	int m_sizeInput; // ������ ������� �������� ������ 

	Number **C; // �������� ������
	Number **B; // �������� ������
	int m_sizeOut;
};	


#endif
