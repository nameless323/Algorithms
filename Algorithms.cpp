//
// Copyright (C) Alexandr Vorontsov 2016.
// Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
//

#include <iostream>
#include <vector>

#include "Source/TemplateHelpers.h"

constexpr int a = 5;

int main()
{
    int x = 5;

    std::cout << HasConstantIterator<int>::Value << " olollo " << a;
    getchar();
    return 0;
}

