#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

bool isPunctW(wchar_t c)
{
	wchar_t puncts[] = { '!', '#' , '$' , '%' , '&', '(', ')', '*' , '+', ',', '-', '.', '/', '"' } ;

	for(int i = 0; i < sizeof(puncts) / sizeof(wchar_t); i++)
	{
		if (c == puncts[i])
			return true;
	}
	return false;
}

void erasePunctsEnd(wstring &word)
{
	if( isPunctW ( word[word.length() -1] ) ){
		word.pop_back();
		erasePunctsEnd(word);
	}
}

void addWord(map<wstring, int> &words, wstring &word)
{
	erasePunctsEnd(word);

	if ( isPunctW (word[0]) )
	{
		cout << "Is Punct";
		word.erase(0,1);
	}

	if ( words.count(word) )
	{
		auto it = words.find(word);
		words[word] = (it->second + 1);
	}
	else
		words[word] = 1;
}

void printStat(int count, map<wstring, int> &words)
{
	int count_unique = 0;

	wcout << L"    Слово:";
	wcout.width(20);
	wcout.setf(ios::right);
	wcout << L"Кол-во:" << endl;
	wcout.unsetf(ios::right);
	for ( auto w : words)
	{
		cout.width(2);
		cout.setf(ios::right);
		cout << ++count_unique << ". ";
		wcout.width(20);
		wcout.setf(ios::left);
		wcout << w.first << " " << w.second << endl;
	}
	wcout << L"Всего слов: " << count << endl;
	wcout << L"Из них уникальных: " << count_unique << endl;
}

int main()
{	
	std::wcout.imbue(std::locale("rus_rus.866"));

    map<wstring, int> words;
	wstring word;
	int count = 0;

	std::wifstream fin;
	fin.imbue(std::locale("rus_rus.1251"));

	fin.open("text.txt");

	if( !fin.is_open())
	{
		std::wcout<<L"Файл не найден\n";
		exit(-1) ;
	}
	
	fin.seekg(0, ios::end); 
	int length = fin.tellg();
	fin.seekg(0, ios::beg);

	if ( !length ) {
		std::wcout<<L"Файл Пуст!\n";
		exit(-1);
	}

	while (!fin.eof())
	{
		count++;
		fin >> word;
		addWord(words,word);
	}
	printStat(count, words);
	return 0;
}