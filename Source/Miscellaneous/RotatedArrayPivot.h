//
// Copyright (C) Alexandr Vorontsov 2016.
// Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
//

#pragma once

#include <vector>

#include "Source/Miscellaneous/BinarySearch.h"

namespace Algorithms
{
int FindRoatedArrayPivot(const std::vector<int>& v)
{
    if (v.size() == 1 || v[0] > v[1])
        return 0;
    if (v[v.size() - 2] > v[v.size() - 1])
        return static_cast<int>(v.size()) - 1;

    int left = 0;
    int right = static_cast<int>(v.size());

    while (right >= left)
    {
        int median = (left + right) / 2;
        bool correctToNext = v[median] < v[median + 1];
        bool correctToPrevious = v[median] > v[median - 1];
        if (correctToNext && !correctToPrevious)
            return median;

        if (v[median] < v[0])
            right = median;
        else if (v[median] > v[0])
            left = median;
    }
    return 0;
}

int FindElementInRotatedArray(std::vector<int>& v, int e)
{
    int pivot = FindRoatedArrayPivot(v);
    int res = BinarySearch(v, 0, pivot, e);
    if (res != -1)
        return res;
    res = BinarySearch(v, pivot, v.size() - 1, e);
    return res + pivot;
}
}