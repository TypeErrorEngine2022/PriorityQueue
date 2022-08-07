#pragma once

#include "IndexPriorityQueue.h"

#include <algorithm>
#include <iostream>

template <typename Item>
IndexPriorityQueue<Item>::IndexPriorityQueue(int maxN):
    m_size(0)
{
    m_data.resize(maxN);
    m_im.resize(maxN);
    m_pm.resize(maxN);

    std::fill(m_pm.begin(), m_pm.end(), -1);
}

template <typename Item>
int IndexPriorityQueue<Item>::size() const
{
    return m_size;
}

template <typename Item>
bool IndexPriorityQueue<Item>::empty() const
{
    return m_size == 0;
}

template <typename Item>
bool IndexPriorityQueue<Item>::contains(int k) const
{
    return m_pm[k] == -1;
}

template <typename Item>
void IndexPriorityQueue<Item>::insert(int k, Item item)
{
    m_im[++m_size] = k;
    m_pm[k] = m_size;
    m_data[k] = item;
    swim(m_size);
}

template <typename Item>
void IndexPriorityQueue<Item>::deleteNode(int k)
{
    //exchange with the last item, since last item has no children
    //less link to break
    swap(k, m_size--);
    swap(k, 1);
    sink(1);
    
    //mark the key as invalid
    m_pm[m_im[m_size + 1]] = -1;
}

template <typename Item>
int IndexPriorityQueue<Item>::delMin()
{
    int max = m_im[1];
    
    deleteNode(1);

    return max;
}

template <typename Item>
Item IndexPriorityQueue<Item>::min() const
{
    return m_data[m_im[1]];
}

template <typename Item>
void IndexPriorityQueue<Item>::print() const
{
    for (int i = 1; i <= m_size; i++)
    {
        std::cout << "(" << m_im[i] << ", " << m_data[m_im[i]] << ")" << " ";
    }
    std::cout << "\n";
}

template <typename Item>
bool IndexPriorityQueue<Item>::less(int i, int j) const
{
    int key1 = m_im[i];
    int key2 = m_im[j];

    // since we want the min item, larger item will have lower priorities
    return m_data[key1] >= m_data[key2];
}

template <typename Item>
void IndexPriorityQueue<Item>::swap(int i, int j)
{
    int key1 = m_im[i];
    int key2 = m_im[j];

    std::swap(m_im[i], m_im[j]);
    std::swap(m_pm[key1], m_pm[key2]);
}

template <typename Item>
void IndexPriorityQueue<Item>::swim(int k)
{
    while (k > 1 && less(k / 2, k))
    {
        swap(k / 2, k);
        k = k / 2;
    }
}

template <typename Item>
void IndexPriorityQueue<Item>::sink(int k)
{
    while (2 * k <= m_size)
    {
        int j = 2 * k;

        //choose the larger children to compare with the parent
        if (j < m_size && less(j, j + 1))
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