
using namespace std;

template<unsigned N> struct factorial {
    static const unsigned value = N * factorial<N - 1>::value;
};
template<> struct factorial<0> {
    static const unsigned value = 1;
};

template<unsigned N, unsigned K> struct C {
    static const unsigned value =
        factorial<N>::value / factorial<K>::value / factorial<N - K>::value;
};

template<typename T>
struct enable_if<false, T> {};

template<int N, typename T>
typename std::enable_if<(N < 0), T>::type meta_pow(T x) {
    return (1 / meta_pow<-N>(x));
}
template<int N, typename T>
typename std::enable_if<(N == 0), T>::type meta_pow(T x) {
    return (1);
}
template<int N, typename T>
typename std::enable_if<(N == 1), T>::type meta_pow(T x) {
    return (x);
}
template<int N, typename T>
typename std::enable_if<(N > 0) && (N % 2 == 0), T>::type meta_pow(T x) {
    T p = meta_pow<N / 2>(x);
    return (p * p);
}
template<int N, typename T>
typename std::enable_if<(N > 0) && (N % 2 == 1) && (N != 1), T>::type meta_pow(T x) {
    return (meta_pow<N - 1>(x) * x);
}

template<unsigned alpha, unsigned beta>
struct monomial2d {
    static const unsigned value =
        factorial<alpha + beta + 2>::value
        / factorial<alpha>::value / factorial<beta>::value;
};


template<unsigned N, unsigned K, typename T, class action_class, typename A>
typename enable_if<(K > 0), T>::type abstract_sum(const A& args) {
    return abstract_sum<N, K - 1, T, action_class, A>(args) + action_class::template value<N, K>(args);
}

template<unsigned N, unsigned K, typename T, class action_class, typename A>
typename enable_if<(K == 0), T>::type abstract_sum(const A& args) {
    return action_class::template value<N, K>(args);
}

struct binom_action {
    template<unsigned N, unsigned K, typename T>
    static T value(const std::pair <T, T>& args) {
        return C<N, K>::value * meta_pow<K>(args.first) * meta_pow<N - K>(args.second) / monomial2d<K, N - K>::value;
    }
};

template<unsigned N, typename T>
T binom1(T a, T b) {
    return abstract_sum<N, N, T, binom_action>(std::pair<T, T>(a, b));
}

template<unsigned N, unsigned K, typename T>
typename enable_if<(K > 0), T>::type binom1(T a, T b) {
    return binom1<N, K - 1>::value(a, b) +
        C<N, K>::value * meta_pow<K>(a) * pow<N - K>(b) /
        monomial2d<K, N - K>::value;
}

template<unsigned N, unsigned K, typename T>
typename enable_if<(K == 0), T>::type binom1(T a, T b) {
    return meta_pow<N>(b) / monomial2d<0, N>::value;
}

template<unsigned N, typename T>
T binom(T a, T b) {
    return binom1<N, N>(a, b);
}
