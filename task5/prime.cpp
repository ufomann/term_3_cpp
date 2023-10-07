#include <iostream>
template <unsigned G, unsigned C = 2, bool D = true>
struct isntPrime {
    static const bool isnt_prime = isntPrime<G, C + 1, (C + 1) * (C + 1) < G>::isnt_prime || ((G % C)==0);
};

template<unsigned G, unsigned C>
struct isntPrime<G, C, false> {
    static const bool isnt_prime = 0;
};

template <unsigned G>
struct isPrime {
    static const bool is_prime = !isntPrime<G>::isnt_prime;
};

template<>
struct isPrime<1> {
    static const bool is_prime = 0;
};

template<>
struct isPrime<2> {
    static const bool is_prime = 1;
};


int main(){
    std::cout << isPrime<1>::is_prime << '\n';
}