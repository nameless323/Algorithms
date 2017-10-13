//
// Copyright (C) Alexandr Vorontsov 2016.
// Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
//

#pragma once

#include <iostream>

namespace Algorithms
{
template <typename T>
struct LinkedListNode
{
    T Data;
    LinkedListNode<T>* Next;
};

template <typename T>
void PrintList(const LinkedListNode<T>* head)
{
    while (head != nullptr)
    {
        std::cout << head->Data << "\n";
        head = head->Next;
    }
    std::cout << std::endl;
}

template <typename T>
LinkedListNode<T>* ReverseList(LinkedListNode<T>* head)
{
    LinkedListNode<T>* prevNode = nullptr;
    while (head != nullptr)
    {
        LinkedListNode<T>* next = head->Next;
        head->Next = prevNode;
        prevNode = head;
        head = next;
    }
    return prevNode;
}
}