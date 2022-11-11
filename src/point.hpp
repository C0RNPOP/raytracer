#pragma once

#include "tuple.hpp"

template<typename T>
class Vector;

template<typename T>
class Point : public Tuple<T, 4>
{
    public:
        Point(T x, T y, T z) : Tuple<T, 4>{ { x, y, z, 1 } } {}

        T X() const { return this->data[x]; }
        T Y() const { return this->data[y]; }
        T Z() const { return this->data[z]; }
        T W() const { return this->data[w]; }

    private:
        constexpr static int x = 0;
        constexpr static int y = 1;
        constexpr static int z = 2;
        constexpr static int w = 3;
};


template <typename T>
Point<T> operator+(const Point<T>& lhs, const Vector<T>& rhs)
{
    return Point<T>{ lhs.X() + rhs.X(), lhs.Y() + rhs.Y(), lhs.Z() + rhs.Z() };
}
