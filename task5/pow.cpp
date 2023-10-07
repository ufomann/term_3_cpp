#include <iostream>

template <unsigned B, unsigned P>
struct pow {
    static const unsigned value = B * pow<B, P - 1>::value;
};

template<unsigned B>
struct pow<B, 0> {
    static const unsigned value = 1;
};

int main(){
    std::cout << pow<6, 2>::value << '\n';
}