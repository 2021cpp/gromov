// MergeSort.cpp: определяет точку входа для приложения.
//

#include "MergeSort.h"

template < class iterator >

void Merge_Sort(iterator a, int n) {
    if (n == 1) { return; }
    int mid = (n + 0) / 2;
    Merge_Sort(a, mid);
    Merge_Sort(a + mid, n - mid);
    int* new_stor = new int[n];
    int cur1 = 0;
    int cur2 = mid;
    for (int i = 0; i < n; ++i) {
        if (cur2 >= n || cur1 < mid && *(a + cur1) <= *(a + cur2)) {
            new_stor[i] = *(a + cur1);
            cur1 += 1;
        }
        else {
            new_stor[i] = *(a + cur2);
            cur2 += 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        *(a + i) = new_stor[i];
    }
    delete[] new_stor;
}


TEST_CASE("Benchmark for Merge_Sort")
{
    BENCHMARK("Sort 1000 random")
    {
        std::vector<int> a;
        for (int i = 0; i < 1000; i++)
        {
            a.push_back(std::rand() / ((RAND_MAX + 1) / 1000));
        }
        Merge_Sort(a.begin(), 1000);
    };
    BENCHMARK("Sort 1000 sorted")
    {
        std::vector<int> a;
        for (int i = 0; i < 1000; i++)
        {
            a.push_back(i);
        }
        Merge_Sort(a.begin(), 1000);
    };
    BENCHMARK("Sort 1000 almost sorted")
    {
        std::vector<int> a;
        for (int i = 0; i < 600; i++)
        {
            a.push_back(i);
        }
        for (int i = 0; i < 400; i++)
        {
            a.push_back(std::rand() / ((RAND_MAX + 1) / 1000));
        }
        Merge_Sort(a.begin(), 1000);
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
        Merge_Sort(a.begin(), 1000);
    };
}
