#include <dependency.hpp>
#include <init.hpp>

#include "type_name.hpp"

#include <gtest/gtest.h>

namespace adhoc3 {

TEST(Dependency, First) {
    auto [S, K, v, T] = Init<4>();

    auto var = exp(T);
    static_assert(order<decltype(var), decltype(T)>::call() ==
                  std::numeric_limits<std::size_t>::max());

    auto sumv = K + v;
    static_assert(order<decltype(sumv), decltype(S)>::call() == 0);
    static_assert(order<decltype(sumv), decltype(K)>::call() == 1);
    static_assert(order<decltype(sumv), decltype(v)>::call() == 1);
    static_assert(order<decltype(sumv), decltype(T)>::call() == 0);

    auto mulv = K * v * K;
    static_assert(order<decltype(sumv), decltype(S)>::call() == 0);
    static_assert(order<decltype(mulv), decltype(K)>::call() == 2);
    static_assert(order<decltype(mulv), decltype(v)>::call() == 1);
    static_assert(order<decltype(sumv), decltype(T)>::call() == 0);

    auto mulexpv = K * v * exp(K);
    static_assert(order<decltype(mulexpv), decltype(S)>::call() == 0);
    static_assert(order<decltype(mulexpv), decltype(K)>::call() ==
                  std::numeric_limits<std::size_t>::max());
    static_assert(order<decltype(mulexpv), decltype(v)>::call() == 1);
    static_assert(order<decltype(mulexpv), decltype(T)>::call() == 0);

    auto divv = v / K;
    static_assert(order<decltype(divv), decltype(S)>::call() == 0);
    static_assert(order<decltype(divv), decltype(K)>::call() ==
                  std::numeric_limits<std::size_t>::max());
    static_assert(order<decltype(divv), decltype(v)>::call() == 1);
    static_assert(order<decltype(divv), decltype(T)>::call() == 0);

    using constants::CD;
    using constants::encode;

    auto poly = K * (K + CD<encode(3)>()) + (K + CD<encode(0.5)>()) *
                                                (K + CD<encode(1.5)>()) *
                                                (K + CD<encode(2.5)>());
    static_assert(order<decltype(poly), decltype(K)>::call() == 3);
}

} // namespace adhoc3
