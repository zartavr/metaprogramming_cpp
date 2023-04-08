#include <utility>

template <class T>
struct is_array_of_arrays
{
    static const bool value = false;
};

template <class T, std::size_t N>
struct is_array_of_arrays<T[][N]>
{
    static const bool value = true;
};

template <class T, std::size_t M, std::size_t N>
struct is_array_of_arrays<T[M][N]>
{
    static const bool value = true;
};

int main()
{
    static_assert(is_array_of_arrays<int[][5]>::value == true);
    static_assert(is_array_of_arrays<int[4][5]>::value == true);
    static_assert(is_array_of_arrays<float[][19]>::value == true);
    static_assert(is_array_of_arrays<float[][3]>::value == true);
    static_assert(is_array_of_arrays<int[]>::value == false);
    static_assert(is_array_of_arrays<int[5]>::value == false);
    static_assert(is_array_of_arrays<int **>::value == false);

    return 0;
}