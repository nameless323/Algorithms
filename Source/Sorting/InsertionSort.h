//
// Copyright (C) Alexandr Vorontsov 2016.
// Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
//

#pragma once

#include <functional>

namespace Algorithms
{
///
/// First iterator go forward, another from first go backwards and search the place where element belongs. When place found, insert element.
///
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

// Same but non template version.
void InsertionSort(std::vector<int>& container)
{
    for (int i = 0; i < container.size() - 1; ++i)
    {
        int key = container[i + 1];
        int j = i + 1;
        for (; j > 0; --j)
        {
            if (container[j - 1] > key)
                container[j] = container[j - 1];
            else
                break;
        }
        container[j] = key;
    }
}
}
