#include <catch2/catch_test_macros.hpp>

#include "color.hpp"

TEST_CASE("Colors are RGB Tuples")
{
    Color color{ -0.5, 0.4, 1.7 };

    REQUIRE(color.R() == -0.5);
    REQUIRE(color.G() == 0.4);
    REQUIRE(color.B() == 1.7);
}
