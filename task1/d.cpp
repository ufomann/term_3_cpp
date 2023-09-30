#include <iostream>

template<typename T, typename U>
T bitCast(U value){
    T ans = *(reinterpret_cast<T*>(&value));
    return ans;
}

int main(){
    int32_t a = 256;
    std::cout << (int) bitCast<char, int32_t>(a) << '\n';
    return 0;
}