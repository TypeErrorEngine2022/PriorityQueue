#pragma once

#include <vector>

template <typename Item>
class IndexPriorityQueue
{
public:
    IndexPriorityQueue(int maxN);
                                         
    int size() const; 
    bool empty() const;

    bool contains(int key) const;

    void insert(int k, Item item);

    void deleteNode(int k);

    int delMin();

    Item min() const;

    void print() const;
private:
    std::vector<Item> m_data; //m_data[1] gives the item (with priorities) for key 1
    std::vector<int> m_im; //inverse map, the binary heap, m_im[1] gives the key for node 1
    std::vector<int> m_pm; //position map, m_pm[1] gives the node number for key 1
    
    int m_size;

    /**
     * @brief Compare the priorities two items in binary heap
     * 
     * @param i the index for node
     * @param j the index for node
     * @return true if the first is smaller than or equal to the second
     */
    bool less(int i, int j) const;

    /**
     * @brief swap two nodes, update both m_im and m_pm
     * 
     * @param i 
     * @param j 
     */
    void swap(int i, int j);

    /**
     * @brief swap m_im[ k ] with its parent until the heap order is restored
     * 
     * @param k 
     */
    void swim(int k);

    /**
     * @brief swap m_im[ k ] with its children until the heap order is restored
     * 
     * @param k 
     */
    void sink(int k);
};

#include "IndexPriorityQueue.tpp"