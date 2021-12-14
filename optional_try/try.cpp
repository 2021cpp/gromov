#include "try.hpp"

template <class T>

Try<T>::Try(): exception(nullptr) {};

template <class T>

Try<T>::Try(const T &val) 
{
    try
    {
        value = val;
    }
    catch(...)
    {
        exception = std::current_exception();
    }
}

template <class T>

Try<T>::Try(T&& val)
{
    try
    {
        value = val;
    }
    catch(...)
    {
        exception = std::current_exception();
    }
}

template<class T>
template<class TException>

Try<T>::Try(const TException& excep) : exception(std::make_exception_ptr(excep)) {};

template <class T>

Try<T>::Try(std::exception_ptr excep): exception(excep) {};

template <class T>

const T& Try<T>::Value() 
{
    if (!Error()) return value;
}

template <class T>

bool Try<T>::Error()
{
    return exception == nullptr;
}
