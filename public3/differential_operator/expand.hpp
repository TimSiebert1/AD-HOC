#ifndef ADHOC3_DIFFERENTIAL_OPERATOR_EXPAND_HPP
#define ADHOC3_DIFFERENTIAL_OPERATOR_EXPAND_HPP

#include "../adhoc.hpp"
#include "../constants_type.hpp"
#include "../dependency.hpp"
#include "differential_operator.hpp"
#include "integer_partition_univariate_function.hpp"
#include "is_ordered.hpp"
#include "merge_ordered.hpp"
#include "ordered_mult.hpp"
#include "select_root_derivatives.hpp"

namespace adhoc3 {

namespace detail {

template <typename T> struct is_constant_class : std::false_type {};

template <constants::ArgType N>
struct is_constant_class<constants::CD<N>> : std::true_type {};

template <class T>
constexpr bool is_constant_class_v = is_constant_class<T>::value;

template <class Arg1, class Arg2>
constexpr auto expand_single(Arg1 arg1, Arg2 arg2);

template <class Nodes>
constexpr auto expand_single(Nodes /* nodes */, std::tuple<> /* id */) {
    return std::tuple<std::tuple<>>{};
}

template <class Nodes, std::size_t N, class... Ids, std::size_t Order,
          std::size_t... Orders, std::size_t Power, std::size_t... Powers>
constexpr auto
expand_single(Nodes /* nodes */,
              std::tuple<der2::p<Power, der2::d<Order, double_t<N>>>,
                         der2::p<Powers, der2::d<Orders, Ids>>...> /* id */) {
    return std::tuple<std::tuple<der2::p<Power, der2::d<Order, double_t<N>>>,
                                 der2::p<Powers, der2::d<Orders, Ids>>...>>{};
}

template <std::size_t Order, class Id1, class Id2, class Nodes>
constexpr auto ordered_operators_sum(Nodes nodes) {
    constexpr auto id1_less_than_id2 = static_cast<bool>(
        get_idx_first2<Id1>(nodes) >= get_idx_first2<Id2>(nodes));
    if constexpr (id1_less_than_id2) {
        return std::tuple<der2::p<1, der2::d<Order, Id2>>,
                          der2::p<1, der2::d<Order, Id1>>>{};
    } else {
        return std::tuple<der2::p<1, der2::d<Order, Id1>>,
                          der2::p<1, der2::d<Order, Id2>>>{};
    }
}

template <class Nodes, class Id1, class Id2, class... Ids, std::size_t Order,
          std::size_t... Orders, std::size_t Power, std::size_t... Powers>
constexpr auto
expand_single(Nodes nodes,
              std::tuple<der2::p<Power, der2::d<Order, add_t<Id1, Id2>>>,
                         der2::p<Powers, der2::d<Orders, Ids>>...> /* id */) {
    if constexpr (is_constant_class_v<Id1>) {
        return expand_single(
            nodes, std::tuple<der2::p<Power, der2::d<Order, Id2>>,
                              der2::p<Powers, der2::d<Orders, Ids>>...>{});
    } else if constexpr (is_constant_class_v<Id2>) {
        return expand_single(
            nodes, std::tuple<der2::p<Power, der2::d<Order, Id1>>,
                              der2::p<Powers, der2::d<Orders, Ids>>...>{});
    } else {
        constexpr auto ordered_ids =
            ordered_operators_sum<Order, Id1, Id2>(nodes);
        // result is (ordered_ids[0] + ordered_ids[1])^Power

        // ERROR! need to expand binomial (d(Id1) + d(Id2)) ^ Power
        auto constexpr ordered_differential_operator_1 = multiply_ordered(
            nodes, std::tuple<der2::p<Power, der2::d<Order, Id1>>>{},
            std::tuple<der2::p<Powers, der2::d<Orders, Ids>>...>{});

        auto constexpr expanded_differential_operator_1 =
            expand_single(nodes, ordered_differential_operator_1);

        auto constexpr ordered_differential_operator_2 = multiply_ordered(
            nodes, std::tuple<der2::p<Power, der2::d<Order, Id2>>>{},
            std::tuple<der2::p<Powers, der2::d<Orders, Ids>>...>{});

        auto constexpr expanded_differential_operator_2 =
            expand_single(nodes, ordered_differential_operator_2);

        return merge_ordered(nodes, expanded_differential_operator_1,
                             expanded_differential_operator_2);
    }
}

template <class Nodes, class Id1, class Id2, class... Ids, std::size_t Order,
          std::size_t... Orders, std::size_t Power, std::size_t... Powers>
constexpr auto
expand_single(Nodes nodes,
              std::tuple<der2::p<Power, der2::d<Order, sub_t<Id1, Id2>>>,
                         der2::p<Powers, der2::d<Orders, Ids>>...> /* id */) {
    // substraction and addition have the same expansion
    return expand_single(
        nodes, std::tuple<der2::p<Power, der2::d<Order, add_t<Id1, Id2>>>,
                          der2::p<Powers, der2::d<Orders, Ids>>...>{});
}

template <class Nodes, template <class> class Univariate, class Id,
          class... Ids, std::size_t Order, std::size_t... Orders,
          std::size_t Power, std::size_t... Powers>
constexpr auto
expand_single(Nodes /* nodes */,
              std::tuple<der2::p<Power, der2::d<Order, Univariate<Id>>>,
                         der2::p<Powers, der2::d<Orders, Ids>>...> /* id */) {
    constexpr auto expansion =
        integer_partition_univariate_function<Id, Order>();
}

template <std::size_t Order, class IdFirst, class IdSecond, std::size_t... I>
constexpr auto generate_operators_mul2(std::index_sequence<I...> /* i */) {
    return std::make_tuple(
        std::tuple<der2::p<1, der2::d<Order, IdFirst>>>{},
        std::tuple<der2::p<1, der2::d<Order - I - 1, IdFirst>>,
                   der2::p<1, der2::d<I + 1, IdSecond>>>{}...,
        std::tuple<der2::p<1, der2::d<Order, IdSecond>>>{});
}

template <std::size_t Order, class Id1, class Id2, class Nodes>
constexpr auto ordered_operators_mul(Nodes nodes) {

    constexpr auto seq = std::make_integer_sequence<std::size_t, Order - 1>{};

    constexpr auto id1_less_than_id2 = static_cast<bool>(
        get_idx_first2<Id1>(nodes) >= get_idx_first2<Id2>(nodes));
    if constexpr (id1_less_than_id2) {
        return generate_operators_mul2<Order, Id2, Id1>(seq);
    } else {
        return generate_operators_mul2<Order, Id1, Id2>(seq);
    }
}

template <class Nodes, class Id1, class Id2, class... Ids, std::size_t Order,
          std::size_t... Orders, std::size_t Power, std::size_t... Powers>
constexpr auto
expand_single(Nodes nodes,
              std::tuple<der2::p<Power, der2::d<Order, mul_t<Id1, Id2>>>,
                         der2::p<Powers, der2::d<Orders, Ids>>...> /* id */) {
    if constexpr (is_constant_class_v<Id1>) {
        return expand_single(
            nodes, std::tuple<der2::p<Power, der2::d<Order, Id2>>,
                              der2::p<Powers, der2::d<Orders, Ids>>...>{});
    } else if constexpr (is_constant_class_v<Id2>) {
        return expand_single(
            nodes, std::tuple<der2::p<Power, der2::d<Order, Id1>>,
                              der2::p<Powers, der2::d<Orders, Ids>>...>{});
    } else {
        constexpr auto ordered_ids =
            ordered_operators_mul<Order, Id1, Id2>(nodes);
        // ordered_ids contains tuple(d^Order-I(Id1)*d^I(Id2))

        return std::tuple<>{};
    }
}

} // namespace detail

template <class Nodes, class... Ids>
constexpr auto expand(Nodes nodes, std::tuple<Ids...> in1);

template <class Nodes>
constexpr auto expand(Nodes /* nodes */, std::tuple<> /* in1 */) {
    return std::tuple<>{};
}

template <class Nodes, class Id, class... Ids>
constexpr auto expand(Nodes nodes, std::tuple<Id, Ids...> in) {
    static_assert(is_ordered(nodes, in));
    return merge_ordered(nodes, detail::expand_single(nodes, Id{}),
                         expand(nodes, std::tuple<Ids...>{}));
}

} // namespace adhoc3

#endif // ADHOC3_DIFFERENTIAL_OPERATOR_EXPAND_HPP
