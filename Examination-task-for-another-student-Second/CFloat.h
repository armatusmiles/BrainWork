#include <iostream>
using namespace std;
class CFloat 
{
    friend ostream& operator<< (ostream &os, const CFloat &obj)
    {
        os << obj._value;
        return os;
    }
public:
    explicit CFloat(): _value(0) {}
    explicit CFloat(float value): _value(value) {}
    CFloat(const CFloat& obj): _value(obj._value) {}
    ~CFloat() {}
    CFloat operator* (const CFloat& right) const 
    {
        CFloat res(_value * right._value);
        return res;
    }
    CFloat operator/ (const CFloat& right) const 
    {
        CFloat res(_value / right._value);
        return res;
    }
    CFloat operator+ (const CFloat& right) const
    {
        CFloat res(_value + right._value);
        return res;
    }
    CFloat operator- (const CFloat& right) const
    {
        CFloat res(_value - right._value);
        return res;
    }    
    CFloat& operator= (const CFloat& right)
    {
        this->_value = right._value;
		return *this;
    }
    bool operator== (const CFloat& right) const
    {
        return _value == right._value;
    }
    bool operator!= (const CFloat& right) const
    {
        return _value != right._value;
    }
    bool operator> (const CFloat& right) const
    {
        return _value > right._value;
    }
    bool operator< (const CFloat& right) const
    {
        return _value < right._value;
    }
    bool operator>= (const CFloat& right) const
    {
        return _value >= right._value;
    }
    bool operator<= (const CFloat& right) const
    {
        return _value <= right._value;
    }
private:
    float _value;
};
