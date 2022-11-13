#pragma once

#include <cmath>
#include <string>
#include <vector>

constexpr double EPSILON = 0.0001;

constexpr bool AreEqualFloating(const double& lhs, const double& rhs)
{
    return std::abs(lhs - rhs) < EPSILON;
}

std::vector<std::string> split(std::string, char);
