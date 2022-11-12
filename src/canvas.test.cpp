#include <catch2/catch_test_macros.hpp>

#include "canvas.hpp"

TEST_CASE("Creating a Canvas")
{
    SECTION("Initializing a Canvas' width and Height")
    {
        Canvas<10, 20> canvas{};

        REQUIRE(canvas.Width() == 10);
        REQUIRE(canvas.Height() == 20);
    }

    SECTION("Initializing a Canvas without a Color makes it all black")
    {
        Canvas<10, 20> canvas{};

        Color expectedColor{ 0, 0, 0 };
        for (std::size_t y = 0; y < canvas.Height(); y++)
        {
            for (std::size_t x = 0; x < canvas.Width(); x++)
            {
                Color actualColor = canvas(x, y);

                REQUIRE(expectedColor == actualColor);
            }
        }
    }

    SECTION("Initializing a Canvas with a Color")
    {
        Canvas<10, 20> canvas{ Color{ 1, 0, 0 } };

        Color expectedColor{ 1, 0, 0 };
        for (std::size_t y = 0; y < canvas.Height(); y++)
        {
            for (std::size_t x = 0; x < canvas.Width(); x++)
            {
                Color actualColor = canvas(x, y);

                REQUIRE(expectedColor == actualColor);
            }
        }
    }
}
