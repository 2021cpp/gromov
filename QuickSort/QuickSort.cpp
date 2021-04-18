#include "QuickSort.h"

template< class iterator >

void Quick_Sort(iterator a, int n)
{
    int mid = (n + 1) / 2;
    int right_pos = 0;
    std::swap(*a, *(a + mid - 1));
    for (int i = 0; i < n; ++i) {
        if (*(a + i) < *a) {
            std::swap(*(a + right_pos + 1), *(a + i));
            right_pos += 1;
        }
    }
    std::swap(*(a + right_pos), *a);
    if (right_pos > 0)
        Quick_Sort(a, right_pos);
    if (right_pos < n - 1)
        Quick_Sort(a + right_pos + 1, n - right_pos - 1);
    return;
}


TEST_CASE("Benchmark for QuickSort")
{
    BENCHMARK("Sort 1000 random")
    {
        std::vector<int> a;
        for (int i = 0; i < 1000; i++)
        {
            a.push_back(std::rand() / ((RAND_MAX + 1) / 1000));
        }
        Quick_Sort(a.begin(), 1000);
    };
    BENCHMARK("Sort 1000 sorted")
    {
        std::vector<int> a;
        for (int i = 0; i < 1000; i++)
        {
            a.push_back(i);
        }
        Quick_Sort(a.begin(), 1000);
    };
    BENCHMARK("Sort 1000 almost sorted")
    {
        std::vector<int> a;
        for (int i = 0; i < 500; i++)
        {
            a.push_back(i);
        }
        for (int i = 0; i < 500; i++)
        {
            a.push_back(std::rand() / ((RAND_MAX + 1) / 1000));
        }
        Quick_Sort(a.begin(), 1000);
    };
    BENCHMARK("Sort 1000 with lots equal")
    {
        std::vector<int> a;
        for (int i = 0; i < 500; i++)
        {
            a.push_back(777);
        }
        for (int i = 0; i < 500; i++)
        {
            a.push_back(std::rand() / ((RAND_MAX + 1) / 1000));
        }
        Quick_Sort(a.begin(), 1000);
    };
}
