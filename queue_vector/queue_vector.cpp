#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp""
#include <vector> 
#include <iostream>
template<class T>
class Queue
{
public:
    std::vector<T> d_back, d_front;
    void put(T a)
    {
        d_back.push_back(a);
    }
    void get()
    {
        if (d_front.size() > 0)
        {
            d_front.pop_back();
        }
        else
        {
            d_front = d_back;
            std::vector<T> a;
            d_back = a;
            for (uint32_t i = 0; i < d_front.size() / 2; ++i)
            {
                std::swap(d_front[i], d_front[d_front.size() - i - 1]);
            }
            d_front.pop_back();
        }
    }
    const T& operator[](uint32_t i)
    {
        if (i >= d_front.size())
        {
            return d_back[i - d_front.size()];
        }
        else
        {
            return d_front[d_front.size() - i - 1];
        }
    }
    uint32_t Size()
    {
        return d_back.size() + d_front.size();
    }
};
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