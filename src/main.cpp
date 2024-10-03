#include <algorithm>
#include <print>

#include "rc/array.hpp"
#include "rc/array_dynamic.hpp"
#include "rc/vector.hpp"

int main()
{
    rc::array<double, 10> a;
    rc::array_dynamic<double> da(10, 0.999);
    rc::vector<double> v(10, 0.999);

    std::fill(a.begin(), a.end(), 0.999);
    a[0] = 100.001;
    a[2] = 800.003;
    a[5] = 500.002;
    a[8] = 300.004;

    da[0] = 10.1;
    da[2] = 80.3;
    da[5] = 50.2;
    da[8] = 30.4;

    v[0] = 1.1;
    v[2] = 8.3;
    v[5] = 5.2;
    v[8] = 3.4;

    auto print = [](auto &a)
    {
        std::print("{} els: [{}", a.size(), a[0]);
        std::for_each(a.begin() + 1, a.end(), [](auto &x)
                      { std::print(", {}", x); });
        std::println("]");
    };

    std::println("Array a:");
    print(a);
    std::sort(a.begin(), a.end());
    print(a);

    std::println("\nArray da:");
    print(da);
    std::sort(da.begin(), da.end());
    print(da);

    v.push_back(4.5);
    std::println("\nVector v [cap = {}]:", v.capacity());
    print(v);
    std::sort(v.begin(), v.end());
    print(v);

    return 0;
}
