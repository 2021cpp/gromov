#define CATCH_CONFIG_MAIN
#include "deque.h"
#include "catch.hpp"

TEST_CASE("Ñîçäàíèå è çàïîëíåíèå äåêà")
{
    Deque<int32_t> test;
    size_t i;

    for (i = 0; i < 3; i++)
    {
        test.Push_Back(i);
    }

    REQUIRE(test[0] == 0);
    REQUIRE(test[1] == 1);
    REQUIRE(test[2] == 2);

    test.Pop_Back();

    REQUIRE(test[0] == 0);
    REQUIRE(test[1] == 1);

    test.Pop_Front();

    REQUIRE(test[0] == 1);

    test.Push_Front(5);
    REQUIRE(test[0] == 5);
    REQUIRE(test[1] == 1);
}

TEST_CASE("size of deque")
{
    Deque<int32_t> test;
    size_t i;

    for (i = 0; i < 3; i++)
    {
        test.Push_Back(i);
    }

    REQUIRE(test.Size() == 3);
}

TEST_CASE("Êîïèðîâàíèå deque") {
    Deque<int32_t> test;
    size_t i;

    for (i = 0; i < 3; i++)
    {
        test.Push_Back(i);
    }

    Deque<int32_t> another_test;
    another_test = test;

    REQUIRE(another_test[0] == 0);
    REQUIRE(another_test[1] == 1);
    REQUIRE(another_test[2] == 2);
    REQUIRE(another_test.Size() == 3);
}

TEST_CASE("Ïåðåìåùåíèå deque") {
    Deque<int32_t> test;
    size_t i;

    for (i = 0; i < 3; i++)
    {
        test.Push_Back(i);
    }

    Deque<int32_t> move_test(std::move(test));
    REQUIRE(move_test[0] == 0);
    REQUIRE(move_test[1] == 1);
    REQUIRE(move_test[2] == 2);
    REQUIRE(move_test.Size() == 3);

    Deque<int32_t> another_test;
    another_test = std::move(move_test);
    REQUIRE(another_test[0] == 0);
    REQUIRE(another_test[1] == 1);
    REQUIRE(another_test[2] == 2);
    REQUIRE(another_test.Size() == 3);
}