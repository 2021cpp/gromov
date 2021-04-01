#include<iostream>

class String
{
public:
    String() : sz(0), mem_sz(16)
    {
        m_str = new char[mem_sz];
    }

    void PushBack(const char& elem)
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

    ~String()
    {
        delete[] m_str;
    }

    String(String&& outer)
    {
        sz = outer.sz;
        mem_sz = outer.mem_sz;
        m_str = outer.m_str;

        outer.sz = 0;
        outer.mem_sz = 0;
        outer.m_str = nullptr;
    }

    int32_t Length()
    {
        return sz;
    }

    const char& operator[](uint32_t i) const
    {
        return m_str[i];
    }

    String& operator=(String&& outer)
    {
        String eq(std::move(outer));
        std::swap(sz, eq.sz);
        std::swap(mem_sz, eq.mem_sz);
        std::swap(m_str, eq.m_str);
        return eq;
    }

    String& operator=(const String& outer)
    {
        String eq(outer);
        std::swap(sz, eq.sz);
        std::swap(mem_sz, eq.mem_sz);
        std::swap(m_str, eq.m_str);
        return eq;
    }

    String(const String& outer) : sz(outer.sz), mem_sz(outer.sz)
    {
        m_str = new char[mem_sz];
        for (int32_t i = 0; i < mem_sz; i++)
        {
            m_str[i] = outer.m_str[i];
        }
    }

    void operator()(const char* s)
    {
        this->mem_sz = 16;
        this->sz = 0;
        this->m_str = new char[mem_sz];
        for (int32_t i = 0; i < strlen(s); i++)
        {
            this->PushBack(s[i]);
        }
    }

    void operator=(const char* s)
    {
        this->mem_sz = 16;
        this->sz = 0;
        this->m_str = new char[mem_sz];
        for (int32_t i = 0; i < strlen(s); i++)
        {
            this->PushBack(s[i]);
        }
    }

    const char* BeginV()
    {
        return m_str;
    }

    const char* EndV()
    {
        return (m_str + sz - 1);
    }

    void get_line()
    {
        char a = '0';
        while (a != '\n')
        {
            a = getchar();
            this->PushBack(a);
        }
        this->PopBack();
    }

    void print()
    {
        for (int32_t i = 0; i < this->sz; ++i)
        {
            std::cout << this->m_str[i];
        }
    }

    String operator+(String& s1)
    {
        String str;
        str.mem_sz = this->mem_sz + s1.mem_sz;
        str.sz = this->sz + s1.sz;
        for (int32_t i = 0; i < this->sz; ++i)
        {
            str.m_str[i] = this->m_str[i];
        }
        for (int32_t i = 0; i < s1.sz; ++i)
        {
            str.m_str[i + this->sz] = s1.m_str[i];
        }

        return str;
    }

    void operator+=(String& s1)
    {
        for (int32_t i = 0; i < s1.sz; ++i)
        {
            this->PushBack(s1.m_str[i]);
        }
    }



private:
    int32_t sz, mem_sz;
    char* m_str;

    void Double_Memory()
    {
        char* new_m_str = new char[2 * mem_sz];
        for (int32_t i = 0; i < mem_sz; i++)
        {
            new_m_str[i] = m_str[i];
        }
        m_str = new_m_str;
    }
};