#include <catch2/catch_test_macros.hpp>

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
