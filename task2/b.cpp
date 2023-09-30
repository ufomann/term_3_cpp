#include "b.h"
#include <iostream>

int main(){
    const Rational a{1, 2};
    print(a);
    Rational b{-2, -4};
    print(b);
    print(-a);
    std::cout << (-a).toDouble() << '\n';
    print(a + 5);
    print(5 + a);
}