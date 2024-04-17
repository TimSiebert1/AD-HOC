#ifndef ADHOC3_TUPLE_UTILS_HPP
#define ADHOC3_TUPLE_UTILS_HPP

#include "utils.hpp"

#include <iostream>
#include <tuple>
#include <type_traits>

namespace adhoc3 {

namespace detail {

template <std::size_t IdxToReplace, class Replacement, class... TupleValues,
          std::size_t... IndicesStart, std::size_t... IndicesEnd>
auto constexpr replace_first_aux2(
    std::tuple<TupleValues...> /* in */,
    std::index_sequence<IndicesStart...> /* idx1 */,
    std::index_sequence<IndicesEnd...> /* idx2 */) {
    return std::make_tuple(
        std::tuple_element_t<IndicesStart, std::tuple<TupleValues...>>{}...,
        Replacement{},
        std::tuple_element_t<IndicesEnd + IdxToReplace + 1,
                             std::tuple<TupleValues...>>{}...);
}

template <std::size_t IdxToReplace, class Replacement, class... TupleValues,
          class IndicesStart = std::make_index_sequence<IdxToReplace>,
          class IndicesEnd = std::make_index_sequence<sizeof...(TupleValues) -
                                                      IdxToReplace - 1>>
auto constexpr replace_first_aux(std::tuple<TupleValues...> /* in */) {
    return replace_first_aux2<IdxToReplace, Replacement>(
        std::tuple<TupleValues...>{}, IndicesStart{}, IndicesEnd{});
}

} // namespace detail

template <class Type, class... TupleValues>
auto constexpr get_idx_first(std::tuple<TupleValues...> /* in */) {
    static_assert(has_type<Type, TupleValues...>(),
                  "type to replace not on this tuple");
    return detail::get_index<Type, TupleValues...>::value;
}

template <class TypeToReplace, class Replacement, class... TupleValues>
auto constexpr replace_first(std::tuple<TupleValues...> /* in */) {
    static_assert(has_type<TypeToReplace, TupleValues...>(),
                  "type to replace not on this tuple");
    constexpr auto idx =
        detail::get_index<TypeToReplace, TupleValues...>::value;
    return detail::replace_first_aux<idx, Replacement>(
        std::tuple<TupleValues...>{});
}

template <typename T, size_t N> class generate_tuple_type {
    template <typename = std::make_index_sequence<N>> struct impl;

    template <size_t... Is> struct impl<std::index_sequence<Is...>> {
        template <size_t> using wrap = T;

        using type = std::tuple<wrap<Is>...>;
    };

  public:
    using type = typename impl<>::type;
};

template <class Type, class... TupleValues>
auto constexpr get_idx_first2(std::tuple<TupleValues...> /* in */) {
    if constexpr (has_type<Type, TupleValues...>()) {
        return detail::get_index<Type, TupleValues...>::value;
    } else {
        // if the type is not found we go beyond the end
        return sizeof...(TupleValues);
    }
}

template <std::size_t IdxToReplace, class Replacement, class... TupleValues>
auto constexpr replace_first2(std::tuple<TupleValues...> /* in */) {
    if constexpr (IdxToReplace >= sizeof...(TupleValues)) {
        return std::tuple<TupleValues...>{};
    } else {
        return detail::replace_first_aux<IdxToReplace, Replacement>(
            std::tuple<TupleValues...>{});
    }
}

template <typename T, typename Tuple> struct has_type_tuple;

template <typename T, typename... Us>
struct has_type_tuple<T, std::tuple<Us...>>
    : std::disjunction<std::is_same<T, Us>...> {};

template <typename T, typename Tuple>
constexpr bool has_type_tuple_v = has_type_tuple<T, Tuple>::value;

template <typename T, typename... Us>
constexpr auto contains(std::tuple<Us...> /* tuple */, T /* value */) -> bool {
    return std::disjunction<std::is_same<T, Us>...>::value;
}

namespace detail {

template <class ThisVal, class RemoveVal>
constexpr auto remove_aux(ThisVal val, RemoveVal /* rem */) {

    if constexpr (std::is_same_v<ThisVal, RemoveVal>) {
        return std::tuple<>{};
    } else {
        return std::make_tuple(val);
    }
}

} // namespace detail

template <typename T, typename... Us>
constexpr auto remove(std::tuple<Us...> tuple, T value) {
    return std::apply(
        [value](auto... val) {
            return std::tuple_cat(detail::remove_aux(val, value)...);
        },
        tuple);
}

template <typename First, typename... Rest>
constexpr auto head(std::tuple<First, Rest...> /* tuple */) {
    return First{};
}

template <typename First, typename... Rest>
constexpr auto tail(std::tuple<First, Rest...> /* tuple */) {
    return std::tuple<Rest...>{};
}

namespace detail {

template <std::size_t N, class UnfilteredTuple, class CalculateFlags,
          class Output>
constexpr auto filter_aux(UnfilteredTuple in, CalculateFlags calc_flags,
                          Output out) {
    if constexpr (N == std::tuple_size_v<UnfilteredTuple>) {
        return out;
    } else {
        if constexpr (std::get<N>(calc_flags)) {
            return filter_aux<N + 1>(
                in, calc_flags,
                std::tuple_cat(out, std::make_tuple(std::get<N>(in))));

        } else {
            return filter_aux<N + 1>(in, calc_flags, out);
        }
    }
}

} // namespace detail

template <class UnfilteredTuple, class CalculateFlags>
constexpr auto filter(UnfilteredTuple in, CalculateFlags calc_flags) {
    return detail::filter_aux<0>(in, calc_flags, std::tuple<>{});
}

template <std::size_t Idx, std::size_t... I>
constexpr auto get(std::index_sequence<I...>) {
    return std::array<std::size_t, sizeof...(I)>{I...}[Idx];
}

template <std::size_t N, class IntegerSequences, class Output>
constexpr auto precedent_required_aux(IntegerSequences integer_sequences,
                                      Output out) {
    if constexpr (N == std::get<0>(integer_sequences).size()) {
        return out;
    } else {
        constexpr auto result_filtered = std::apply(
            [](auto... sequence) { return ((get<N>(sequence) + ...) != 0); },
            integer_sequences);

        using this_result_type =
            std::conditional<result_filtered, std::true_type,
                             std::false_type>::type;

        return precedent_required_aux<N + 1>(
            integer_sequences,
            std::tuple_cat(out, std::make_tuple(this_result_type{})));
    }
}

template <class IntegerSequences>
constexpr auto precedent_required(IntegerSequences integer_sequences) {
    return precedent_required_aux<0>(integer_sequences, std::tuple<>{});
}

} // namespace adhoc3

#endif // ADHOC3_TUPLE_UTILS_HPP
