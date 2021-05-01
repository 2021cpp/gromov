#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING

#include "catch.hpp"
#include "HeapSort.h"

TEST_CASE("Benchmark for QuickHeapSort")
{
    BENCHMARK("Sort 1000 random")
    {
        std::vector<int> a;
        for (int i = 0; i < 1000; i++)
        {
            a.push_back(std::rand() / ((RAND_MAX + 1u) / 1000));
        }
        HeapSort(a.begin(), a.end() - 1);
    };
    BENCHMARK("Sort 1000 sorted")
    {
        std::vector<int> a;
        for (int i = 0; i < 1000; i++)
        {
            a.push_back(i);
        }
        HeapSort(a.begin(), a.end() - 1);
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
        HeapSort(a.begin(), a.end() - 1);
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
        HeapSort(a.begin(), a.end() - 1);
    };
}