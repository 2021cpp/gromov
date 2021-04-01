#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp""
#include <iostream>

template <typename T> class Item 
{
    T node; Item* next;
public:
    Item(const T& elem, Item* n = 0) 
    {
        node = elem; next = n;
    }
    
    T& get_node() 
    {
        return node; 
    }
    
    Item*& get_next() 
    {
        return next; 
    }
};

template <typename T> class Queue
{
    Item<T>* head, * tail; T rab;
public:
    Queue() { tail = head = 0; }
    
    bool empty() { return head == 0; }
    
    void put(const T& elem) 
    {
        if (tail == 0) tail = head = new Item<T>(elem);
        else tail = (tail->get_next() = new Item<T>(elem));
    }

    T& get()
    {
        Item<T>* p = head;
        rab = head->get_node();
        head = head->get_next();
        delete p;
        if (head == 0) tail = 0;
        return rab;
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