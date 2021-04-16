#include "HeapSort.h"

template< class RandomIt >
void SiftDown(RandomIt b, int root, int bottom)
{
    int maxChild;
    int done = 0;
    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)
        {
            maxChild = root * 2;
        }
        else
        {
            if (*(b + root * 2) > * (b + root * 2 + 1))
            {
                maxChild = root * 2;
            }
            else
            {
                maxChild = root * 2 + 1;
            }
        }
        if (*(b + root) < *(b + maxChild))
        {
            std::swap(*(b + root), *(b + maxChild));
            root = maxChild;
        }
        else
        {
            done = 1;
        }
    }
}

template< class RandomIt >
void Sort(RandomIt b, RandomIt e)
{
    for (int i = (e - b) / 2; i >= 0; i--)
    {
        SiftDown(b, i, (e - b) - 1);
    }
    for (int i = (e - b) - 1; i >= 1; i--)
    {
        std::swap(*b, *(b + i));
        SiftDown(b, 0, i - 1);
    }
}


TEST_CASE("Benchmark for QuickSort")
{
    BENCHMARK("Sort 1000 random")
    {
        std::vector<int> a;
        for (int i = 0; i < 1000; i++)
        {
            a.push_back(std::rand() / ((RAND_MAX + 1u) / 1000));
        }
        Sort(a.begin(), a.end() - 1);
    };
    BENCHMARK("Sort 1000 sorted")
    {
        std::vector<int> a;
        for (int i = 0; i < 1000; i++)
        {
            a.push_back(i);
        }
        Sort(a.begin(), a.end() - 1);
    };
    BENCHMARK("Sort 1000 almost sorted")
    {
        std::vector<int> a;
        for (int i = 0; i < 950; i++)
        {
            a.push_back(i);
        }
        for (int i = 0; i < 50; i++)
        {
            a.push_back(std::rand() / ((RAND_MAX + 1u) / 1000));
        }
        Sort(a.begin(), a.end() - 1);
    };
    BENCHMARK("Sort 1000 with lots equal")
    {
        std::vector<int> a;
        for (int i = 0; i < 950; i++)
        {
            a.push_back(1000);
        }
        for (int i = 0; i < 50; i++)
        {
            a.push_back(std::rand() / ((RAND_MAX + 1u) / 1000));
        }
        Sort(a.begin(), a.end() - 1);
    };
}

