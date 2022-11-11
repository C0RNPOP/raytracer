#pragma once

#include <array>
#include <ostream>

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

        friend bool operator==(const Tuple& rhs, const Tuple& lhs) { return rhs.data == lhs.data; }
        friend bool operator!=(const Tuple& rhs, const Tuple& lhs) { return rhs.data != lhs.data; }

    protected:
        Tuple(std::array<T, N> data) : data{ data } {}
        std::array<T, N> data;
};
