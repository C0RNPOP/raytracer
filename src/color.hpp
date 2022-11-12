#pragma once

#include "tuple.hpp"

class Color : Tuple<3>
{
    public:
        Color(double r, double g, double b) : Tuple<3>{ { r, g, b } } {}

        double R() const { return this->data[0]; }
        double G() const { return this->data[1]; }
        double B() const { return this->data[2]; }
};
