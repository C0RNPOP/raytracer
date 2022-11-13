#include <algorithm>
#include <sstream>

#include "canvas.hpp"

static void WritePPMHeader(std::ostringstream&, const Canvas&);
static void WritePPMBody(std::ostringstream&, const Canvas&);

std::string Canvas::ToPPM() const
{ 
    std::ostringstream ppm;
    WritePPMHeader(ppm, *this);
    WritePPMBody(ppm, *this);
    return ppm.str();
}

static void WritePPMHeader(std::ostringstream& ppm, const Canvas& canvas)
{
    ppm << "P3\n";
    ppm << canvas.Width() << " " << canvas.Height() << "\n";
    ppm << "255\n";
}

static void WritePPMComponent(std::ostringstream& ppm, double comp, std::size_t& lineLen)
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

static void WritePPMBody(std::ostringstream& ppm, const Canvas& canvas)
{
    for (std::size_t y = 0; y < canvas.Height(); y++)
    {
        std::size_t lineLen{ 0 };
        for(std::size_t x = 0; x < canvas.Width(); x++)
        {
            Color color = canvas(x, y);

            WritePPMComponent(ppm, color.R(), lineLen);
            WritePPMComponent(ppm, color.G(), lineLen);
            WritePPMComponent(ppm, color.B(), lineLen);
        }
        ppm << "\n";
    }
}
