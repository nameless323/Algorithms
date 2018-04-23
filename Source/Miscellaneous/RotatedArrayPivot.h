#pragma once

#include <vector>

namespace Algorithms
{
int FindRoatedArrayPivot(const std::vector<int>& v)
{
    if (v.size() == 1 || v[0] > v[1])
        return 0;
    if (v[v.size() - 2] > v[v.size() - 1])
        return v.size() - 1;

    int left = 0;
    int right = static_cast<int>(v.size());

    while ((right - left) > 1)
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
}