#include <catch2/catch_test_macros.hpp>
#include <sstream>

#include "tuple.hpp"
#include "point.hpp"
#include "vector.hpp"

TEST_CASE("A Tuple's operator<< is correct")
{
    Point point{ 4, -4, 3 };

    std::string expectedString{ "{ 4, -4, 3, 1 }"};

    std::ostringstream pointStream;
    pointStream << point;
    std::string actualString{ pointStream.str() };

    REQUIRE(expectedString == actualString);
}

TEST_CASE("Two Tuples with the same coordinates are equal")
{
    Point point1{ 1.0, 2.0, 3.0 };
    Point point2{ 1.0, 2.0, 3.0 };

    REQUIRE(point1 == point2);
}

TEST_CASE("Two Tuples with the different coordinates are not equal")
{
    Point point1{ 1.0, 2.0, 3.0 };
    Point point2{ 1.1, 2.1, 3.1 };

    REQUIRE(point1 != point2);
}
