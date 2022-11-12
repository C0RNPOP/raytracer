#include "color.hpp"

Color operator+(const Color& lhs, const Color& rhs)
{
    return Color{ lhs.R() + rhs.R(), lhs.G() + rhs.G(), lhs.B() + rhs.B() };
}

Color operator-(const Color& lhs, const Color& rhs)
{
    return Color{ lhs.R() - rhs.R(), lhs.G() - rhs.G(), lhs.B() - rhs.B() };
}

Color operator*(double scalar, const Color& Color)
{
    return { scalar * Color.R(), scalar * Color.G(), scalar * Color.B() };
}

Color operator*(const Color& Color, double scalar)
{
    return scalar * Color;
}

Color operator*(const Color& lhs, const Color& rhs)
{
    return Color{ lhs.R() * rhs.R(), lhs.G() * rhs.G(), lhs.B() * rhs.B() };
}
