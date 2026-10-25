#include <iostream>

template<class T> // <1>
constexpr bool IsBooleanV = IsSameV<T, bool>; // <1>

template<class T> // <2>
constexpr bool IsCharacterV = IsSameV<T, char> || IsSameV<T, unsigned char>; // <2>

template<class T> // <3>
constexpr bool IsIntegralV = IsSameV<T, short> || IsSameV<T, unsigned short> // <3>
                            || IsSameV<T, int> || IsSameV<T, unsigned int> // <3>
                            || IsSameV<T, long> || IsSameV<T, unsigned long> // <3>
                            || IsSameV<T, long long> // <3>
                            || IsSameV<T, unsigned long long>; // <3>

template<class T> // <4>
constexpr bool IsFloatingPointV = IsSameV<T, float> // <4>
                                  || IsSameV<T, double> // <4>
                                  || IsSameV<T, long double>; // <4>

template<class T> // <5>
constexpr bool IsArithmeticV = IsBooleanV<T> || IsCharacterV<T> // <5>
                               || IsIntegralV<T> || IsFloatingPointV<T>; // <5>

template<class T, EnableIfT<IsArithmeticV<T>, std::nullptr_t> = nullptr> // <1>
void display(T value)
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