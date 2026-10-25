#include <iostream>
#include <type_traits>

template<class T>
concept Arithmetic = std::is_arithmetic_v<T>;

void display(Arithmetic auto value)
{
    std::cout << value << "\n";
}

class NoOp
{

};

int main()
{
    display(NoOp{});
}