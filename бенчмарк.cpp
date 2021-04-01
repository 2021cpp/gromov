#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp""
#include <vector> 
#include <iostream> 

template <class T>
using TVector = std::vector<T>;

TEST_CASE("Benchmark") {
    BENCHMARK("Plus 1000, minus 1000") 
    {
        TVector<int32_t> test;

        for (size_t i = 0; i < 1000; ++i) 
        {
            test.push_back(i);
        }
        for (size_t i = 0; i < 1000; ++i) 
        {
            test.pop_back();
        }
        return test.size();
    };

    BENCHMARK("Plus 100 000, minus 100 000") 
    {
        TVector<int32_t> test;

        for (size_t i = 0; i < 100000; ++i) 
        {
            test.push_back(i);
        }
        for (size_t i = 0; i < 100000; ++i) 
        {
            test.pop_back();
        }
        return test.size();
    };

    BENCHMARK("Plus 10 000 000, minus 10 000 000") 
    {
        TVector<int32_t> test;

        for (size_t i = 0; i < 10000000; ++i) 
        {
            test.push_back(i);
        }
        for (size_t i = 0; i < 10000000; ++i) 
        {
            test.pop_back();
        }
        return test.size();
    };
}