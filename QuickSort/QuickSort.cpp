#include "QuickSort.h"

template< class RandomIt >
void QuickSort(RandomIt left, RandomIt right)
{
    RandomIt i = left, j = right;
    int64_t size = right - left;

    while (i <= j)
    {
        while (*i < *(left + size / 2))
        {
            i++;
        }
        while (*j > *(left + size / 2))
        {
            j--;
        }

        if (i <= j)
        {
            if (*i > *j)
            {
                std::swap(*i, *j);
            }

            if (j - left > 0)
            {
                j--;
            }
            if (right - i > 0)
            {
                i++;
            }
        }

    }

    if (left < j) QuickSort(left, j);
    if (i < right) QuickSort(i, right);
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
        QuickSort(a.begin(), a.end() - 1);
    };
    BENCHMARK("Sort 1000 sorted")
    {
        std::vector<int> a;
        for (int i = 0; i < 1000; i++)
        {
            a.push_back(i);
        }
        QuickSort(a.begin(), a.end() - 1);
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
        QuickSort(a.begin(), a.end() - 1);
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
        QuickSort(a.begin(), a.end() - 1);
    };
}
