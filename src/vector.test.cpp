#include <catch2/catch_test_macros.hpp>
#include <sstream>

#include "tuple.hpp"
#include "point.hpp"
#include "vector.hpp"

TEST_CASE("A Vector is a Tuple with w = 0")
{
    Vector vector{ 4, -4, 3 };

    REQUIRE(vector.W() == 0);
}

TEST_CASE("Adding a Vector and a Vector result in a new Vector")
{
    Vector vector1{ 3, -2, 5 };
    Vector vector2{ -2, 3, 1 };

    Vector expectedVector{ 1, 1, 6 };
    Vector actualVector = vector1 + vector2;

    REQUIRE(expectedVector == actualVector);
}

TEST_CASE("Substracting a Point and a Point results in a new Vector")
{
    Point point1{ 3, 2, 1 };
    Point point2{ 5, 6, 7 };

    Vector expectedVector{ -2, -4, -6 };
    Vector actualVector = point1 - point2;

    REQUIRE(expectedVector == actualVector);
}

TEST_CASE("Substracting a Vector and a Vector result in a new Vector")
{
    Vector vector1{ 3, 2, 1 };
    Vector vector2{ 5, 6, 7 };

    Vector expectedVector{ -2, -4, -6 };
    Vector actualVector = vector1 - vector2;

    REQUIRE(expectedVector == actualVector);
}

TEST_CASE("Negating a Vector")
{
    Vector vector{ 1, -2, 3 };
    
    Vector expectedVector{ -1, 2, -3 };
    Vector actualVector = -vector;

    REQUIRE(expectedVector == actualVector);
}

TEST_CASE("Multiplying a Vector")
{
    Vector vector{ 1, -2, 3 };

    SECTION("Multiplying a scalar and a Vector")
    {
        Vector expectedVector{ 3.5, -7, 10.5 };
        Vector actualVector = 3.5 * vector;

        REQUIRE(expectedVector == actualVector);
    }

    SECTION("Multiplying a Vector and a scalar")
    {
        Vector expectedVector{ 0.5, -1, 1.5 };
        Vector actualVector = vector * 0.5;

        REQUIRE(expectedVector == actualVector);
    }
}

TEST_CASE("Dividing a Vector by a scalar")
{
    Vector vector{ 1, -2, 3 };

    Vector expectedVector{ 0.5, -1, 1.5 };
    Vector actualVector = vector / 2.0;

    REQUIRE(expectedVector == actualVector);
}
