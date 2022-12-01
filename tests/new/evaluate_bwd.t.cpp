#include <new/evaluate_bwd.hpp>
#include <new/evaluate_fwd.hpp>
#include <new/init.hpp>

#include "call_price.hpp"

#include <gtest/gtest.h>

namespace adhoc2 {

TEST(EvaluateBwd, Univariate) {
    auto [v0] = Init<1>();
    // auto r = exp(cos(v0) * (v1 * v1));
    auto r = exp(cos(log(v0)));

    auto leaves_and_roots = TapeRootsAndLeafs(r);
    leaves_and_roots.set(v0, 0.5);

    auto intermediate_tape = evaluate_fwd_return_vals(leaves_and_roots);
    auto tape_d = TapeDerivatives(v0, r);
    tape_d.get(r) = 1.0;

    evaluate_bwd(leaves_and_roots, intermediate_tape, tape_d);
    EXPECT_NEAR(tape_d.get(v0), 2.757914160416556, 1e-13);
}

TEST(EvaluateBwd, Univariate2) {
    auto [v0] = Init<1>();
    // auto r = exp(cos(v0) * (v1 * v1));
    auto r = exp(v0);

    auto leaves_and_roots = TapeRootsAndLeafs(r);
    leaves_and_roots.set(v0, 0.5);

    auto intermediate_tape = evaluate_fwd_return_vals(leaves_and_roots);
    auto tape_d = TapeDerivatives(v0, r);
    tape_d.get(r) = 1.0;

    evaluate_bwd(leaves_and_roots, intermediate_tape, tape_d);
    EXPECT_NEAR(tape_d.get(v0), 1.6487212707001282, 1e-13);
}

TEST(EvaluateBwd, BivariateCutLeaf1) {
    auto [v0, v1] = Init<2>();
    // auto r = exp(cos(v0) * (v1 * v1));
    auto r = cos(v0) * cos(v1);

    auto leaves_and_roots = TapeRootsAndLeafs(r);
    leaves_and_roots.set(v0, 0.5);
    leaves_and_roots.set(v1, 2.);

    auto intermediate_tape = evaluate_fwd_return_vals(leaves_and_roots);
    auto tape_d = TapeDerivatives(v0, r);
    tape_d.get(r) = 1.0;

    evaluate_bwd(leaves_and_roots, intermediate_tape, tape_d);
    EXPECT_NEAR(tape_d.get(v0), -std::sin(0.5) * std::cos(2.), 1e-13);
}

TEST(EvaluateBwd, BivariateCutLeaf2) {
    auto [v0, v1] = Init<2>();
    // auto r = exp(cos(v0) * (v1 * v1));
    auto r = cos(v0) * cos(v1);

    auto leaves_and_roots = TapeRootsAndLeafs(r);
    leaves_and_roots.set(v0, 0.5);
    leaves_and_roots.set(v1, 2.);

    auto intermediate_tape = evaluate_fwd_return_vals(leaves_and_roots);
    auto tape_d = TapeDerivatives(v1, r);
    tape_d.get(r) = 1.0;

    evaluate_bwd(leaves_and_roots, intermediate_tape, tape_d);
    EXPECT_NEAR(tape_d.get(v1), std::cos(0.5) * -std::sin(2.), 1e-13);
}

TEST(EvaluateBwd, BlackScholes) {
    double result = 0.;

    {
        double S = 100.0;
        double K = 102.0;
        double v = 0.15;
        double T = 0.5;
        result = call_price(S, K, v, T);
    }

    auto [S, K, v, T] = Init<4>();
    auto result_adhoc = call_price(S, K, v, T);

    auto leaves_and_roots = TapeRootsAndLeafs(result_adhoc);
    leaves_and_roots.set(S, 100.0);
    leaves_and_roots.set(K, 102.0);
    leaves_and_roots.set(v, 0.15);
    leaves_and_roots.set(T, 0.5);

    auto intermediate_tape = evaluate_fwd_return_vals(leaves_and_roots);
    auto tape_d = TapeDerivatives(S, K, v, T, result_adhoc);

    tape_d.get(result_adhoc) = 1.0;

    evaluate_bwd(leaves_and_roots, intermediate_tape, tape_d);

    EXPECT_NEAR(tape_d.get(S), 0.33961663008862131, 1e-14);
    EXPECT_NEAR(tape_d.get(K), -0.38387614859866631, 1e-14);
    EXPECT_NEAR(tape_d.get(v), -30.580208040388474, 1e-14);
    EXPECT_NEAR(tape_d.get(T), -4.5870312060582705, 1e-14);
}

} // namespace adhoc2