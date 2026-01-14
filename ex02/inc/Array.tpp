/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:53:29 by myuen             #+#    #+#             */
/*   Updated: 2026/01/14 22:10:43 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <stdexcept>

template <typename T> Array<T>::Array(unsigned int n) : size_(n), ptr_(new T[size_]){}
template <typename T> Array<T>::~Array(){delete [] ptr_;}
template <typename T> Array<T>::Array(Array const & rhs) : size_(rhs.size_), ptr_(new T[size_])
{
    for (size_t i = 0; i < this->size_; ++i)
    {
        this->ptr_[i] = rhs.ptr_[i];
    }
}
template <typename T> Array<T> & Array<T>::operator=(Array const & rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    
    delete [] this->ptr_;
    this->size_ = rhs.size_;
    ptr_ = new T[this->size_];
    for (size_t i = 0; i < this->size_; ++i)
    {
        this->ptr_[i] = rhs.ptr_[i];
    }
    return *this;    
}

template <typename T> T & Array<T>::operator[](size_t index)
{
    if (index < size_)
        return ptr_[index];
    else
        throw std::out_of_range("Index out of bounds");   
}

template <typename T> T const & Array<T>::operator[](size_t index) const
{
    if (index < size_)
        return ptr_[index];
    else
        throw std::out_of_range("Index out of bounds");   
}

template <typename T> size_t Array<T>::size() const{return this->size_;}
