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
#include <windows.h>

#include "Source/DataStructures/RingBuffer.h"

#include "Source/DataStructures/LinkedList.h"

constexpr int a = 5;

int main()
{
    using namespace Algorithms;

    LinkedListNode<const char> n5{ '5' , nullptr };
    LinkedListNode<const char> n4{ '4' , &n5 };
    LinkedListNode<const char> n3{ '3' , &n4 };
    LinkedListNode<const char> n2{ '2' , &n3 };
    LinkedListNode<const char> n1{ '1' , &n2 };

    LinkedListNode<const char>* newHead = ReverseList(&n1);
    PrintList(newHead);

    std::vector<int> v = { -2, 34, 5, 64, 23, 62, 90 };
    //MergeSort(v, 0, 6);
    InsertionSort(v.begin(), v.end());

    getchar();

    return 0;
}
