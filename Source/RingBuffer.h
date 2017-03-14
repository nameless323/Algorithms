//
// Copyright (C) Alexandr Vorontsov 2016.
// Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
//

#pragma once

#include <array>

#include <stdio.h>
#include <numeric>

namespace Algorithms
{
template <typename T, size_t ContainerSize>
class RingBuffer
{
public:
    template <typename... T>
    RingBuffer(T&&... args) : buffer({ std::forward<T>(args)... })
    {
        for (auto& i : buffer)
        {
            sum += i;
        }
    }

    void Reset(const T&& value)
    {
        buffer.fill(std::begin(buffer), std::end(buffer), std::forward<T>(value));
    }

    void Add(const T&& value)
    {
        sum -= buffer[i];
        buffer[i] = value;
        sum += value;
        i = ++i % buffer.size();
    }

    T GetAverage()
    {
        return static_cast<T>(sum * (1.0f / static_cast<float>(buffer.size())));
    }

    T GetMax(std::function<bool(const T&, const T&)> comparer = std::less<T>())
    {
        return *std::max_element(std::begin(buffer), std::end(buffer), comparer);
    }

    T GetMin(std::function<bool(const T&, const T&)> comparer = std::less<T>())
    {
        return *std::min_element(std::begin(buffer), std::end(buffer), comparer);
    }

private:
    std::array<T, ContainerSize> buffer = {};
    int i = 0;
    T sum = {};
};
}