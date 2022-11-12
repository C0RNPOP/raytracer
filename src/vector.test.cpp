#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include "tuple.hpp"
#include "point.hpp"
#include "vector.hpp"

using Catch::Matchers::WithinAbs;

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

TEST_CASE("Computing the magnitude of a Vector")
{
    SECTION("Computing the magntiude of Vector{ 1, 0, 0 }")
    {
        Vector vector{ 1, 0, 0 };

        double expectedMagnitude = 1;
        double actualMagnitude = vector.Magnitude();

        REQUIRE(expectedMagnitude == actualMagnitude);
    }

    SECTION("Computing the magntiude of Vector{ 0, 1, 0 }")
    {
        Vector vector{ 0, 1, 0 };

        double expectedMagnitude = 1;
        double actualMagnitude = vector.Magnitude();

        REQUIRE(expectedMagnitude == actualMagnitude);
    }

    SECTION("Computing the magntiude of Vector{ 0, 0, 1 }")
    {
        Vector vector{ 0, 0, 1 };

        double expectedMagnitude = 1;
        double actualMagnitude = vector.Magnitude();

        REQUIRE(expectedMagnitude == actualMagnitude);
    }

    SECTION("Computing the magntiude of Vector{ 1, 2, 3 }")
    {
        Vector vector{ 1, 2, 3 };

        double expectedMagnitude = std::sqrt(14);
        double actualMagnitude = vector.Magnitude();

        REQUIRE_THAT(expectedMagnitude, WithinAbs(actualMagnitude, EPSILON));
    }

    SECTION("Computing the magntiude of Vector{ -1, -2, -3 }")
    {
        Vector vector{ -1, -2, -3 };

        double expectedMagnitude = std::sqrt(14);
        double actualMagnitude = vector.Magnitude();

        REQUIRE_THAT(expectedMagnitude, WithinAbs(actualMagnitude, EPSILON));
    }
}

TEST_CASE("Normalizing a Vector")
{
    SECTION("Normalizing Vector{ 4, 0, 0 }")
    {
        Vector vector{ 4, 0, 0 };

        Vector expectedNormalized{ 1, 0, 0 };
        Vector actualNormalized = vector.Normalized();

        REQUIRE(expectedNormalized == actualNormalized);
    }

    SECTION("Normalizing Vector{ 4, 0, 0 }")
    {
        Vector vector{ 1, 2, 3 };

        Vector expectedNormalized{ 0.26726, 0.53452, 0.80178 };
        Vector actualNormalized = vector.Normalized();

        REQUIRE(expectedNormalized == actualNormalized);
    }
}

TEST_CASE("The magnitude of a normalized Vector is 1")
{
    Vector norm = Vector{ 1, 2, 3 }.Normalized();

    double expectedMagnitude = 1;
    double actualMagnitude = norm.Magnitude();

    REQUIRE(expectedMagnitude == actualMagnitude);
}

TEST_CASE("The dot product of two Vectors")
{
    Vector vector1{ 1, 2, 3 };
    Vector vector2{ 2, 3, 4 };

    double expectedDot = 20;
    double actualDot = vector1.Dot(vector2);

    REQUIRE(expectedDot == actualDot);
}

TEST_CASE("The cross product of two Vectors")
{
    Vector vector1{ 1, 2, 3 };
    Vector vector2{ 2, 3, 4 };

    SECTION("The cross product of { 1, 2, 3 } by { 2, 3, 4 }")
    {
        Vector expectedDot{ -1, 2, -1 };
        Vector actualDot = vector1.Cross(vector2);

        REQUIRE(expectedDot == actualDot);
    }

    SECTION("The cross product of { 2, 3, 4 } by { 1, 2, 3 }")
    {
        Vector expectedDot{ 1, -2, 1 };
        Vector actualDot = vector2.Cross(vector1);

        REQUIRE(expectedDot == actualDot);
    }
}
