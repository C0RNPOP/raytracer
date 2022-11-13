#include <sstream>

#include "util.hpp"

std::vector<std::string> split(std::string input, char delimiter)
{
    std::istringstream stream{ input };

    std::vector<std::string> splitInput{};
    for (std::string line{}; std::getline(stream, line, delimiter); )
    {
        splitInput.push_back(line);
    }

    return splitInput;
}
