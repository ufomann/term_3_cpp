#include <iostream>

struct Foo {
    void say() const { std::cout << "Foo says: " << msg << "\n"; }
protected:
    Foo(const std::string& msg) : msg(msg) { }
private:
    const std::string& msg;
};

struct foo : public Foo{
    foo(const std::string& msg) : Foo(msg){};
};

Foo get_foo(std::string msg){
    foo a{msg};
    return a;
}

void foo_says(const Foo& foo) { foo.say(); }


int main(){
    foo_says(get_foo("aboba"));
    return 0;
}