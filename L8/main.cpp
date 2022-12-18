#include "1.hpp"
#include<iostream>
int main() {
    const unsigned N = 2;
    const double a = 3.0, b = 4.5;
    const double bi = binom<N>(a, b); // вычисление интеграла 
    std::cout << bi << '\n';
    return(0);
}
