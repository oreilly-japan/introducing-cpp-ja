template<bool B, class T>
struct AddPointerIf
{
    using type = T;
};

template<class T>
struct AddPointerIf<true, T>
{
    using type = T *;
};

template<bool B, class T>
using AddPointerIfT = AddPointerIf<B, T>::type;

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

template<class T, class U>
constexpr bool IsSameV{IsSame<T, U>::value};

static_assert(IsSameV<AddPointerIfT<false, int>, int> == true); // ❶
static_assert(IsSameV<AddPointerIfT<true, int>, int *> == true); // ❷
static_assert(IsSameV<AddPointerIfT<false, double>, int> == false); // ❸
static_assert(IsSameV<AddPointerIfT<true, double>, double> == false); // ❹

int main()
{
}