//
// Copyright (C) Alexandr Vorontsov 2016.
// Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
//

#pragma once

#include <functional>

namespace Algorithms
{
template <typename T>
void BubbleSort(T first, T last, std::function<bool(decltype(*first), decltype(*last))> comparer = std::greater<decltype(*first)>())
{
    for (T i = first; i != last - 1; ++i)
    {
        for (T j = i + 1; j != last; ++j)
        {
            if (comparer(*i, *j))
                std::swap(*i, *j);
        }
    }
}

void BubbleSort(std::vector<int>& v)
{
    for (int i = 0; i < v.size() - 1; ++i)
    {
        bool swapped = false;
        for (int j = 0; j < v.size() - i - 1; ++j)
        {
            if (v[j] > v[j + 1])
            {
                std::swap(v[j], v[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            return;
    }
}
}