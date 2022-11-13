#pragma once

#include <array>
#include <cstddef>
#include <ostream>

#include "util.hpp"

template<std::size_t rows, std::size_t cols>
class Matrix
{
    public:
        Matrix() {}
        Matrix(std::array<double, rows * cols> data) : data{ data } {}

        double operator()(std::size_t i, std::size_t j) const
        {
            return data[i * rows + j];
        }

        double& operator()(std::size_t i, std::size_t j)
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

        friend bool operator==(const Matrix& lhs, const Matrix& rhs)
        {
            return std::equal(
                    lhs.data.begin(), lhs.data.end(), 
                    rhs.data.begin(), rhs.data.end(),
                    AreEqualFloating
            );
        }

        friend bool operator!=(const Matrix& lhs, const Matrix& rhs)
        {
            return !(lhs == rhs);
        }

    private:
        std::array<double, rows * cols> data{};
};

template<std::size_t M, std::size_t N, std::size_t P>
Matrix<M, P> operator*(const Matrix<M, N>& lhs, const Matrix<N, P>& rhs)
{
    Matrix<M, P> result{};

    for (std::size_t i = 0; i < M; i++)
    {
        for (std::size_t j = 0; j < P; j++)
        {
            for (std::size_t k = 0; k < N; k++)
            {
                result(i, j) += lhs(i, k) * rhs(k, j);
            }
        }
    }

    return result;
}
