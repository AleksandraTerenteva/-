#include "p1.hpp"

using std::cout;
using std::endl;

Matrix::Matrix(double m00, double m01, double m10, double m11) {
    m[0][0] = m00;
    m[0][1] = m01;
    m[1][0] = m10;
    m[1][1] = m11;
};

template <>
double absz<Matrix>(Matrix o) {
    return (o.m[0][0] * o.m[1][1] - o.m[0][1] * o.m[1][0]);
}

template <>
double absz<Complex>(Complex o) {
    return (o.r * o.r + o.i * o.i);
}

void test() {
    Real r = {2};
    Complex c = {3, -9};
    Matrix m(3, 2, 4, 5);
    cout << "Real = " << absz(r) << endl;
    cout << "Complex = " << absz(c) << endl;
    cout << "Matrix = " << absz(m) << endl;
}
