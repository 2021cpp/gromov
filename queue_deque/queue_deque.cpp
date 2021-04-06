#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp"
#include <iostream>
#include "deque.cpp"
template<class T>

class Queue {
public:
    Deque <T> deq;

    void PushBack(const T& el) {
        deq.Push_Back(el);
    }

    const T& operator[](size_t i) {
        return deq[i];
    }

    size_t Size() const {
        return deq.Size();
    }



    void PopFront() {
        deq.Pop_Front();
    }
};


TEST_CASE("Создание и заполнение очереди")
{
    Queue<int32_t> test;
    size_t i;

    for (i = 0; i < 3; i++)
    {
        test.PushBack(i);
    }

    REQUIRE(test[0] == 0);
    REQUIRE(test[1] == 1);
    REQUIRE(test[2] == 2);

    test.PopFront();

    REQUIRE(test[0] == 1);
    REQUIRE(test[1] == 2);
}

TEST_CASE("Benchmark") {
    BENCHMARK("Plus 1000, minus 1000")
    {
        Queue<int32_t> test;
        for (size_t i = 0; i < 1000; ++i)
        {
            test.PushBack(i);
        }
        for (size_t i = 0; i < 1000; ++i)
        {
            test.PopFront();
        }
    };
    BENCHMARK("Plus 100 000, minus 100 000")
    {
        Queue<int32_t> test;
        for (size_t i = 0; i < 100000; ++i)
        {
            test.PushBack(i);
        }
        for (size_t i = 0; i < 100000; ++i)
        {
            test.PopFront();
        }
    };
    BENCHMARK("Plus 10 000 000, minus 10 000 000")
    {
        Queue<int32_t> test;
        for (size_t i = 0; i < 10000000; ++i)
        {
            test.PushBack(i);
        }
        for (size_t i = 0; i < 10000000; ++i)
        {
            test.PopFront();
        }
    };
}