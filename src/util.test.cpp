#include <catch2/catch_test_macros.hpp>

#include "util.hpp"

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

TEST_CASE("Splitting a string by delimiter into a vector of string")
{
    std::string string{
        "P3\n"
        "80 40\n"
        "255"
    };
    char delimiter{ '\n' };

    std::vector<std::string> expectedVector{ "P3", "80 40", "255" };
    std::vector<std::string> actualVector = split(string, delimiter);

    REQUIRE(expectedVector == actualVector);
}
