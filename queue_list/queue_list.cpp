#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp"
#include "queue_list.h"

TEST_CASE("Benchmark") {
    BENCHMARK("Plus 1000, minus 1000")
    {
        Queue<int32_t> test;
        for (size_t i = 0; i < 1000; ++i)
        {
            test.put(i);
        }
        for (size_t i = 0; i < 1000; ++i)
        {
            test.get();
        }
    };
    BENCHMARK("Plus 100 000, minus 100 000")
    {
        Queue<int32_t> test;
        for (size_t i = 0; i < 100000; ++i)
        {
            test.put(i);
        }
        for (size_t i = 0; i < 100000; ++i)
        {
            test.get();
        }
    };
    BENCHMARK("Plus 10 000 000, minus 10 000 000")
    {
        Queue<int32_t> test;
        for (size_t i = 0; i < 10000000; ++i)
        {
            test.put(i);
        }
        for (size_t i = 0; i < 10000000; ++i)
        {
            test.get();
        }
    };
}