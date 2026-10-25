#include <iostream>

template<class T>
struct IsPointer
{
    static constexpr bool value{false};
};

template<class T>
struct IsPointer<T *> 
{
    static constexpr bool value{true};
};

template<class T>
constexpr bool IsPointerV{IsPointer<T>::value};

template<bool B, class T>
struct EnableIf
{
};

template<class T>
struct EnableIf<true, T>
{
    using type = T;
};

template<bool B, class T>
using EnableIfT = EnableIf<B, T>::type;

template<class T>
using EnableIfPointerT = EnableIfT<IsPointerV<T>, T>;

int main()
{
    int number_1{57};
    EnableIfPointerT<int *> number_2{&number_1}; // <1>
    std::cout << number_2 << "\n";
}