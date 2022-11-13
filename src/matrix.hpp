#pragma once

#include <array>
#include <cstddef>

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

    private:
        std::array<double, rows * cols> data;
};
