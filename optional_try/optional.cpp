#include "optional.hpp"

template<class T>

Optional<T>::Optional(): empty(true) {}

template<class T>

Optional<T>::Optional(const T& val): value(val), empty(false) {}

template<class T>

Optional<T>::Optional(const Optional<T>& other): value(other.value), empty(false)
{
    if(!other.empty)
    {
        value = other.value;
        empty = false;

        other.value = nullptr;
        other.empty = true;
    }

    else empty = true;
}

template<class T>

Optional<T>::Optional(Optional<T>&& other)
{
    if(!other.empty)
    {
        *this = std::move(other);
    }
    
    else empty = true;
}

template<class T>

Optional<T>& Optional<T>::operator=(const Optional<T>& other)
{
    if(!other.empty)
    {
        if(this == &other) return *this;
        value = other.value;
        empty = false;
        return *this;
    }

    else
    {
        empty = true;
        return *this;
    }
}

template<class T>

Optional<T>& Optional<T>::operator=(Optional<T>&& other)
{
    if(!other.empty)
    {
        if(this == &other) return *this;
        *this = std::move(other);
        return *this;
    }

    else
    {
        empty = true;
        return *this;
    }
}

template<class T>

bool Optional<T>::Empty()
{
    return empty;
}

template<class T>

T& Optional<T>::Value()
{
    if(empty)
        throw std::runtime_error("There is no value :'(");
    return value;
}

template<class T>

T& Optional<T>::ValueOr(const T& another_val)
{
    if(!empty) return value;
    else return another_val;
}
