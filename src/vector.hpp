#pragma once

#include "tuple.hpp"

class Vector : public Tuple<4>
{
    public:
        Vector(double x, double y, double z) : Tuple<4>{ { x, y, z, 0 } } {}

        double Magnitude() const;
        Vector Normalized() const;
        double Dot(const Vector&) const;
        Vector Cross(const Vector&) const;

        double X() const { return this->data[0]; }
        double Y() const { return this->data[1]; }
        double Z() const { return this->data[2]; }
        double W() const { return this->data[3]; }
};

class Point;

Vector operator+(const Vector&, const Vector&);

Vector operator-(const Point&, const Point&);
Vector operator-(const Vector&, const Vector&);
Vector operator-(const Vector&);

Vector operator*(double, const Vector&);
Vector operator*(const Vector&, double);

Vector operator/(const Vector&, double);
