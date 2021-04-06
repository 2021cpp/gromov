#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"

template <class T>
class Deque {
private:
    void expand() {
        size_t new_sz = 2 * m_memsz;
        T** new_stor = new T * [new_sz];
        for (size_t i = 0; i < new_sz; ++i) {
            T* new_block = new T[b_sz];
            new_stor[i] = new_block;

            if (i * b_sz < m_sz) {
                for (size_t j = 0; j < b_sz; ++j) {
                    int32_t k = index(i * b_sz + j);

                    new_stor[i][j] = m_stor[k / b_sz][k % b_sz];
                }
            }
        }

        offset = 0;
        std::swap(new_stor, m_stor);
        std::swap(new_sz, m_memsz);

        for (size_t i = 0; i < new_sz; ++i) {
            delete[] new_stor[i];
        }
        delete[] new_stor;
    }

    size_t index(size_t i) {
        int32_t j = i + offset;
        if (j < 0) {
            return (j + b_sz * m_memsz);
        }
        if (j >= b_sz * m_memsz) {
            return (j - b_sz * m_memsz);
        }

        return static_cast<size_t>(j);
    }

    T** m_stor;
    size_t m_sz, m_memsz;
    int32_t offset;
    const size_t b_sz = 16;
public:
    Deque() : offset(0), m_sz(0), m_memsz(16) {
        m_stor = new T * [m_memsz];
        for (size_t i = 0; i < m_memsz; i++) {
            m_stor[i] = new T[b_sz];
        }
    }

    size_t Size() {
        return m_sz;
    }

    void Push_Back(const T& el) {
        if (m_sz == b_sz * m_memsz) {
            expand();
        }
        size_t i = index(m_sz);

        m_stor[i / b_sz][i % b_sz] = el;
        m_sz++;
    }

    void Pop_Back() {
        m_sz--;
    }

    T& Back() {
        size_t i = index(m_sz - 1);

        return m_stor[i / b_sz][i % b_sz];
    }

    const T& Back() const {
        size_t i = index(m_sz - 1);

        return m_stor[i / b_sz][i % b_sz];
    }

    void Push_Front(const T& el) {
        if (m_sz == b_sz * m_memsz) {
            expand();
        }

        size_t i = index(-1);

        m_stor[i / b_sz][i % b_sz] = el;
        m_sz++;
        offset--;
    }

    void Pop_Front() {
        m_sz--;
        offset++;
    }

    T& Front() {
        size_t i = index(0);

        return m_stor[i / b_sz][i % b_sz];
    }

    const T& Front() const {
        size_t i = index(0);

        return m_stor[i / b_sz][i % b_sz];
    }

    T* Begin() {
        size_t i = index(0);
        return m_stor[i / b_sz] + (i % b_sz);
    };

    T* End() {
        size_t i = index(m_sz);
        return m_stor[i / b_sz] + (i % b_sz);
    }

    T& operator[](size_t i) {
        size_t j = index(i);
        return m_stor[j / b_sz][j % b_sz];
    }

    const T& operator[](size_t i) const {
        size_t j = index(i);
        return m_stor[j / b_sz][j % b_sz];
    }

    ~Deque() {
        for (size_t i = 0; i < m_memsz; ++i) {
            delete[] m_stor[i];
        }
        delete[] m_stor;
    }

    Deque& operator= (Deque<T>&& rhs) {
        if (this == &rhs) return *this;
        Deque<T> t(std::move(rhs));

        std::swap(m_sz, t.m_sz);
        std::swap(m_stor, t.m_stor);
        std::swap(m_memsz, t.m_memsz);
        std::swap(offset, t.offset);

        return *this;
    }

    Deque& operator= (const Deque<T>& rhs) {
        if (this == &rhs) return *this;
        Deque<T> t(rhs);

        std::swap(m_sz, t.m_sz);
        std::swap(m_stor, t.m_stor);
        std::swap(m_memsz, t.m_memsz);
        std::swap(offset, t.offset);

        return *this;
    }

    Deque(Deque<T>&& rhs) {
        m_sz = rhs.m_sz;
        m_memsz = rhs.m_memsz;
        m_stor = rhs.m_stor;
        offset = rhs.offset;

        rhs.m_sz = 0;
        rhs.m_memsz = 0;
        rhs.m_stor = nullptr;
        rhs.offset = 0;
    }

    Deque(const Deque<T>& rhs) : m_sz(rhs.m_sz), m_memsz(rhs.m_memsz), offset(rhs.offset) {
        m_stor = new T * [m_memsz];
        for (size_t i = 0; i < m_memsz; ++i) {
            m_stor[i] = new T[b_sz];
            for (size_t j = 0; j < b_sz; j++) {
                m_stor[i][j] = rhs.m_stor[i][j];
            }
        }
    }
};