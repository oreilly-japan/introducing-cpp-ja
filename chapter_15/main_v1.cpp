#include <iostream>

#include "events.h"

template<typename T> // <1>
class Structure // <1>
{
    T value{}; // <2>
public:
    explicit Structure(T value) // <3>
        : value(value)
    {
    }
    void member_function() const // <4>
    {
        std::cout << value << '\n';
    }
};

template<> // <1>
class Structure<stock_prices::Nothing> // <2>
{
public:
    explicit Structure(stock_prices::Nothing value) // <3>
    {

    }
    void member_function() const // <4>
    {
        std::cout << "Nothing\n";
    }
};

int main()
{
    Structure structure{101};
    structure.member_function();

    Structure nothing_structure{stock_prices::Nothing{}};
    nothing_structure.member_function();
}

