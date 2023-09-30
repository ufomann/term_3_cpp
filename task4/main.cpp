#include <iostream>
#include "Array_v2.h"

struct Str{
    Str() = delete;
    Str(int t) : t(t) { };
    Str(const Str&) = default;
    Str& operator=(const Str&) = delete;
    int get_int(){
        return t;
    }
    private:
        int t = 0;
};

int main(){
    Array<Str> arr(5, 5);
    for (int i = 0; i < 5; i++){
        std::cout << arr[i].get_int() << " \n"[i == 4];
    }
    Array<Str> arr2(arr);
    for (int i = 0; i < 5; i++){
        std::cout << arr2[i].get_int() << " \n"[i==4];
    }
    Array<Str> arr3(std::move(arr));
    for (int i = 0; i < 5; i++){
        std::cout << arr3[i].get_int() << " \n"[i==4];
    }
    return 0;
}