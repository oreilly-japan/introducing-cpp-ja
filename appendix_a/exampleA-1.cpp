#include <iostream>
#include <array>

template<size_t N> // <1>
struct IntArray // <1>
{
    std::array<int, N> array{}; // <2>
};

int main()
{
    IntArray<3u> integers{}; // <3>
    for(auto i : integers.array)
    {
        std::cout << i << "\n";
    }
}