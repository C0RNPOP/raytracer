#include <cmath>

constexpr double EPSILON = 0.0001;

constexpr bool AreEqualFloating(const double& lhs, const double& rhs)
{
    return std::abs(lhs - rhs) < EPSILON;
}
