#pragma once

#include "tuple.hpp"

class Point : public Tuple<4>
{
    public:
        Point(double x, double y, double z) : Tuple<4>{ { x, y, z, 1 } } {}

        double X() const { return this->data[0]; }
        double Y() const { return this->data[1]; }
        double Z() const { return this->data[2]; }
        double W() const { return this->data[3]; }
};

class Vector;

Point  operator+(const Point& lhs, const Vector& rhs);
