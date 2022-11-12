#pragma once

#include "tuple.hpp"

template<typename T>
class Point;

template<typename T>
class Vector : public Tuple<T, 4>
{
    public:
        Vector(T x, T y, T z) : Tuple<T, 4>{ { x, y, z, 0 } } {}

        T X() const { return this->data[0]; }
        T Y() const { return this->data[1]; }
        T Z() const { return this->data[2]; }
        T W() const { return this->data[3]; }
};

template<typename T>
Vector<T> operator+(const Vector<T>& lhs, const Vector<T>& rhs)
{
    return Vector<T>{ lhs.X() + rhs.X(), lhs.Y() + rhs.Y(), lhs.Z() + rhs.Z() };
}

template<typename T>
Vector<T> operator-(const Point<T>& lhs, const Point<T>& rhs)
{
    return Vector<T>{ lhs.X() - rhs.X(), lhs.Y() - rhs.Y(), lhs.Z() - rhs.Z() };
}

template<typename T>
Vector<T> operator-(const Vector<T>& lhs, const Vector<T>& rhs)
{
    return Vector<T>{ lhs.X() - rhs.X(), lhs.Y() - rhs.Y(), lhs.Z() - rhs.Z() };
}

template<typename T>
Vector<T> operator-(const Vector<T>& vector)
{
    return Vector<T>{ 0, 0, 0 } - vector;
}

template<typename T1, typename T2>
auto operator*(T1 scalar, const Vector<T2>& vector) -> Vector<decltype(scalar * vector.X())>
{
    return { scalar * vector.X(), scalar * vector.Y(), scalar * vector.Z() };
}

template<typename T1, typename T2>
auto operator*(const Vector<T2>& vector, T1 scalar) -> Vector<decltype(scalar * vector.X())>
{
    return scalar * vector;
}

template<typename T1, typename T2>
auto operator/(const Vector<T2>& vector, T1 scalar) -> Vector<decltype(vector.X() / scalar)>
{
    return (1 / scalar) * vector;
}
