#pragma once

#include <vector>

namespace Algorithms
{
void Merge(std::vector<int>& v, int start, int median, int end);

void MergeSort(std::vector<int>& v, int start, int end)
{
    if (end - start == 1)
        return;
    int median = (start + end) / 2;
    MergeSort(v, start, median);
    MergeSort(v, median, end);
    Merge(v, start, median, end);
}

void Merge(std::vector<int>& v, int start, int median, int end)
{
    std::vector<int> left(v.begin() + start, v.begin() + median);
    std::vector<int> right(v.begin() + median, v.end());
    int marker = std::numeric_limits<int>::max();
    left.push_back(marker);
    right.push_back(marker);

    int l = 0, r = 0;
    for (int m = start; m < end; ++m)
    {
        if (left[l] < right[r])
            v[m] = left[l++];
        else
            v[m] = right[r++];
    }
}
}