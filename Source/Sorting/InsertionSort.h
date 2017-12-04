//
// Copyright (C) Alexandr Vorontsov 2016.
// Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
//
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
    for (T i = first; i != last - 1; std::advance(i, 1))
    {
        auto key = *(i + 1);
        T j = i + 1;
        for (; j != first; std::advance(j, -1))
        {
            if (comparer(key, *(j - 1)))
                *j = *(j - 1);
            else
                break;
        }
        *j = key;
    }
}
}
