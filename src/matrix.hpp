#pragma once

#include <array>
#include <cstddef>
#include <ostream>

#include "util.hpp"

template<std::size_t rows, std::size_t cols>
class Matrix
{
    public:
        Matrix(std::array<double, rows * cols> data) : data{ data } {}

        double operator()(std::size_t i, std::size_t j) const
        {
            return data[i * rows + j];
        }

        double operator()(std::size_t i, std::size_t j)
        {
            return data[i * rows + j];
        }

        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
        {
            os << "{\n";

            for (std::size_t i = 0; i < rows; i++)
            {
                os << "    ";
                for(std::size_t j = 0; j < cols; j++)
                {
                    os << matrix(i, j);
                    os << ", ";
                }
                os << "\n";
            }

            os << "}";

            return os;
        }

    private:
        std::array<double, rows * cols> data;
};
