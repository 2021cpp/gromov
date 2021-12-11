#include "optional.hpp"

template<class T>

Optional<T>::Optional(): empty(true) {}

template<class T>

Optional<T>::Optional(const T& val) : value(val), empty(false) {}

template<class T>

Optional<T>::Optional(const Optional<T>& other)
{
    value = other.value;
    empty = other.empty;
}

template<class T>

Optional<T>& Optional<T>::operator=(const Optional<T>& other)
{
    if(this == &other) return *this;
    Optional copy(other);
    value = copy.value;
    empty = copy.empty;
    return *this;
}

template<class T>

Optional<T>& Optional<T>::operator=(Optional<T>&& other)
{
    if(this == &other) return *this;
    Optional copy(std::move(other));

    std::swap(value, copy.value);
    std::swap(empty, copy.emp);
    return *this;
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
        throw "There is no value :'(";
    return value;
}

template<class T>

T& Optional<T>::ValueOr(const T& another_val)
{
    if(!empty) return value;
    else return another_val;
}
