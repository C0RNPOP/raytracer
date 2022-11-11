#include <catch2/catch_test_macros.hpp>
#include <sstream>

#include "tuple.hpp"
#include "point.hpp"
#include "vector.hpp"

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

TEST_CASE("Two Tuples with the same coordinates are equal")
{
    Point<double> point1{ 1.0, 2.0, 3.0 };
    Point<double> point2{ 1.0, 2.0, 3.0 };

    REQUIRE(point1 == point2);
}

TEST_CASE("Two Tuples with the different coordinates are not equal")
{
    Point<double> point1{ 1.0, 2.0, 3.0 };
    Point<double> point2{ 1.1, 2.1, 3.1 };

    REQUIRE(point1 != point2);
}

TEST_CASE("Adding two Tuples together")
{
    SECTION("Adding a Point and a Vector results in a new Point")
    {
        Point<int> point{ 3, -2, 5 };
        Vector<int> vector{ -2, 3, 1 };

        Point<int> expectedPoint{ 1, 1, 6 };
        Point<int> actualPoint = point + vector;

        REQUIRE(expectedPoint == actualPoint);
    }

    SECTION("Adding a Vector and a Vector result in a new Vector")
    {
        Vector<int> vector1{ 3, -2, 5 };
        Vector<int> vector2{ -2, 3, 1 };

        Vector<int> expectedPoint{ 1, 1, 6 };
        Vector<int> actualPoint = vector1 + vector2;

        REQUIRE(expectedPoint == actualPoint);
    }
}
