/*
 * AD-HOC, Automatic Differentiation for High Order Calculations
 *
 * This file is part of the AD-HOC distribution
 * (https://github.com/juanlucasrey/AD-HOC).
 * Copyright (c) 2024 Juan Lucas Rey
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ADHOC4_ADD_SAT_HPP
#define ADHOC4_ADD_SAT_HPP

#include <cstddef>
#include <limits>
#include <type_traits>

namespace adhoc4::detail {

// constexpr version of saturation arithmetic
// https://en.cppreference.com/w/cpp/numeric/add_sat
// while we wait for C++26

template <typename T, typename... Types>
concept is_all_same = (... && std::is_same<T, Types>::value);

constexpr auto add_sat(std::size_t lhs) { return lhs; }

template <is_all_same<std::size_t>... Types>
constexpr auto add_sat(std::size_t lhs, Types... args) {
    auto const rhs = add_sat(args...);

    if (std::numeric_limits<std::size_t>::max() - lhs < rhs) {
        return std::numeric_limits<std::size_t>::max();
    }

    if (std::numeric_limits<std::size_t>::max() - rhs < lhs) {
        return std::numeric_limits<std::size_t>::max();
    }

    return lhs + rhs;
}

} // namespace adhoc4::detail

#endif // ADHOC4_ADD_SAT_HPP
