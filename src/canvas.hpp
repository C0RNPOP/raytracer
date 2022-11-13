#pragma once

#include <algorithm>
#include <cstddef>
#include <sstream>

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

        std::string ToPPM() const
        { 
            std::ostringstream ppm;
            WritePPMHeader(ppm);
            WritePPMBody(ppm);
            return ppm.str();
        }

        std::size_t Width() const { return width; }
        std::size_t Height() const { return height; }

    private:
        std::array<Color, width * height> data;

        void WritePPMHeader(std::ostringstream& ppm) const
        {
            ppm << "P3\n";
            ppm << width << " " << height << "\n";
            ppm << "255\n";
        }

        void WritePPMBody(std::ostringstream& ppm) const
        {
            for (std::size_t y = 0; y < height; y++)
            {
                std::size_t lineLen{ 0 };
                for(std::size_t x = 0; x < width; x++)
                {
                    Color color = (*this)(x, y);

                    WritePPMComponent(ppm, color.R(), lineLen);
                    WritePPMComponent(ppm, color.G(), lineLen);
                    WritePPMComponent(ppm, color.B(), lineLen);
                }
                ppm << "\n";
            }
        }

        void WritePPMComponent(std::ostringstream& ppm, double comp, std::size_t& lineLen) const
        {
            constexpr std::size_t PPM_LINE_LIMIT = 70;

            unsigned int clampedComp = std::round(std::clamp(255 * comp, 0.0, 255.0));
            std::string stringComp = std::to_string(clampedComp);
            
            if (lineLen + 1 + stringComp.length() > PPM_LINE_LIMIT)
            {
                ppm << "\n";
                lineLen = 0;
            }
            else if (lineLen != 0)
            {
                ppm << " ";
                lineLen += 1;
            }

            ppm << stringComp;
            lineLen += stringComp.length();
        }
};
