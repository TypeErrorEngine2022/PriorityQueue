#pragma once

#include <vector>

template <typename T>
bool less(std::vector<T>& vec, int i, int j)
{
    return vec[i] <= vec[j];
}

template <typename T>
void swap(std::vector<T>& vec, int i, int j)
{
    std::swap(vec[i], vec[j]);
}

template <typename T>
void sink(std::vector<T>& vec, int i, int size)
{
    while (2 * i + 1 <= size)
    {
        int j  = 2 * i + 1;

        if (j + 1 <= size && less(vec, j, j + 1))
        {
            ++j;
        }
        if (!less(vec, i, j))
        {
            break;
        }
        swap(vec, i , j);
        i  = j;
    }
}

template <typename T>
void sort(std::vector<T>& vec)
{
    int size = vec.size();

    //size / 2 + 1, size / 2 + 2, ... , size are all leaves
    //leaves are already a max-heap
    for (int i = size / 2; i >= 0; i--)
    {
        sink<T>(vec, i, size);
    }

    while (size > 0)
    {
        swap<T>(vec, 0, size--);
        sink<T>(vec, 0, size);
    }
}