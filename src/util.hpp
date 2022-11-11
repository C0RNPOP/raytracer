#include <cmath>

constexpr double EPSILON = 0.0001;

template<typename T>
constexpr bool AreEqualFloating(T lhs, T rhs)
{
    return std::abs(lhs - rhs) < EPSILON;
}
