#include <catch2/catch_test_macros.hpp>

#include "color.hpp"

TEST_CASE("Colors are RGB Tuples")
{
    Color color{ -0.5, 0.4, 1.7 };

    REQUIRE(color.R() == -0.5);
    REQUIRE(color.G() == 0.4);
    REQUIRE(color.B() == 1.7);
}

TEST_CASE("Adding a Color and a Color result in a new Color")
{
    Color color1{ 0.9, 0.6, 0.75 };
    Color color2{ 0.7, 0.1, 0.25 };

    Color expectedColor{ 1.6, 0.7, 1 };
    Color actualColor = color1 + color2;

    REQUIRE(expectedColor == actualColor);
}

TEST_CASE("Substracting a Color and a Color result in a new Color")
{
    Color color1{ 0.9, 0.6, 0.75 };
    Color color2{ 0.7, 0.1, 0.25 };

    Color expectedColor{ 0.2, 0.5, 0.5 };
    Color actualColor = color1 - color2;

    REQUIRE(expectedColor == actualColor);
}

TEST_CASE("Multiplying a Color")
{
    Color color{ 0.2, 0.3, 0.4 };

    SECTION("Multiplying a scalar and a Color")
    {
        Color expectedColor{ 0.4, 0.6, 0.8 };
        Color actualColor = 2 * color;

        REQUIRE(expectedColor == actualColor);
    }

    SECTION("Multiplying a Color and a scalar")
    {
        Color expectedColor{ 0.1, 0.15, 0.2 };
        Color actualColor = color * 0.5;

        REQUIRE(expectedColor == actualColor);
    }
}

TEST_CASE("Multiplying colors")
{
    Color color1{ 1, 0.2, 0.4 };
    Color color2{ 0.9, 1, 0.1 };

    Color expectedColor{ 0.9, 0.2, 0.04 };
    Color actualColor = color1 * color2;

    REQUIRE(expectedColor == actualColor);
}
