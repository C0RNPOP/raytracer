#pragma once

#include "tuple.hpp"

class Vector : public Tuple<4>
{
    public:
        Vector(double x, double y, double z) : Tuple<4>{ { x, y, z, 0 } } {}

        double Magnitude() const;

        double X() const { return this->data[0]; }
        double Y() const { return this->data[1]; }
        double Z() const { return this->data[2]; }
        double W() const { return this->data[3]; }
};

class Point;

Vector operator+(const Vector& lhs, const Vector& rhs);

Vector operator-(const Point& lhs, const Point& rhs);
Vector operator-(const Vector& lhs, const Vector& rhs);
Vector operator-(const Vector& vector);

Vector operator*(double scalar, const Vector& vector);
Vector operator*(const Vector& vector, double scalar);

Vector operator/(const Vector& vector, double scalar);
