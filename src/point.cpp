#include "point.hpp"
#include "vector.hpp"

Point operator+(const Point& lhs, const Vector& rhs)
{
    return Point{ lhs.X() + rhs.X(), lhs.Y() + rhs.Y(), lhs.Z() + rhs.Z() };
}
