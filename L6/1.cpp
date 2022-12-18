#include "1.hpp"
#include <iostream>

#define N 20
#if N < 0
#define N 0
#endif

const int f = fibonacci<N>::val;

void func1() {
    using std::cout; using std::endl;
    cout << f << endl;
}
