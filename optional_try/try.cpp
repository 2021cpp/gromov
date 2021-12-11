#include "try.hpp"

template<class T>

Try<T>::Try() : error(false)
{
    try
    {
        value = T();
    } 
    catch (...)
    {
        error = true;
        exception = std::current_exception();
    }
};

template<class T>

Try<T>::Try(const T& val) : error(false)
{
    try
    {
        value = val;
    } 
    catch (...)
    {
        error = true;
        exception = std::current_exception();
    }
};

template<class T>

Try<T>::Try(T&& val)
{
    try
    {
        value = val;
    } 
    catch (...)
    {
        error = true;
        exception = std::current_exception();
    }
};

template<class T>
template<class TException>

Try<T>::Try(const TException& excep) : error(true), exception(std::make_exception_ptr(excep)) {};

template<class T>

Try<T>::Try(std::exception_ptr excep) : error(true), exception(excep) {};

template<class T>

T Try<T>::Value()
{
    if (Error())
    {
        std::rethrow_exception(exception);
    }
    return value;
};

template<class T>

bool Try<T>::Error()
{
    return error;
};
