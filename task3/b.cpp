#include <string>
#include <iostream>
#include <algorithm>

struct Unit  
{
    explicit Unit(size_t id) 
        : id_(id) 
    {}

    size_t id() const { return id_; }

private:
    size_t id_;
};

// базовый класс для животных
struct Animal : virtual public Unit
{
    // name хранит название животного
    // "bear" для медведя
    // "pig" для свиньи
    Animal(std::string const & name, size_t id) : Unit(id), name_(name) { }
    // ...

    std::string const& name() const { return name_; }
private:
    std::string name_;
};

// класс для человека
struct Man : virtual public Unit
{
    explicit Man(size_t id) : Unit(id) { }
};

// класс для медведя
struct Bear : public Animal
{
    explicit Bear(size_t id) : Animal("bear", id), Unit(id) { }
};

// класс для свиньи
struct Pig : public Animal
{
    explicit Pig(size_t id) : Animal("pig", id), Unit(id) { }
};

// класс для челмедведосвина
struct ManBearPig : public Pig, public Bear, public Man
{
    ManBearPig(size_t id) : Man(id), Bear(id), Pig(id), Unit(id) { }
};

int main(){
    ManBearPig a(8);
    std::cout << a.id();
}
/*
bad solution

// базовый класс для животных
struct Animal : public Unit
{
    // name хранит название животного
    // "bear" для медведя
    // "pig" для свиньи
    Animal(std::string const & name, size_t id) : Unit(id), name_(name) { }
    // ...

    std::string const& name() const { return name_; }
private:
    std::string name_;
};

// класс для человека
struct Man : public Unit
{
    explicit Man(size_t id) : Unit(id) { }
    size_t id() const { return Unit::id(); }
};

// класс для медведя
struct Bear : public Animal
{
    explicit Bear(size_t id) : Animal("bear", id) { }
    size_t id() const { return Unit::id(); }
};

// класс для свиньи
struct Pig : public Animal
{
    explicit Pig(size_t id) : Animal("pig", id) { }
    size_t id() const { return Unit::id(); }
};

// класс для челмедведосвина
struct ManBearPig : public Pig, public Bear, public Man
{
    ManBearPig(size_t id) : Man(id), Bear(id), Pig(id) { }
    size_t id() const { return Man::id(); }
};
*/