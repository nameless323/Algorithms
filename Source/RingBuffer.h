//
// Copyright (C) Alexandr Vorontsov 2016.
// Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
//

#pragma once

#include <array>

#include <stdio.h>
#include <numeric>
#include <iostream>

namespace Algorithms
{
template <typename T, size_t ContainerSize>
class RingBuffer
{
public:
    template <typename... T>
    RingBuffer(T&&... args) : m_buffer({ std::forward<T>(args)... })
    {
        for (auto& i : m_buffer)
        {
            m_sum += i;
        }
    }

    RingBuffer() = default;

    RingBuffer(RingBuffer<T, ContainerSize>& rhs) : RingBuffer(const_cast<const RingBuffer<T, ContainerSize>&>(rhs))
    {}

    RingBuffer(const RingBuffer<T, ContainerSize>& rhs) : RingBuffer()
    {
        m_buffer = rhs.buffer;
        m_sum = rhs.sum;
    }

    RingBuffer(RingBuffer<T, ContainerSize>&& rhs) : RingBuffer()
    {
        using namespace std;
        swap(*this, rhs);
    }

    RingBuffer<T, ContainerSize>& operator=(RingBuffer<T, ContainerSize> rhs)
    {
        m_buffer.swap(rhs.buffer);
        return *this;
    }

    void Reset(const T&& value)
    {
        m_buffer.fill(std::begin(m_buffer), std::end(m_buffer), std::forward<T>(value));
    }

    void Add(const T&& value)
    {
        m_sum -= m_buffer[m_i];
        m_buffer[m_i] = value;
        m_sum += value;
        m_i = ++m_i % m_buffer.size();
    }

    T GetAverage()
    {
        return static_cast<T>(m_sum * (1.0f / static_cast<float>(m_buffer.size())));
    }

    T GetMax(std::function<bool(const T&, const T&)> comparer = std::less<T>())
    {
        return *std::max_element(std::begin(m_buffer), std::end(m_buffer), comparer);
    }

    T GetMin(std::function<bool(const T&, const T&)> comparer = std::less<T>())
    {
        return *std::min_element(std::begin(m_buffer), std::end(m_buffer), comparer);
    }

    friend void swap(RingBuffer<T, ContainerSize>& rhs, RingBuffer<T, ContainerSize>& lhs)
    {
        std::swap(rhs.buffer, lhs.buffer);
    }

private:
    std::array<T, ContainerSize> m_buffer = {};
    int m_i = 0;
    T m_sum = {};
};
}