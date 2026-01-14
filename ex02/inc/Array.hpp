#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{

private:
    T       *ptr;
    size_t  len;    

public:
    explicit Array(unsigned int n = 0);
    Array(Array const & other);
    ~Array();
    Array & operator=(Array const & rhs);

};

#endif
