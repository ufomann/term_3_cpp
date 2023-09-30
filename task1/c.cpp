#include <iostream>

template <typename T>
T min(T a, T b){
    return a < b ? a : b;
}

template <typename T>
T max(T a, T b){
    return a > b ? a : b;
}

template <typename T>
T less(T a, T b){
    return a < b;
}

template <typename T>
T greater(T a, T b){
    return a > b;
}

int main(){
    int a = 1, b = 2;
    std::cout << min(a, b) << ' ' << max(a, b) << ' ' << greater(a, b) << ' ' << less(a, b) << '\n';
}