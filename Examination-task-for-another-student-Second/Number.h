#ifndef NumberH
#define NumberH

#include <iostream>

class Number {
friend std::ostream &operator<<(std::ostream &os, const Number &n) { char s[256]; n.ToString(s); os << s; };
friend std::istream &operator>>(std::istream &is, Number &n) { char s[256]; is >> s; n.FromString(s); };
public:
    virtual void FromString(const char*) = 0;
    virtual void ToString(char*) const = 0;
    virtual Number *Copy() const = 0;
    virtual Number &operator+ (const Number&) const = 0;
    virtual Number &operator- (const Number&) const = 0;
    virtual Number &operator* (const Number&) const = 0;
    virtual Number &operator/ (const Number&) const = 0;
    virtual bool operator== (const Number&) const = 0;
    virtual bool operator!= (const Number&) const = 0;
    virtual bool operator<= (const Number&) const = 0;
    virtual bool operator>= (const Number&) const = 0;
    virtual bool operator< (const Number&) const = 0;
    virtual bool operator> (const Number&) const = 0;
};

class Matrix {
friend std::ostream &operator<<(std::ostream&, const Matrix&);
friend std::istream &operator>>(std::istream&, const Matrix&);
private:
    unsigned int rownum;
    unsigned int colnum;
    Number **elem;
public:
    Matrix(unsigned int _rownum = 1, unsigned int _colnum = 1):
        rownum(_rownum), colnum(_colnum), elem(new Number*[_rownum*_colnum]) {}
    ~Matrix() { 
        for ( unsigned int i = 0; i < rownum*colnum; i++ ) delete elem[i];
        delete[] elem; 
    }
    Number *&operator[](unsigned int i) { return elem[i]; }
    Matrix &operator+(const Matrix &m) const {
        if ( rownum == m.rownum && colnum == m.colnum ) {
            Matrix *result = new Matrix(rownum, colnum);
            for ( unsigned int i = 0; i < rownum*colnum; i++ )
                result->elem[i] = &(*elem[i]+*m.elem[i]);
            return *result;
        }
        else throw;
    }
    Matrix &operator*(const Matrix &m) const {
        if ( colnum == m.rownum ) {
            Matrix *result = new Matrix(rownum, m.colnum);
            for ( unsigned int i = 0; i < rownum; i++ )
                for ( unsigned int j = 0; j < m.colnum; j++ ) {
                    result->elem[i*m.colnum+j] = &(*elem[i*colnum] * *m.elem[j]);
                    for ( unsigned int k = 0; k < colnum; k++ ) {
                        Number *product = &(*elem[i*colnum+k] * *m.elem[k*m.colnum+j]);
                        Number *sum = &(*result->elem[i*m.colnum+j] + *product);
                        delete product; delete result->elem[i*m.colnum+j];
                        result->elem[i*m.colnum+j] = sum;
                    }
                }
            return *result;
        }
        else throw;
    }
};

#endif
