//
// Copyright (C) Alexandr Vorontsov 2016.
// Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
//

#include <vector>

#pragma once

namespace Algorithms
{
int BinarySearch(std::vector<int> v, int begin, int end, int value)
{
    while (end >= begin)
    {
        int median = (end + begin) / 2;
        if (v[median] > value)
            end = median - 1;
        else if (v[median] < value)
            begin = median + 1;
        else
            return median;
    }
    return -1;
}
}