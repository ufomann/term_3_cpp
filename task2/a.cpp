#include <iostream>
#include <string>

struct Character
{
    std::string const & name() const;
    unsigned health() const;
};

struct LongRange
{
    std::string const & name() const;
    unsigned health() const;

    unsigned range() const;
};

struct SwordsMan
{
    std::string const & name() const;
    unsigned health() const;

    unsigned strength() const;    
};

struct Wizard
{
    std::string const & name() const;
    unsigned health() const;

    unsigned range() const;

    unsigned mana() const;
};

struct Archer
{
    std::string const & name() const;
    unsigned health() const;

    unsigned range() const;

    unsigned accuracy() const;
};

struct LongRange : virtual Character {};