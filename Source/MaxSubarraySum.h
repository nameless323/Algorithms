//
// Copyright (C) Alexandr Vorontsov 2016.
// Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
//

#pragma once

#include <vector>

namespace Algorithms
{
struct MaxCrossArrayResult
{
    float MaxSum = -std::numeric_limits<float>::max();
    int LowIndex = -1;
    int HighIndex = -1;
};

MaxCrossArrayResult FindMaxCrossingArray(std::vector<float> src, int low, int high)
{
    int mid = (low + high) / 2;
    float maxLeftSum = -std::numeric_limits<float>::max();
    float maxRightSum = -std::numeric_limits<float>::max();
    float leftSum = 0;
    float rightSum = 0;
    MaxCrossArrayResult res; 
    res.LowIndex = mid;
    res.HighIndex = mid + 1;
    for (int i = mid; i >= low; --i)
    {
        leftSum += src[i];
        if (leftSum > maxLeftSum)
        {
            maxLeftSum = leftSum;
            res.LowIndex = i;
        }
    }
    for (int i = mid + 1; i <= high; ++i)
    {
        rightSum += src[i];
        if (rightSum > maxRightSum)
        {
            maxRightSum += rightSum;
            res.HighIndex = i;
        }
    }
    res.MaxSum = rightSum + leftSum;
    return res;
}
}