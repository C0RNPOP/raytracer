#include <catch2/catch_test_macros.hpp>

#include "util.h"

TEST_CASE("Two floating-point number separated by less than EPSILON are equal")
{
    double d1{ 4.3581498 };
    double d2{ d1 + EPSILON / 2 };

    REQUIRE(AreEqualFloating(d1, d2));
}

TEST_CASE("Two floating-point number separated by more than EPSILON are equal")
{
    double d1{ 4.3581498 };
    double d2{ d1 + EPSILON * 2 };

    REQUIRE(!AreEqualFloating(d1, d2));
}
