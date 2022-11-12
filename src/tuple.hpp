#pragma once

#include <array>
#include <ostream>

#include "util.hpp"

template<typename T, std::size_t N>
class Tuple
{
    using Type = T;
    std::size_t Length = N;

    public:
        friend std::ostream& operator<<(std::ostream& os, const Tuple& tuple)
        {
            os << "{ ";
            for(const T& elem : tuple.data)
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
                    AreEqualFloating<T>
            );
        }

        friend bool operator!=(const Tuple& lhs, const Tuple& rhs) { return !(lhs == rhs); }

    protected:
        Tuple(std::array<T, N> data) : data{ data } {}
        std::array<T, N> data;
};
