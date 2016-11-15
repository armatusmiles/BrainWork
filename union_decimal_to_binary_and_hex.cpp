#include <iostream>

using namespace std;

union Union
{
	unsigned int number;
	unsigned char bytes[4];
};

void showAllBytes(Union *n) {
	for (int i = 0; i < 4; i++)
		cout << "byte[" << i << "] = " << (int)(n->bytes[i]) << endl;
}

void showSelectByte(Union *n, int select_byte) {
	cout << "Select byte[" << select_byte << "] = " << (int)(n->bytes[select_byte]) << endl;
}

void showBinaryAllBytes(Union *n)
{
	short size_byte = 7, temp;
	bool bits[8];
	for (int i = 3; i >= 0; i--)
	{
		temp = n->bytes[i];
		for (int i = 0; i < 8; i++)
			(bits[size_byte - i] = (temp % 2 ? 1 : 0)) & (temp = temp >> 1);
		for (int i = 0; i < 8; i++) cout << bits[i];
		cout << " ";
	}
	cout << endl;
}

void showHeximalAllBytes(Union *n)
{
	cout << "In Heximal:" << endl;
	for (int i = 0; i < 4; i++)
		printf("byte %d = %x \n", i, (int)(n->bytes[i]));
}


int main()
{
	Union *n = new Union;
	n->number = 254;
	showAllBytes(n);
	showSelectByte(n, 0); //int имееет 4 байта, отсчет начинаем с 0, значит диапазон второго значение должен быть от 0 до 3 включительно
	showBinaryAllBytes(n);
	showHeximalAllBytes(n);
	delete n;
}