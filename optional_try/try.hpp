#pragma once

#include <iostream>
#include <exception>

template <class T>

class Try
{
private:
    T value;
    std::exception_ptr exception;

public:
    Try();
    Try(const T&);
    Try(T&&);

    template <class TException>
    Try(const TException&);
    Try(std::exception_ptr);

    const T& Value();
    bool Error();

    ~Try() = default;
};