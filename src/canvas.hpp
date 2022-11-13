#pragma once

#include <cstddef>
#include <vector>

#include "color.hpp"

class Canvas
{
    public:
        Canvas(std::size_t width, std::size_t height, const Color& color = Color{ 0, 0, 0 }) 
            : width{ width }, height{ height }, data{ width * height, color } {}

        const Color& operator()(std::size_t x, std::size_t y) const
        {
            return data[x + y * width];
        }

        Color& operator()(std::size_t x, std::size_t y)
        {
            return data[x + y * width];
        }

        std::string ToPPM() const;
        std::size_t Width() const { return width; }
        std::size_t Height() const { return height; }

    private:
        std::size_t width;
        std::size_t height;
        std::vector<Color> data;
};
