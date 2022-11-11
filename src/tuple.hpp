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

template<typename T>
class Point : public Tuple<T, 4>
{
    public:
        Point(T x, T y, T z) : Tuple<T, 4>{ { x, y, z, 1 } } {}

        T X() const { return this->data[x]; }
        T Y() const { return this->data[y]; }
        T Z() const { return this->data[z]; }
        T W() const { return this->data[w]; }

    private:
        constexpr static int x = 0;
        constexpr static int y = 1;
        constexpr static int z = 2;
        constexpr static int w = 3;
};

template<typename T>
class Vector : public Tuple<T, 4>
{
    public:
        Vector(T x, T y, T z) : Tuple<T, 4>{ { x, y, z, 0 } } {}

        T X() const { return this->data[x]; }
        T Y() const { return this->data[y]; }
        T Z() const { return this->data[z]; }
        T W() const { return this->data[w]; }

    private:
        constexpr static int x = 0;
        constexpr static int y = 1;
        constexpr static int z = 2;
        constexpr static int w = 3;
};

template <typename T>
Point<T> operator+(const Point<T>& lhs, const Vector<T>& rhs)
{
    return Point<T>{ lhs.X() + rhs.X(), lhs.Y() + rhs.Y(), lhs.Z() + rhs.Z() };
}

template <typename T>
Vector<T> operator+(const Vector<T>& lhs, const Vector<T>& rhs)
{
    return Vector<T>{ lhs.X() + rhs.X(), lhs.Y() + rhs.Y(), lhs.Z() + rhs.Z() };
}
