
void zd();

template<unsigned N>
class fibonacci {
public:
    static const unsigned value = fibonacci<N - 1>::value + fibonacci<N - 2>::value;
};

template<>
class fibonacci<0> {
public:
    static const unsigned value = 0;
};

template<>
class fibonacci<1> {
public:
    static const unsigned value = 1;
};


template<int...I> struct int_vector {};
template<class IntVector, int i> struct push_back;


template<int...I, int i>
struct push_back<int_vector<I...>, i> {
    typedef int_vector<I..., i> type;
};

template<class IntVector, int n> struct at;

template<int i, int...I, int n>
struct at<int_vector<i, I...>, n> :at<int_vector<I...>, n - 1> {};

template<int i, int...I>
struct at<int_vector<i, I...>, 0> :std::integral_constant<int, i> {};

template<unsigned n> struct fib {
    typedef typename push_back<typename fib<n - 1>::type, fibonacci<n - 1>::value>::type type;
};
template<> struct fib<0> {
    typedef int_vector<>type;
};
