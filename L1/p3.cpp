#include "p3.hpp"

void z3::test1() {
    Qeq<double> d(0, 0, 1);
    d.solve();
    cout << endl;
}
void z3::test2() {
    Qeq<double> d(1, 1, 0);
    d.solve();
    cout << endl;
}

void z3::test3() {
    Qeq<double> d(1, 0, 3);
    d.solve();
    cout << endl;
}

void z3::test4() {
    Qeq<double> d(1, 1, 1);
    d.solve();
    cout << endl;
}

void z3::test5() {
    Qeq<double> d(-3, 7, -9);
    d.solve();
    cout << endl;
}

void f3() {
    using namespace z3;

    test1();
    test2();
    test3();
    test4();
    test5();
}
