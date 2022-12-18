#include "0.hpp"
#include <numeric>
const unsigned f5 = factorial<5>::value;
const unsigned b52 = C<5, 2>::value;
const unsigned int111 = monomial_3d<1, 1, 1>::value;
void lec() {
    using std::cout;
    using std::endl;
    int arr[f5];
    cout << f5 << endl;
    int arr1[b52];
    cout << b52 << endl;
    int arr2[int111];
    cout << int111 << endl;
    double a[3] = { 1.23, 2.34, 3.45 };
    double sum = std::accumulate(a, a + 3, 0);
    cout << sum << endl;
    sum = std::accumulate(a, a + 3, 0.);
    cout << sum << endl;
}
