#include "binaryHeap.h"
#include "heapsort.h"

#include <iostream>
#include <ctime>
#include <random>
#include <vector>
#include <string>

template <typename T>
bool checkIncreasing(std::vector<T> vec)
{
    if (vec.empty()) return true;

    T prev = vec[0];
    for (std::size_t i = 1; i < vec.size(); ++i)
    {
        T el = vec[i];
        if (! (el >= prev) )
        {
            return false;
        }
        prev = el;
    }

    return true;
}

int main()
{
    /*srand(time(NULL));
    std::vector<int> vec1;
    for (int i = 0; i < 10; i++)
    {
        vec1.push_back(rand());
    }

    for (auto& x: vec1)
    {
        std::cout << x << " ";
    }
    std::cout << '\n';

    sort<int>(vec1);

    std::string state = checkIncreasing<int>(vec1) ? "Success" : "Fail";
    std::cout << "The State is " << state << "\n";

    for (auto& x: vec1)
    {
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::vector<int> vec2;
    for (int i = 0; i < 10; i++)
    {
        vec2.push_back(rand());
    }

    for (auto& x: vec2)
    {
        std::cout << x << " ";
    }
    std::cout << '\n';

    BinaryHeap<int> tree(vec2);

    std::vector<int> res = tree.sort();

    std::string state2 = checkIncreasing<int>(res) ? "Success" : "Fail";
    std::cout << "The State is " << state2 << "\n";

    for (auto& x: res)
    {
        std::cout << x << " ";
    }*/

    return 0;
}