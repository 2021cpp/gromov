#pragma once

#include <map>
#include <string>
#include <functional>

template <class T>

class Factory
{
private:
    std::map<std::string, std::function<T*()>> products;

    Factory() = default;
    Factory(const Factory&) = delete;
    Factory(Factory&&) = delete;

    static Factory& Get()
    {
        static Factory inst;
        return inst;
    }

    Factory& operator=(const Factory&) = delete;
    Factory& operator=(Factory&&) = delete;

public:
    static T* Make(const std::string& product)
    {
        return Get().products[product]();
    };

    static bool Register(const std::string& product, std::function<T*()> a)
    {
        Get().products[product] = a;
        return true;
    };
};