//
// Copyright (C) Alexandr Vorontsov 2016.
// Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
//

#include <iostream>
#include <vector>
#include <array>

#include "Source/TemplateHelpers.h"
#include "Source/BubbleSort.h"

#include "Source/RingBuffer.h"

constexpr int a = 5;

int main()
{
    using namespace Algorithms;

    int x = 5;

    std::array<int, 4> arr = { 1, 2225, -31, 41 };
    RingBuffer<int, 4> b{arr};
    auto m = b.GetMax();
    auto n = b.GetMin();
    auto av = b.GetAverage();
    std::vector<int> v = { 2, 4, 5, 1, 34, 6 };
    Algorithms::BubbleSort(v.begin(), v.end(), [](const int& a, const int& b) { return a > b; });

//     std::cout << HasConstantIterator<int>::Value << " olollo " << v;
    for (auto& i : v)
        std::cout << i << " __ ";
    getchar();
    return 0;
}

