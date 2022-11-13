#include <catch2/catch_test_macros.hpp>
#include <sstream>

#include "matrix.hpp"

TEST_CASE("Constructing and inspecting a Matrix")
{
    SECTION("Construcing a 2x2 Matrix")
    {
        const Matrix<2, 2> matrix{ {
            -3,  5,
             1, -2
        } };
    
        REQUIRE(matrix(0, 0) == -3);
        REQUIRE(matrix(0, 1) == 5);
        REQUIRE(matrix(1, 0) == 1);
        REQUIRE(matrix(1, 1) == -2);
    }

    SECTION("Construcing a 3x3 Matrix")
    {
        const Matrix<3, 3> matrix{ {
            -3,  5,  0,
             1, -2, -7,
             0,  1,  1,
        } };
    
        REQUIRE(matrix(0, 0) == -3);
        REQUIRE(matrix(1, 1) == -2);
        REQUIRE(matrix(2, 2) == 1);
    }

    SECTION("Construcing a 4x4 Matrix")
    {
        const Matrix<4, 4> matrix{ {
               1,    2,    3,    4,
             5.5,  6.5,  7.5,  8.5,
               9,   10,   11,   12,
            13.5, 14.5, 15.5, 16.5
        } };
    
        REQUIRE(matrix(0, 0) == 1);
        REQUIRE(matrix(0, 3) == 4);
        REQUIRE(matrix(1, 0) == 5.5);
        REQUIRE(matrix(1, 2) == 7.5);
        REQUIRE(matrix(2, 2) == 11);
        REQUIRE(matrix(3, 0) == 13.5);
        REQUIRE(matrix(3, 2) == 15.5);
    }
}

TEST_CASE("A Matrix's operator<< is correct")
{
    const Matrix<3, 3> matrix{ {
        -3,  5,  0,
         1, -2, -7,
         0,  1,  1,
    } };

    std::string expectedString{
        "{\n"
        "    -3, 5, 0, \n"
        "    1, -2, -7, \n"
        "    0, 1, 1, \n"
        "}"
    };

    std::ostringstream matrixStream;
    matrixStream << matrix;
    std::string actualString{ matrixStream.str() };

    REQUIRE(expectedString == actualString);
}

TEST_CASE("Two identical Matrixes are equal")
{
    Matrix<4, 4> matrix1{ {
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 8, 7, 6,
        5, 4, 3, 2
    } };
    Matrix<4, 4> matrix2{ {
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 8, 7, 6,
        5, 4, 3, 2
    } };

    REQUIRE(matrix1 == matrix2);
}

TEST_CASE("Two non-identical Matrixes are not equal")
{
    Matrix<4, 4> matrix1{ {
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 8, 7, 6,
        5, 4, 3, 2
    } };
    Matrix<4, 4> matrix2{ {
        9, 8, 7, 6,
        5, 4, 3, 2,
        1, 2, 3, 4,
        5, 6, 7, 8
    } };

    REQUIRE(matrix1 != matrix2);
}
