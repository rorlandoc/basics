#include <algorithm>
#include <print>

#include "rc/array.hpp"
#include "rc/array_dynamic.hpp"

int main()
{
    rc::array<double, 10> a;
    rc::array_dynamic<double> da(10, 0.999);

    std::fill(a.begin(), a.end(), 0.999);
    a[0] = 100.001;
    a[2] = 800.003;
    a[5] = 500.002;
    a[8] = 300.004;

    da[0] = 1.1;
    da[2] = 8.3;
    da[5] = 5.2;
    da[8] = 3.4;

    auto print = [](auto &a)
    {
        std::println("{}", a.size());
        std::print("[{}", a[0]);
        for (size_t i = 1; i < a.size(); i++)
        {
            std::print(", {}", a[i]);
        }
        std::println("]");
    };

    std::println("\nArray a:");
    print(a);
    std::sort(a.begin(), a.end());
    print(a);

    std::println("\nArray da:");
    print(da);
    std::sort(da.begin(), da.end());
    print(da);

    return 0;
}
