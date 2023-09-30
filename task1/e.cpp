#include <iostream>

template <typename T, typename U>
void copy_n(T*target, U*data, size_t count){
    for (size_t i = 0; i < count; i++){
        *(target + i) = static_cast<T>(*(data + i));
    }
}

template<typename T, size_t arr_size>
void print_array(T* arr){
    for (size_t i = 0; i < arr_size; i++){
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

int main(){
    int ints[] = {1, 2, 3, 4};
    double doubles[4] = {};
    copy_n(doubles, ints, 4); 
    print_array<double, 4>(doubles);
    return 0;
}