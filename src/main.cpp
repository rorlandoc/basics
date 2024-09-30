#include <print>

#include "rc/array.hpp"
#include "rc/array_dynamic.hpp"

int main()
{
    rc::array_dynamic<double> a(10, 0.0);
    a[0] = 10.1;
    a[5] = 5.2;

    std::println("{}", a.size());

    std::print("[{}", a[0]);
    for (size_t i = 1; i < a.size(); i++)
    {
        std::print(", {}", a[i]);
    }
    std::println("]");

    return 0;
}
