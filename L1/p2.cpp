#include "p2.hpp"


using std::string;
typedef string tst;
typedef double tst2;


void z2::test1() {
    cout << endl << "string" << endl;
    tst s[] = {"ab", "bb", "cb", "db", "eb", "fb"};
    void (*p)(tst s);
    p = show<tst>;
    iter(s, 6, p);
}


void z2::test2() {
    cout << endl << "double" << endl;
    double s[] = {1.1, 1.2, 1.3, 1.4, 1.6, 1.7, 1.8};
    void (*p)(double s);
    p = show<double>;
    iter(s, 8, p);
}


void z2::test3() {
    cout << endl << "int" << endl;
    int s[] = {1, 2, 3, 4, 5, 6, 7};
    void (*p)(int s);
    p = showWtxt<int>;
    iter(s, 7, p);
}

void f2() {
    using namespace z2;
    test1();
    test2();
    test3();
}
