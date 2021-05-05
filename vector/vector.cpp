#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "vector.h"

TEST_CASE("Создание и заполнение вектора")
{
    Vector<int32_t> test;
    size_t i;

    for (i = 0; i < 3; i++)
    {
        test.PushBack(i);
    }

    REQUIRE(test[0] == 0);
    REQUIRE(test[1] == 1);
    REQUIRE(test[2] == 2);

    test.PopBack();

    REQUIRE(test[0] == 0);
    REQUIRE(test[1] == 1);
}

TEST_CASE("Размер вектора")
{
    Vector<int32_t> test;
    size_t i;

    for (i = 0; i < 3; i++)
    {
        test.PushBack(i);
    }

    REQUIRE(test.Size() == 3);
}

TEST_CASE("Копирование веторов") {
    Vector<int32_t> test;
    size_t i;

    for (i = 0; i < 3; i++)
    {
        test.PushBack(i);
    }

    Vector<int32_t> another_test;
    another_test = test;

    REQUIRE(another_test[0] == 0);
    REQUIRE(another_test[1] == 1);
    REQUIRE(another_test[2] == 2);
    REQUIRE(another_test.Size() == 3);
}

TEST_CASE("Перемещение векторов") {
    Vector<int32_t> test;
    size_t i;

    for (i = 0; i < 3; i++)
    {
        test.PushBack(i);
    }

    Vector<int32_t> move_test(std::move(test));
    REQUIRE(move_test[0] == 0);
    REQUIRE(move_test[1] == 1);
    REQUIRE(move_test[2] == 2);
    REQUIRE(move_test.Size() == 3);

    Vector<int32_t> another_test;
    another_test = std::move(move_test);
    REQUIRE(another_test[0] == 0);
    REQUIRE(another_test[1] == 1);
    REQUIRE(another_test[2] == 2);
    REQUIRE(another_test.Size() == 3);
}