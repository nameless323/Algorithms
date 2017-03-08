//
// Copyright (C) Alexandr Vorontsov 2016.
// Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
//

#pragma once

#include <type_traits>

template <typename T>
struct HasConstantIterator
{
private:
    template <typename C>
    static char Test(typename C::const_iterator*) {}

    template <typename C>
    static int Test(...) {}

public:
    enum { Value = sizeof(Test<T>(0)) == sizeof(char) };
};