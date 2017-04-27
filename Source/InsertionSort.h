//
// Copyright (C) Alexandr Vorontsov 2016.
// Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
//

#pragma once

#include <functional>

namespace Algorithms
{
template <typename T>
void InsertionSort(T first, T last, std::function<bool(decltype(*first), decltype(*last))> comparer = std::less<decltype(*first)>())
{
    for (T i = first; i != last - 1; ++i)
    {
        for (T j = i + 1; j != first; --j)
        {
            if (comparer(*j, *(j - 1)))
                std::swap(*j, *(j - 1));
            else
                break;
        }
    }
}
}
