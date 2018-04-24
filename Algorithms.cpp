//
// Copyright (C) Alexandr Vorontsov 2016.
// Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
//

#include <iostream>
#include <vector>
#include <array>

#include "Source/Utils/TemplateHelpers.h"
#include "Source/Sorting/BubbleSort.h"
#include "Source/Sorting/InsertionSort.h"
#include "Source/Sorting/MergeSort.h"
#include "Source/MaxSubarraySum.h"
#include "Source/Miscellaneous/RotatedArrayPivot.h"
#include "Source/Miscellaneous/BinarySearch.h"
#include <windows.h>

#include "Source/DataStructures/RingBuffer.h"

#include "Source/DataStructures/LinkedList.h"

constexpr int a = 5;

int main()
{
    using namespace Algorithms;
    std::vector<int> v = { 13, 14, 5, 6, 7, 12 };
    int ind = FindElementInRotatedArray(v, 12);
    getchar();

    return 0;
}
