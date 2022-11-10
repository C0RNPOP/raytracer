#include <catch2/catch_test_macros.hpp>
#include <sstream>

#include "tuple.hpp"

TEST_CASE("A Point is a Tuple with w = 1")
{
    Point<int> point{ 4, -4, 3 };

    REQUIRE(point.W() == 1);
}

TEST_CASE("A Vector is a Tuple with w = 0")
{
    Vector<int> vector{ 4, -4, 3 };

    REQUIRE(vector.W() == 0);
}

TEST_CASE("A Tuple's operator<< is correct")
{
    Point<int> point{ 4, -4, 3 };

    std::string expectedString{ "{ 4, -4, 3, 1 }"};

    std::ostringstream pointStream;
    pointStream << point;
    std::string actualString{ pointStream.str() };

    REQUIRE(expectedString == actualString);
}
