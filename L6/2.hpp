#include "0.hpp"

template<unsigned alpha, unsigned beta>
struct monomial2d {
    static const unsigned value =
        factorial<alpha+beta+2>::value
        / factorial<alpha>::value / factorial<beta>::value;
};

void funct2();
