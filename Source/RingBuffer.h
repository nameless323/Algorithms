//
// Copyright (C) Alexandr Vorontsov 2016.
// Distributed under the MIT License (license terms are at http://opensource.org/licenses/MIT).
//

#pragma once

#include <array>
#include <numeric>

namespace Algorithms
{
template <typename T, size_t ContainerSize>
class RingBuffer
{
public:
    template <typename... T>
    RingBuffer(T&&... args) : m_buffer({ std::forward<T>(args)... })
    {
        RecalculateSum();
    }

    RingBuffer() = default;

    RingBuffer(RingBuffer<T, ContainerSize>& rhs) : RingBuffer(const_cast<const RingBuffer<T, ContainerSize>&>(rhs))
    {}

    RingBuffer(const RingBuffer<T, ContainerSize>& rhs) : RingBuffer()
    {
        m_buffer = rhs.m_buffer;
        m_sum = rhs.m_sum;
    }

    RingBuffer(RingBuffer<T, ContainerSize>&& rhs) : RingBuffer()
    {
        using namespace std;
        swap(*this, rhs);
    }

    RingBuffer<T, ContainerSize>& operator=(RingBuffer<T, ContainerSize> rhs)
    {
        using namespace std;
        swap(*this, rhs);
        return *this;
    }

    template <typename U, typename = std::enable_if_t<std::is_convertible_v<T, std::remove_reference_t<U>>> >
    void Reset(const U&& value)
    {
        m_buffer.fill(std::forward<const U>(value));
        RecalculateSum();
    }

    template <typename U, typename = std::enable_if_t<std::is_convertible_v<T, std::remove_reference_t<U>>> >
    void Add(const U&& value)
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
        std::swap(rhs.m_sum, lhs.m_sum);
        std::swap(rhs.m_i, lhs.m_i);
        std::swap(rhs.m_buffer, lhs.m_buffer);
    }

private:
    inline void RecalculateSum();

    std::array<T, ContainerSize> m_buffer = {};
    int m_i = 0;
    T m_sum = {};
};

template <typename T, size_t ContainerSize>
void RingBuffer<T, ContainerSize>::RecalculateSum()
{
    m_sum = {};
    m_i = 0;
    for (auto& i : m_buffer)
    {
        m_sum += i;
    }
}
}