// vector.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

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

#endif //VECTOR_H

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
