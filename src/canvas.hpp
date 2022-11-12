#pragma once

#include <cstddef>

#include "color.hpp"

template<std::size_t width, std::size_t height>
class Canvas
{
    public:
        Canvas() {}
        Canvas(const Color& color) { for(Color& elem : data) elem = color; }

        const Color& operator()(std::size_t x, std::size_t y) const
        {
            return data[x + y * width];
        }

        Color& operator()(std::size_t x, std::size_t y)
        {
            return data[x + y * width];
        }

        std::size_t Width() const { return width; }
        std::size_t Height() const { return height; }

    private:
        std::array<Color, width * height> data;
};
