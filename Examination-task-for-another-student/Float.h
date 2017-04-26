#ifndef FloatH
#define FloatH

#include "Number.h"

class Float: public Number {
private:
    float value;
public:
    Float(float _value = 0): value(_value) {}
    virtual void FromString(const char *s) { value = atof(s); }
    virtual void ToString(char *s) const { sprintf(s, "%f", value); }
    virtual Float *Copy() const { return new Float(this->value); }
    virtual Number &operator+ (const Number &n) const {
        const Float *right = dynamic_cast<const Float*>(&n);
        if ( right != 0 ) return *(new Float(value + right->value));
        else {
            char s[20]; n.ToString(s);
            Float right; right.FromString(s);
            return *(new Float(value + right.value));
        }
    }
    virtual Number &operator- (const Number &n) const {
        const Float *right = dynamic_cast<const Float*>(&n);
        if ( right != 0 ) return *(new Float(value - right->value));
        else {
            char s[20]; n.ToString(s);
            Float right; right.FromString(s);
            return *(new Float(value - right.value));
        }
    }
    virtual Number &operator* (const Number &n) const {
        const Float *right = dynamic_cast<const Float*>(&n);
        if ( right != 0 ) return *(new Float(value * right->value));
        else {
            char s[20]; n.ToString(s);
            Float right; right.FromString(s);
            return *(new Float(value * right.value));
        }
    }
    virtual Number &operator/ (const Number &n) const {
        const Float *right = dynamic_cast<const Float*>(&n);
        if ( right != 0 ) return *(new Float(value / right->value));
        else {
            char s[20]; n.ToString(s);
            Float right; right.FromString(s);
            return *(new Float(value / right.value));
        }
    }
    virtual bool operator== (const Number &n) const {
        const Float *right = dynamic_cast<const Float*>(&n);
        if ( right != 0 ) return (value == right->value); else return false;
    }
    virtual bool operator!= (const Number &n) const {
        const Float *right = dynamic_cast<const Float*>(&n);
        if ( right != 0 ) return (value != right->value); else return false;
    }
    virtual bool operator>= (const Number &n) const {
        const Float *right = dynamic_cast<const Float*>(&n);
        if ( right != 0 ) return (value >= right->value); else return false;
    }
    virtual bool operator<= (const Number &n) const {
        const Float *right = dynamic_cast<const Float*>(&n);
        if ( right != 0 ) return (value <= right->value); else return false;
    }
    virtual bool operator> (const Number &n) const {
        const Float *right = dynamic_cast<const Float*>(&n);
        if ( right != 0 ) return (value > right->value); else return false;
    }
    virtual bool operator< (const Number &n) const {
        const Float *right = dynamic_cast<const Float*>(&n);
        if ( right != 0 ) return (value < right->value); else return false;
    }
};

#endif
