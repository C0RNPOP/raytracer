#pragma once

#include "tuple.hpp"

template<typename T>
class Point;

template<typename T>
class Vector : public Tuple<T, 4>
{
    public:
        Vector(T x, T y, T z) : Tuple<T, 4>{ { x, y, z, 0 } } {}

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
Vector<T> operator+(const Vector<T>& lhs, const Vector<T>& rhs)
{
    return Vector<T>{ lhs.X() + rhs.X(), lhs.Y() + rhs.Y(), lhs.Z() + rhs.Z() };
}

template <typename T>
Vector<T> operator-(const Point<T>& lhs, const Point<T>& rhs)
{
    return Vector<T>{ lhs.X() - rhs.X(), lhs.Y() - rhs.Y(), lhs.Z() - rhs.Z() };
}

template <typename T>
Vector<T> operator-(const Vector<T>& lhs, const Vector<T>& rhs)
{
    return Vector<T>{ lhs.X() - rhs.X(), lhs.Y() - rhs.Y(), lhs.Z() - rhs.Z() };
}

