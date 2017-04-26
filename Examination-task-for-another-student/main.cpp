#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "MyClass.h"
#include "MyTemplate.h"

using namespace std;


int main()
{
		_CrtDumpMemoryLeaks();
	
		/* ���������������� ������ MyClass, Int � ������������ ����������� */		
		/*srand(time(0));
		int size = 5 + rand() % 10;
		Number **A1 = new Number*[size];
		Number **K1 = new Number*[size];

		for (int i = 0; i < size; i++)
		{
			A1[i] = new Int(1 + rand() % 5);
			K1[i] = new Int(1 + rand() % 5);
		}

		MyClass m(A1, K1, size);
		MyClass m2(m); //����� ������������ �����������
		m2.likeTerms();
		cout << m2;
	
		for (int i = 0; i < size; i++)
		{
			delete A1[i];
			delete K1[i];
		}
		delete A1;
		delete K1;*/

		


		/* ���������������� ������ MyClass, Float � ��������� ������������*/

		/*srand(time(0));
		int size = 5 + rand() % 10;
		Number **A1 = new Number*[size];
		Number **K1 = new Number*[size];

		for (int i = 0; i < size; i++)
		{
			A1[i] = new Float(1 + rand() % 5);
			K1[i] = new Float(1 + rand() % 5);
		}

		MyClass m(A1, K1, size);
		MyClass m2;
		m2 = m; //����� ��������� ������������
		m2.likeTerms();
		cout << m2;

		for (int i = 0; i < size; i++)
		{
			delete A1[i];
			delete K1[i];
		}
		delete A1;
		delete K1;
		*/



		/* ������������ ������������ ����������� � ������ MyTemplate � CInt*/
		
		/*
		srand(time(0));

		const int sizeOfArray = 10;
		CInt Array3a[sizeOfArray]; CInt Array3b[sizeOfArray];
		for (int i = 0; i < sizeOfArray; i++)
			Array3a[i] = CInt(5 + rand() % 5);

		for (int i = 0; i < sizeOfArray; i++)
			Array3b[i] = CInt(5 + rand() % 5);
		MyTemplate<CInt>* CIntA1 = new MyTemplate<CInt>(Array3a, Array3b, sizeOfArray);

		CIntA1->likeTerms();
		cout << *CIntA1;

		delete CIntA1;
		*/


		/* ������������ ������������ ����������� � ������ MyTemplate � float*/
		/*
		srand(time(0));
		const int sizeOfArray = 10;
		float Array3a[sizeOfArray]; float Array3b[sizeOfArray];
		for (int i = 0; i < sizeOfArray; i++)
			Array3a[i] = float( 5 + rand() % 5);

		for (int i = 0; i < sizeOfArray; i++)
			Array3b[i] = float(5 + rand() % 5);

		MyTemplate<float> CIntA1(Array3a, Array3b, sizeOfArray);

		MyTemplate<float> CIntA2(CIntA1); //����� ������������ �����������.
		CIntA2.likeTerms();
		cout << CIntA2;
		*/
		
		
	
		/*������������ ��������� ������������ � ������ MyTemplate � CFloat*/
		/*srand(time(0));
		const int sizeOfArray = 10;
		CFloat Array3a[sizeOfArray]; CFloat Array3b[sizeOfArray];
		for (int i = 0; i < sizeOfArray; i++)
			Array3a[i] = CFloat(5 + rand() % 5);

		for (int i = 0; i < sizeOfArray; i++)
			Array3b[i] = CFloat(5 + rand() % 5);
		
		MyTemplate<CFloat> CIntA1 = MyTemplate<CFloat>(Array3a, Array3b, sizeOfArray);

		MyTemplate<CFloat> CIntA2;

		CIntA2 = CIntA1; // ����� ��������� ������������ 
	
		CIntA2.likeTerms();
		cout << CIntA2;*/



		/*������������ ��������� ������������ � ������ MyTemplate � CInt*/
		/*srand(time(0));
		const int sizeOfArray = 10;
		CInt Array3a[sizeOfArray]; CInt Array3b[sizeOfArray];
		for (int i = 0; i < sizeOfArray; i++)
			Array3a[i] = CInt(5 + rand() % 5);

		for (int i = 0; i < sizeOfArray; i++)
			Array3b[i] = CInt(5 + rand() % 5);

		MyTemplate<CInt> CIntA1 = MyTemplate<CInt>(Array3a, Array3b, sizeOfArray);
	
		MyTemplate<CInt> CIntA2;

		CIntA2 = CIntA1; // ����� ��������� ������������ 

		CIntA2.likeTerms();
		cout << CIntA2;
		*/


	

		/* MyClass ���������� � ����������� ���� ��� �������� �� ������ ������ */
		/*while (true)
		{
			srand(time(0));
			int size = 5 + rand() % 10;
			Number **A1 = new Number*[size];
			Number **K1 = new Number*[size];

			for (int i = 0; i < size; i++)
			{
				A1[i] = new Int(1 + rand() % 5);
				K1[i] = new Int(1 + rand() % 5);
			}

			MyClass m(A1, K1, size);
			MyClass m2(m); //����� ������������ �����������
			m2.likeTerms();
			for (int i = 0; i < size; i++)
			{
				delete A1[i];
				delete K1[i];
			}
			delete A1;
			delete K1;
		}*/


		/* MyTemplate ���������� � ����������� ���� ��� �������� �� ������ ������ */
		
		/*while (true)
		{
			srand(time(0));
			const int sizeOfArray = 10;
			CInt Array3a[sizeOfArray]; CInt Array3b[sizeOfArray];
			for (int i = 0; i < sizeOfArray; i++)
				Array3a[i] = CInt(5 + rand() % 5);

			for (int i = 0; i < sizeOfArray; i++)
				Array3b[i] = CInt(5 + rand() % 5);

			MyTemplate<CInt> CIntA1 = MyTemplate<CInt>(Array3a, Array3b, sizeOfArray);

			MyTemplate<CInt> CIntA2;

			CIntA2 = CIntA1; // ����� ��������� ������������

			CIntA2.likeTerms();
		}*/



	/* MyTemplate ���������� � ����������� ���� ��� �������� �� ������ ������ 
	   ��������� ���������� � ������� ��������� �� � ������� ������������ �� ���������*/

		/*while (true)
		{
			srand(time(0));
			const int sizeOfArray = 10;
			CInt Array3a[sizeOfArray]; CInt Array3b[sizeOfArray];
			for (int i = 0; i < sizeOfArray; i++)
				Array3a[i] = CInt(5 + rand() % 5);

			for (int i = 0; i < sizeOfArray; i++)
				Array3b[i] = CInt(5 + rand() % 5);

			MyTemplate<CInt> CIntA1 = MyTemplate<CInt>(Array3a, Array3b, sizeOfArray);

			MyTemplate<CInt> CIntA2(Array3a, Array3b, sizeOfArray);

			CIntA2 = CIntA1; // ���������� �������  ���������� �� � ������� ������������ �� ���������

			CIntA2.likeTerms();
		}*/


		

		/* MyClass ���������� � ����������� ���� ��� �������� �� ������ ������
		��������� ���������� � ������� ��������� �� � ������� ������������ �� ���������*/
	
	/*while (true)
	{
		srand(time(0));
		int size = 5 + rand() % 10;
		Number **A1 = new Number*[size];
		Number **K1 = new Number*[size];

		for (int i = 0; i < size; i++)
		{
		A1[i] = new Float(1 + rand() % 5);
		K1[i] = new Float(1 + rand() % 5);
		}

		MyClass m(A1, K1, size);
		MyClass m2(A1, K1, size);
		m2 = m; //����� ��������� ������������
		m2.likeTerms();

		for (int i = 0; i < size; i++)
		{
		delete A1[i];
		delete K1[i];
		}
		delete A1;
		delete K1;
	}
	*/
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}


