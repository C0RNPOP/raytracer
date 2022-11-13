#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

#include "canvas.hpp"
#include "util.hpp"

using Catch::Matchers::EndsWith;

TEST_CASE("Creating a Canvas")
{
    SECTION("Initializing a Canvas' width and Height")
    {
        const Canvas<10, 20> canvas{};

        REQUIRE(canvas.Width() == 10);
        REQUIRE(canvas.Height() == 20);
    }

    SECTION("Initializing a Canvas without a Color makes it all black")
    {
        const Canvas<10, 20> canvas{};

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
        const Canvas<10, 20> canvas{ Color{ 1, 0, 0 } };

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

TEST_CASE("Writing pixels to a Canvas")
{
    Canvas<10, 20> canvas{};
    Color red{ 1, 0, 0 };

    canvas(2, 3) = red;

    REQUIRE(red == canvas(2, 3));
    REQUIRE(red != canvas(3, 3));
}

TEST_CASE("Converting a Canvas to a PPM")
{
    SECTION("Constructing the PPM header")
    {
        Canvas<5, 3> canvas{};

        std::vector<std::string> splitPPM = split(canvas.ToPPM(), '\n');
        std::vector<std::string> expectedPPMHeader{ "P3", "5 3", "255" };
        std::vector<std::string> actualPPMHeader{ splitPPM.begin(), splitPPM.begin() + 3 };

        REQUIRE(expectedPPMHeader == actualPPMHeader);
    }

    SECTION("Constructing the PPM Body")
    {
        Canvas<5, 3> canvas{};
        canvas(0, 0) = Color{ 1.5, 0, 0 };
        canvas(2, 1) = Color{ 0, 0.5, 0 };
        canvas(4, 2) = Color{ -0.5, 0, 1 };

        std::vector<std::string> splitPPM = split(canvas.ToPPM(), '\n');
        std::vector<std::string> expectedPPMBody{ 
            "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0",
            "0 0 0 0 0 0 0 128 0 0 0 0 0 0 0",
            "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255",
        };
        std::vector<std::string> actualPPMBody{ splitPPM.begin() + 3, splitPPM.begin() + 6 };

        REQUIRE(expectedPPMBody == actualPPMBody);
    }

    SECTION("Splitting long lines in PPM files")
    {
        Canvas<10, 2> canvas{ Color{ 1, 0.8, 0.6 } };

        std::vector<std::string> splitPPM = split(canvas.ToPPM(), '\n');
        std::vector<std::string> expectedPPMBody{ 
            "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204",
            "153 255 204 153 255 204 153 255 204 153 255 204 153",
            "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204",
            "153 255 204 153 255 204 153 255 204 153 255 204 153",
        };
        std::vector<std::string> actualPPMBody{ splitPPM.begin() + 3, splitPPM.begin() + 7 };

        REQUIRE(expectedPPMBody == actualPPMBody);
    }

    SECTION("PPM files are terminated by a newline character")
    {
        Canvas<5, 3> canvas{};

        std::string ppm = canvas.ToPPM();

        REQUIRE_THAT(ppm, EndsWith("\n"));
    }
}
