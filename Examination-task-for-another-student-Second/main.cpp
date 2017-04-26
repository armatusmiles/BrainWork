#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "MyClass.h"
#include "MyTemplate.h"

using namespace std;

int main()
{
		_CrtDumpMemoryLeaks();

		/* Демонстрационная работы MyClass, Int и конструктора копирования */
		/*srand(time(0));
		int size = (4 + rand() % 5) * 2;
		Number **A1 = new Number*[size];

		for (int i = 0; i < size; i++)
			A1[i] = new Int(2 + rand() % 30);
		

		MyClass m(A1, size);

		MyClass m2(m);
		m2.likeTerms();
		cout << m2;
		for (int i = 0; i < size; i++)
		{
			delete A1[i];
		}
		delete A1;*/


		/* Демонстрационная работы MyClass, Float и оператора присваивания */		
		/*srand(time(0));
		int size = (4 + rand() % 5) * 2;
		Number **A1 = new Number*[size];

		for (int i = 0; i < size; i++)
			A1[i] = new Float(2 + rand() % 30);


		MyClass m(A1, size);

		MyClass m2 = m;
		m2 = m;
		m2.likeTerms();
		cout << m2;
		for (int i = 0; i < size; i++)
		{
			delete A1[i];
		}
		delete A1;*/

		
		/* Демонстрация конструктора копирования и работы MyTemplate с CInt*/
			
		/*srand(time(0));

		const int sizeOfArray = (4 + rand() % 5) * 2;
		CInt *Array3a = new CInt[sizeOfArray];
		for (int i = 0; i < sizeOfArray; i++)
			Array3a[i] = CInt(5 + rand() % 25);

		
		MyTemplate<CInt> CIntA1(Array3a, sizeOfArray);

		MyTemplate<CInt> CIntA2(CIntA1);
		CIntA2.likeTerms();
		cout << CIntA2;
		delete[] Array3a;*/



		/* Демонстрация оператора присваивания и работы MyTemplate с CInt*/
		
		srand(time(0));
		const int sizeOfArray = (4 + rand() % 5) * 2;
		CFloat *Array3a = new CFloat[sizeOfArray];
		for (int i = 0; i < sizeOfArray; i++)
			Array3a[i] = CFloat(5 + rand() % 25);

		MyTemplate<CFloat> CIntA1(Array3a, sizeOfArray);

		MyTemplate<CFloat> CIntA2;

		CIntA2 = CIntA1;

		CIntA2.likeTerms();
		cout << CIntA2;

		delete []Array3a;


		/* Демонстрация оператора присваивания и работы MyTemplate с float*/
		/*srand(time(0));
		const int sizeOfArray = (4 + rand() % 5) * 2;
		float *Array3a = new float[sizeOfArray];
		for (int i = 0; i < sizeOfArray; i++)
			Array3a[i] = float(5 + rand() % 25);

		MyTemplate<float> CIntA1(Array3a, sizeOfArray);

		CIntA1.likeTerms();
		cout << CIntA1;

		delete[] Array3a;*/


		/* MyClass погружение в бесконечный цикл */
		/*while (true)
		{
			srand(time(0));
			int size = (4 + rand() % 5) * 2;
			Number **A1 = new Number*[size];

			for (int i = 0; i < size; i++)
				A1[i] = new Int(2 + rand() % 30);


			MyClass m(A1, size);

			MyClass m2(m);
			m2.likeTerms();
			for (int i = 0; i < size; i++)
			{
				delete A1[i];
			}
			delete A1;
		}*/

		/* MyTemplate погружение в вечный цикл*/
		/*while (true)
		{

			srand(time(0));
			const int sizeOfArray = (4 + rand() % 5) * 2;
			int *Array3a = new int[sizeOfArray];
			for (int i = 0; i < sizeOfArray; i++)
				Array3a[i] = int(5 + rand() % 25);

			MyTemplate<int> CIntA1(Array3a, sizeOfArray);

			CIntA1.likeTerms();

			delete []Array3a;
		}*/


	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}


