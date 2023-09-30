#include <iostream>
#include <cstdint>

struct Cls {
    public:
    void print(){
        std::cout << m_c << ' ' << m_d << ' ' << m_i << '\n';
    }
    Cls(char c, double d, std::int32_t i)
        : m_c(c)
        , m_d(d)
        , m_i(i)
    {}
private:
    char m_c;
    double m_d;
    std::int32_t m_i;
};

// Эта функция должна предоставить доступ к полю m_c объекта cls.
// Обратите внимание, что возвращается ссылка на char, т.е.
// доступ предоставляется на чтение и запись.
char& get_c(Cls& cls) {
    Cls * cls_ptr = &cls;
    char * target = static_cast<char*>(static_cast<void*>(cls_ptr));
    return *target;
}

// Эта функция должна предоставить доступ к полю m_d объекта cls.
// Обратите внимание, что возвращается ссылка на double, т.е.
// доступ предоставляется на чтение и запись.
double& get_d(Cls& cls) {
    Cls * cls_ptr = &cls;
    char * supp = static_cast<char*>(static_cast<void*>(cls_ptr));
    supp = supp + 8;
    double* target = static_cast<double*>(static_cast<void*>(supp));
    return *target;
}

// Эта функция должна предоставить доступ к полю m_i объекта cls.
// Обратите внимание, что возвращается ссылка на int, т.е.
// доступ предоставляется на чтение и запись.
int& get_i(Cls& cls) {
    Cls * cls_ptr = &cls;
    char * supp = static_cast<char*>(static_cast<void*>(cls_ptr));
    supp = supp + 16;
    std::int32_t* target = static_cast<int32_t*>(static_cast<void*>(supp));
    return *target;
}

int main(){
    Cls a{'a', 2.0, 1};
    a.print();
    get_d(a) = 3.0;
    get_i(a) = 25;
    a.print();
    return 0;
}