/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:53:29 by myuen             #+#    #+#             */
/*   Updated: 2026/01/14 20:31:49 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>
void increment(T &x) //non const
{
    x = x + '0';
}

template <typename T>
void printItem(T const &item) // const
{
    std::cout << item << std::endl;
}

int main()
{
    // Test 1: Non-const int array with printItem
    int intArray[] = {1, 2, 3, 4, 5};
    
    std::cout << "Printing int array:" << std::endl;    iter(intArray, 5, printItem);
    std::cout << "Increase int array:" << std::endl;    iter(intArray, 5, increment);
    std::cout << "Printing int array:" << std::endl;    iter(intArray, 5, printItem);
    std::cout << std::endl;

    //Test 2: const int array
    int const c_intArray[] = {-1, -2, -3, -4, -5};
    
    std::cout << "Printing int const array:" << std::endl;  iter(c_intArray, 5, printItem);
    // std::cout << "Increase int const array:" << std::endl;  iter(c_intArray, 5, increment); //method is not marked const error
    // std::cout << "Printing int const array:" << std::endl;  iter(c_intArray, 5, printItem);
    std::cout << std::endl;

    std::string strArray[] = {"hello", "world"};
    std::cout << "Printing string array:" << std::endl;    iter(strArray, 2, printItem);
    std::cout << "Adding to string array:" << std::endl;    iter(strArray, 2, increment);
    std::cout << "Printing string array:" << std::endl;    iter(strArray, 2, printItem);
    std::cout << std::endl;

    std::string const c_strArray[] = {"hello", "world"};
    std::cout << "Printing const string array:" << std::endl;    iter(c_strArray, 2, printItem);
    // std::cout << "Adding to const string array:" << std::endl;    iter(c_strArray, 2, increment); //method is not marked const error
    // std::cout << "Printing const string array:" << std::endl;    iter(c_strArray, 2, printItem);
    std::cout << std::endl;


    return 0;
}
