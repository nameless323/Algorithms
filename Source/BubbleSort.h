#pragma once

#include <functional>

namespace Algorithms
{
template <typename T>
void BubbleSort(T first, T last, std::function<bool(decltype(*first), decltype(*last))> comparer)
{
    for (T i = first; i != last; i++)
    {
        for (T j = i; j != last; j++)
        {
            if (comparer(*i, *j))
                std::swap(*i, *j);
        }
    }
}
}