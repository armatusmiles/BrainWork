#ifndef IntH
#define IntH

#include "Number.h"

class Int: public Number {
private:
    int value;
public:
    Int(int _value = 0): value(_value) {}
    virtual void FromString(const char *s) { value = atoi(s); }
    virtual void ToString(char* s) const { sprintf(s, "%d", value); }
    virtual Int *Copy() const { return new Int(this->value); }
    virtual Number &operator+ (const Number &n) const {
        const Int *right = dynamic_cast<const Int*>(&n);
        if ( right != 0 ) return *(new Int(value + right->value));
        else {
            char s[20]; n.ToString(s);
            Int right; right.FromString(s);
            return *(new Int(value + right.value));
        }
    }
    virtual Number &operator- (const Number &n) const {
        const Int *right = dynamic_cast<const Int*>(&n);
        if ( right != 0 ) return *(new Int(value - right->value));
        else {
            char s[20]; n.ToString(s);
            Int right; right.FromString(s);
            return *(new Int(value - right.value));
        }
    }
    virtual Number &operator* (const Number &n) const {
        const Int *right = dynamic_cast<const Int*>(&n);
        if ( right != 0 ) return *(new Int(value * right->value));
        else {
            char s[20]; n.ToString(s);
            Int right; right.FromString(s);
            return *(new Int(value * right.value));
        }
    }
    virtual Number &operator/ (const Number &n) const {
        const Int *right = dynamic_cast<const Int*>(&n);
        if ( right != 0 ) return *(new Int(value / right->value));
        else {
            char s[20]; n.ToString(s);
            Int right; right.FromString(s);
            return *(new Int(value / right.value));
        }
    }
    virtual bool operator== (const Number &n) const {
        const Int *right = dynamic_cast<const Int*>(&n);
        if ( right != 0 ) return (value == right->value); else return false;
    }
    virtual bool operator!= (const Number &n) const {
        const Int *right = dynamic_cast<const Int*>(&n);
        if ( right != 0 ) return (value != right->value); else return false;
    }
    virtual bool operator>= (const Number &n) const {
        const Int *right = dynamic_cast<const Int*>(&n);
        if ( right != 0 ) return (value >= right->value); else return false;
    }
    virtual bool operator<= (const Number &n) const {
        const Int *right = dynamic_cast<const Int*>(&n);
        if ( right != 0 ) return (value <= right->value); else return false;
    }
    virtual bool operator> (const Number &n) const {
        const Int *right = dynamic_cast<const Int*>(&n);
        if ( right != 0 ) return (value > right->value); else return false;
    }
    virtual bool operator< (const Number &n) const {
        const Int *right = dynamic_cast<const Int*>(&n);
        if ( right != 0 ) return (value < right->value); else return false;
    }
};

#endif
