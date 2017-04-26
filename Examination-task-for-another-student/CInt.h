#include <iostream>
using namespace std;
class CInt 
{
    friend ostream& operator<< (ostream &os, const CInt &obj)
    {
        os << obj._value;
        return os;
    }
public:
    explicit CInt(): _value(0) {}
    explicit CInt(int value): _value(value) {}
    CInt(const CInt& obj): _value(obj._value) {}
    ~CInt() {}
    CInt operator* (const CInt& right) const 
    {
        CInt res(_value * right._value);
        return res;
    }
    CInt operator/ (const CInt& right) const 
    {
        CInt res(_value / right._value);
        return res;
    }
    CInt operator+ (const CInt& right) const
    {
        CInt res(_value + right._value);
        return res;
    }
    CInt operator- (const CInt& right) const
    {
        CInt res(_value - right._value);
        return res;
    }    
    CInt& operator= (const CInt& right)
    {
		this->_value = right._value;
		return *this;
    }
    bool operator== (const CInt& right) const
    {
        return _value == right._value;
    }
    bool operator!= (const CInt& right) const
    {
        return _value != right._value;
    }
    bool operator> (const CInt& right) const
    {
        return _value > right._value;
    }
    bool operator< (const CInt& right) const
    {
        return _value < right._value;
    }
    bool operator>= (const CInt& right) const
    {
        return _value >= right._value;
    }
    bool operator<= (const CInt& right) const
    {
        return _value <= right._value;
    }
private:
    int _value;
};
