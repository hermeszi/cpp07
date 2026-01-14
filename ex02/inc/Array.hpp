#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>

template <typename T>
class Array
{

private:
    size_t  size_;    
    T       *ptr_;

public:
    explicit Array(unsigned int n = 0);
    Array(Array const & other);
    ~Array();
    Array & operator=(Array const & rhs);
    T & operator[](size_t const index);
    T const & operator[](size_t const index) const;

    size_t size(void) const;
};

#include "Array.tpp"

#endif
