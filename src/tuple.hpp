#pragma once

#include <array>
#include <ostream>

#include "util.hpp"

template<std::size_t N>
class Tuple
{
    public:
        friend std::ostream& operator<<(std::ostream& os, const Tuple& tuple)
        {
            os << "{ ";
            for(const double& elem : tuple.data)
            {
                os << elem;
                if (&elem != &tuple.data.back())
                    os << ", ";
            }
            os << " }";
            return os;
        }

        friend bool operator==(const Tuple& lhs, const Tuple& rhs)
        { 
            return std::equal(
                    lhs.data.begin(), lhs.data.end(), 
                    rhs.data.begin(), rhs.data.end(),
                    AreEqualFloating
            );
        }

        friend bool operator!=(const Tuple& lhs, const Tuple& rhs) { return !(lhs == rhs); }

    protected:
        Tuple(std::array<double, N> data) : data{ data } {}
        std::array<double, N> data;
};
