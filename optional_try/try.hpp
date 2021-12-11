#pragma once

#include <exception>

template<class T>

class Try
{
private:
    bool error;
    T value;
    std::exception_ptr exception;

public:
    Try();
    Try(const T&);
    Try(T&&);

    template<class TException>
    Try(const TException&);
    Try(std::exception_ptr);

    T Value();
    bool Error();

    ~Try() = default;
};