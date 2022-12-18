template<unsigned N>
class fibonacci {
public:
    static const unsigned val = fibonacci<N-1>::val + fibonacci<N-2>::val;
};

template<>
class fibonacci<0> {
public:
    static const unsigned val=0;
};

template<>
class fibonacci<1> {
public:
    static const unsigned val=1;
};

void func1();
