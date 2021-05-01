// MergeSort.cpp: определяет точку входа для приложения.
//
#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING

#include "catch.hpp"
#include "MergeSort.h"

TEST_CASE("Benchmark for MergeSort")
{
    BENCHMARK("Sort 1000 random")
    {
        std::vector<int> a;
        for (int i = 0; i < 1000; i++)
        {
            a.push_back(std::rand() / ((RAND_MAX + 1) / 1000));
        }
        MergeSort(a.begin(), 1000);
    };
    BENCHMARK("Sort 1000 sorted")
    {
        std::vector<int> a;
        for (int i = 0; i < 1000; i++)
        {
            a.push_back(i);
        }
        MergeSort(a.begin(), 1000);
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
        MergeSort(a.begin(), 1000);
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
        MergeSort(a.begin(), 1000);
    };
}
