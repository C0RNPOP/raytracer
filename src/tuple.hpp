#pragma once

#include <array>
#include <ostream>

template<typename T, std::size_t N>
class Tuple
{
    public:
        friend std::ostream& operator<<(std::ostream& os, const Tuple& tuple)
        {
            os << "{ ";
            for(const T& elem : tuple.data)
            {
                os << elem;
                if (&elem != &tuple.data.back())
                    os << ", ";
            }
            os << " }";
            return os;
        }

    protected:
        Tuple(std::array<T, N> data) : data{ data } {}
        std::array<T, N> data;
};

template<typename T>
class Point : public Tuple<T, 4>
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
class Vector : public Tuple<T, 4>
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
