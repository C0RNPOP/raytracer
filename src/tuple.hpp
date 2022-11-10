#pragma once

#include <array>

template<typename T, std::size_t N>
class Tuple
{
    protected:
        Tuple(std::array<T, N> data) : data{ data } {}
        std::array<T, N> data;
};

template<typename T>
class Point : Tuple<T, 4>
{
    public:
        Point(T x, T y, T z) : Tuple<T, 4>{ { x, y, z, 1 } } {}

        T W() const { return this->data[w]; }

    private:
        constexpr static int x = 0;
        constexpr static int y = 1;
        constexpr static int z = 2;
        constexpr static int w = 3;
};

template<typename T>
class Vector : Tuple<T, 4>
{
    public:
        Vector(T x, T y, T z) : Tuple<T, 4>{ { x, y, z, 0 } } {}

        T W() const { return this->data[w]; }

    private:
        constexpr static int x = 0;
        constexpr static int y = 1;
        constexpr static int z = 2;
        constexpr static int w = 3;
};
