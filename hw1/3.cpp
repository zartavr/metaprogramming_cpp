#include <utility>

template<class T, std::size_t N>
struct remove_pointers {
	using type = T;
};

template<class T, std::size_t N>
struct remove_pointers<T*, N> {
	using type = typename remove_pointers<T, N-1>::type;
};

template<class T>
struct remove_pointers<T*, 0>{
	using type = T*;
};

int main()
{
    static_assert(std::is_same<remove_pointers<bool***, 2>::type, bool*>::value);
    static_assert(std::is_same<remove_pointers<bool*, 100500>::type, bool>::value);
    static_assert(std::is_same<remove_pointers<bool***, 0>::type, bool***>::value);
    static_assert(std::is_same<remove_pointers<bool****, 4>::type, bool>::value);

    return 0;
}