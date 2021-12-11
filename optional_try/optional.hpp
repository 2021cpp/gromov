#pragma once

#include<iostream>

template<class T>

class Optional
{
private:
    T value;
    bool empty;

public:
	bool Empty();

    Optional();
    Optional(const T& t);
    Optional(const Optional<T>& other);
    Optional(Optional<T>&& other);

	T& Value();
    T& ValueOr(const T& t);

    Optional& operator=(const Optional<T>& other);
    Optional& operator=(Optional<T>&& other);

	~Optional() = default;
};
