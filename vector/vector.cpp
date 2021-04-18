#define CATCH_CONFIG_MAIN
#include "catch.hpp"


template<class T>
class Vector
{
public:
    Vector() : sz(0), mem_sz(16)
    {
        m_str = new T[mem_sz];
    }

    void PushBack(const T& elem)
    {
        if (sz >= mem_sz)
        {
            Double_Memory();
        }
        m_str[sz] = elem;
        sz++;
    }

    void PopBack()
    {
        if (sz == 0)
        {
            std::cout << "Нельзя удалить элемент из пустого вектора";
        }
        else
        {
            sz--;
        }
    }

    ~Vector()
    {
        delete[] m_str;
    }

    Vector(Vector&& outer)
    {
        sz = outer.sz;
        mem_sz = outer.mem_sz;
        m_str = outer.m_str;

        outer.sz = 0;
        outer.mem_sz = 0;
        outer.m_str = nullptr;
    }

    uint32_t Size()
    {
        return sz;
    }

    const T& operator[](int32_t i) const
    {
        return m_str[i];
    }

    Vector& operator=(Vector&& outer)
    {
        Vector eq(std::move(outer));
        std::swap(sz, eq.sz);
        std::swap(mem_sz, eq.mem_sz);
        std::swap(m_str, eq.m_str);
        return eq;
    }

    Vector& operator=(const Vector& outer)
    {
        Vector eq(outer);
        std::swap(sz, eq.sz);
        std::swap(mem_sz, eq.mem_sz);
        std::swap(m_str, eq.m_str);
        return eq;
    }

    Vector(const Vector& outer) : sz(outer.sz), mem_sz(outer.sz)
    {
        m_str = new T[mem_sz];
        for (int32_t i = 0; i < mem_sz; i++)
        {
            m_str[i] = outer.m_str[i];
        }
    }

    const T* BeginV()
    {
        return m_str;
    }

    const T* EndV()
    {
        return (m_str + sz - 1);
    }

private:
    int32_t sz, mem_sz;
    T* m_str;

    void Double_Memory()
    {
        T* new_m_str = new T[2 * mem_sz];
        for (int32_t i = 0; i < mem_sz; i++)
        {
            new_m_str[i] = m_str[i];
        }
        m_str = new_m_str;
    }
};


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