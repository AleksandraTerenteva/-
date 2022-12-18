#include <stdio.h>
#include <iostream>

class Complex {
public:
    double r, i;
};

class Matrix {
public:
    Matrix(double m00, double m01, double m10, double m11);
    double m[2][2];
};

class Real {
public:
    double r;
};


template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

template <class T>
double absz(T o) {
    return sgn(o.r) * o.r;
}

template <>
double absz<Matrix>(Matrix o);

template <>
double absz<Complex>(Complex o);

void test();
