#include "point.hpp"
#include "vector.hpp"

double Vector::Magnitude() const
{
    return std::sqrt(X() * X() + Y() * Y() + Z() * Z());
}

Vector Vector::Normalized() const
{
    return *this / Magnitude();
}

double Vector::Dot(const Vector& other) const
{
    return X() * other.X() + Y() * other.Y() + Z() * other.Z();
}

Vector Vector::Cross(const Vector& other) const
{
    return { 
        Y() * other.Z() - Z() * other.Y(),
        Z() * other.X() - X() * other.Z(),
        X() * other.Y() - Y() * other.X()
    };
}

Vector operator+(const Vector& lhs, const Vector& rhs)
{
    return Vector{ lhs.X() + rhs.X(), lhs.Y() + rhs.Y(), lhs.Z() + rhs.Z() };
}

Vector operator-(const Point& lhs, const Point& rhs)
{
    return Vector{ lhs.X() - rhs.X(), lhs.Y() - rhs.Y(), lhs.Z() - rhs.Z() };
}

Vector operator-(const Vector& lhs, const Vector& rhs)
{
    return Vector{ lhs.X() - rhs.X(), lhs.Y() - rhs.Y(), lhs.Z() - rhs.Z() };
}

Vector operator-(const Vector& vector)
{
    return Vector{ 0, 0, 0 } - vector;
}

Vector operator*(double scalar, const Vector& vector)
{
    return { scalar * vector.X(), scalar * vector.Y(), scalar * vector.Z() };
}

Vector operator*(const Vector& vector, double scalar)
{
    return scalar * vector;
}

Vector operator/(const Vector& vector, double scalar)
{
    return (1 / scalar) * vector;
}
