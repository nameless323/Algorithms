//
// Copyright (C) Alexandr Vorontsov 2016.
// Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
//

#include <vector>

#pragma once

namespace Algorithms
{
int BinarySearch(std::vector<int>::iterator begin, std::vector<int>::iterator end, int value)
{
    auto oldBegin = begin;
    while (1)
    {
        ptrdiff_t median = std::distance(begin, end) / 2;
        if (*(begin + median) > value)
            end = begin + median;
        else if (*(begin + median) < value)
            begin = begin + median;
        else
            return static_cast<int>(std::distance(oldBegin, begin + median));
        if (median == 0)
            return -1;
    }
    return -1;
}
}