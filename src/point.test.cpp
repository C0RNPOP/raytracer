#include <catch2/catch_test_macros.hpp>
#include <sstream>

#include "tuple.hpp"
#include "point.hpp"
#include "vector.hpp"

TEST_CASE("A Point is a Tuple with w = 1")
{
    Point point{ 4, -4, 3 };

    REQUIRE(point.W() == 1);
}

TEST_CASE("Adding a Point and a Vector results in a new Point")
{
    Point point{ 3, -2, 5 };
    Vector vector{ -2, 3, 1 };

    Point expectedPoint{ 1, 1, 6 };
    Point actualPoint = point + vector;

    REQUIRE(expectedPoint == actualPoint);
}
