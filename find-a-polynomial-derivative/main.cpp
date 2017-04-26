#include <iostream>
#include <map>
#include <string>
#include <vector>

void getExpressions(std::vector<std::string>&, std::string);
void eraseOnlyNumbers(std::vector<std::string>&);
void addToMap(std::map<int,int>&, std::vector<std::string>&);

std::string derivative(std::string polynomial) {

    using namespace std;

    map<int,int> myMap;

    std::string temp_string;

    if(polynomial[0] != '-')
        temp_string.push_back('+');

   for(unsigned short i = 0; i < polynomial.length(); i++)
    {
        temp_string.push_back(polynomial[i]);
        if(polynomial[i] == 'x')
            if(polynomial[i + 1] != '^') temp_string.append("^1");
    }

    std::vector<std::string>expressions;

    getExpressions(expressions, temp_string);
    eraseOnlyNumbers(expressions);
    addToMap(myMap, expressions);

    int new_koef, new_exponent;

    temp_string.clear();

    for(map<int,int>::reverse_iterator it = myMap.rbegin(); it != myMap.rend(); it++)
    {
        new_koef = it->second * it->first;
        new_exponent = it->first - 1;

        if(new_koef > 0)
            temp_string.push_back('+');

        temp_string.append(std::to_string(new_koef));

        if(new_exponent == 1)
            temp_string.append("*x");
        else if(new_exponent > 1)
            temp_string.append("*x^").append(std::to_string(new_exponent));

    }

    if(temp_string[0] == '+')
        temp_string.erase(temp_string.begin());

    return temp_string;
}

void addToMap(std::map<int,int>& myMap, std::vector<std::string>& expressions)
{

    std::string str_koef, str_stepen ,temp;
    int koef, stepen;

    for(std::vector<std::string>::iterator it = expressions.begin(); it != expressions.end(); ++it)
    {
        for(char c : *it)
        {
            if(c == 'x')
                break;
            str_koef.push_back(c);
        }
        if(str_koef.length() == 1) str_koef.push_back('1');
        koef = atoi(str_koef.c_str());
        str_koef.clear();
        temp = *it;
        for(unsigned short i = temp.find('^') + 1; i< temp.length(); i++)
            str_stepen.push_back(temp[i]);

        stepen = atoi(str_stepen.c_str());
        str_stepen.clear();


        if(myMap.find(stepen)->second)
            myMap.find(stepen)->second += koef;
        else myMap[stepen] = koef;

    }
}

void eraseOnlyNumbers(std::vector<std::string>& expressions)
{
    bool have_x = false;
    for(std::vector<std::string>::iterator it = expressions.begin(); it != expressions.end(); ++it)
    {
        for(char c : *it)
        {
            if ( c == 'x')
                have_x = true;
        }
        if(!have_x)
        {
            expressions.erase(it);
            --it;
        }
        have_x = false;
    }
}


void getExpressions(std::vector<std::string>& expressions, std::string temp_string)
{
    std::string temp2;

    for(unsigned short i = 0; i < temp_string.length(); i++)
    {
        if(i && (temp_string[i] == '+' || temp_string[i] == '-') )
        {
            expressions.push_back(temp2);
            temp2.clear();
        }
        temp2.push_back(temp_string[i]);
    }

    expressions.push_back(temp2);
}


int main()
{
    std::cout << derivative("x^2+x") << std::endl;
}




