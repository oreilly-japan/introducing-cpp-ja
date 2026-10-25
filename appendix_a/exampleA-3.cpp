template<class T, class U>
struct IsSame
{
    static constexpr bool value{false};
};

template<class T>
struct IsSame<T, T>
{
    static constexpr bool value{true};
};

static_assert(IsSame<int, int>::value == true); // ❶
static_assert(IsSame<double, double>::value == true); // ❷
static_assert(IsSame<int, double>::value == false); // ❸
static_assert(IsSame<int, int *>::value == false); // ❹

int main()
{
}