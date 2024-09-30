#include <print>

#include "rc/array.hpp"

int main()
{
    rc::array<double, 10> a;
    a.fill(0.0);

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
