#pragma once

#include <vector>

template <typename Key>
class BinaryHeap
{
public:
    BinaryHeap(int maxN);
    BinaryHeap(std::vector<Key> nums);

    int size() const; 
    bool empty() const;

    void insert(Key k);

    Key delMax();

    std::vector<Key> sort();

    void print() const;
private:
    std::vector<Key> data;
    int m_size;

    /**
     * @brief Compare data[ i ] and data[ j ]
     * 
     * @param i 
     * @param j 
     * @return true if data[ i ] is smaller than or equal to data[ j ]
     */
    bool less(int i, int j) const;

    /**
     * @brief swap contents in data[ i ] and data[ j ]
     * 
     * @param i 
     * @param j 
     */
    void swap(int i, int j);

    /**
     * @brief swap data[ k ] with its parent until the heap order is restored
     * 
     * @param k 
     */
    void swim(int k);

    /**
     * @brief swap data[ k ] with its children until the heap order is restored
     * 
     * @param k 
     */
    void sink(int k);
};

#include "binaryHeap.tpp"