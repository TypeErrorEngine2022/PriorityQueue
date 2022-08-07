#pragma once

#include "binaryHeap.h"

#include <algorithm>
#include <iostream>

template <typename Key>
BinaryHeap<Key>::BinaryHeap(int maxN):
    m_size(0)
{
    data.resize(maxN);
}

template <typename Key>
BinaryHeap<Key>::BinaryHeap(std::vector<Key> nums):
    data(nums), m_size(nums.size())
{

}

template <typename Key>
int BinaryHeap<Key>::size() const
{
    return m_size;
}

template <typename Key>
bool BinaryHeap<Key>::empty() const
{
    return m_size == 0;
}

template <typename Key>
void BinaryHeap<Key>::insert(Key k)
{
    data[++m_size] = k;
    swim(m_size);
}

template <typename Key>
Key BinaryHeap<Key>::delMax()
{
    Key max = data[0];
    //exchange with the last item, since last item has no children
    //less link to break
    swap(0, m_size--);
    sink(0);

    return max;
}

template <typename Key>
std::vector<Key> BinaryHeap<Key>::sort()
{
    //build max-heap : O(n)
    for (int i = m_size / 2; i >= 0; i--)
    {
        sink(i);
    }

    while (m_size > 0)
    {
        swap(0, m_size--);
        sink(0);
    }

    return data;
}

template <typename Key>
void BinaryHeap<Key>::print() const
{
    for (int i = 0; i <= m_size; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

template <typename Key>
bool BinaryHeap<Key>::less(int i, int j) const
{
    //larger element has lower priority
    return data[i] <= data[j];
}

template <typename Key>
void BinaryHeap<Key>::swap(int i, int j)
{
    std::swap(data[i], data[j]);
}

template <typename Key>
void BinaryHeap<Key>::swim(int k)
{
    while (k > 0 && less(k / 2, k))
    {
        swap(k / 2, k);
        k = k / 2;
    }
}

template <typename Key>
void BinaryHeap<Key>::sink(int k)
{
    while (2 * k + 1 <= m_size)
    {
        int j = 2 * k + 1;

        //choose the larger children to compare with the parent
        if (j + 1 <= m_size && less(j, j + 1))
        {
            ++j;
        }
        //If it is larger than the largest children, do not sink
        if (!less(k, j))
        {
            break;
        }
        swap(k, j);
        k = j;
    }
}