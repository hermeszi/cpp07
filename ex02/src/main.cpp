
//----------------------------SUPPLIED_TEST----------------------------

#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>  // For time
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}


//----------------------------My_Test----------------------------


// #include <iostream>
// #include <string>
// #include "Array.hpp"

// void printSeparator(std::string title)
// {
//     std::cout << "\n--- " << title << " ---" << std::endl;
// }

// int main()
// {
//     // ========== Section 1: Basic Construction ==========
//     printSeparator("Basic Construction");
//     {
//         Array<int> empty;
//         std::cout << "Empty array size: " << empty.size() << std::endl;

//         Array<int> five(5);
//         std::cout << "Array of 5 size: " << five.size() << std::endl;
//     }

//     // ========== Section 3: Assignment Operator ==========
//     printSeparator("Assignment Operator");
//     {
//         Array<int> original(3);
//         original[0] = 10;
//         original[1] = 20;
//         original[2] = 30;
        
//         Array<int> another(5);
//         another = original;

//         std::cout << "Another size after assignment: " << another.size() << " (expected 3)" << std::endl;
        
//         another[0] = 999;
//         std::cout << "Original[0]: " << original[0] << " (Deep copy if 10)" << std::endl;
//         std::cout << "Another[0]: " << another[0] << " (Should be 999)" << std::endl;
//     }

//     // ========== Section 4: Different Types (Strings) ==========
//     printSeparator("Working with Different Types");
//     {
//         Array<std::string> strings(3);
//         strings[0] = "Hello";
//         strings[1] = "42";
//         strings[2] = "Singapore";

//         for (size_t i = 0; i < strings.size(); i++)
//         {
//             std::cout << "strings[" << i << "]: " << strings[i] << std::endl;
//         }
        
//         strings[1] = "SUTD";
//         std::cout << "Modified strings[1]: " << strings[1] << std::endl;
//     }

//     // ========== Section 6: Edge Cases & Exceptions ==========
//     printSeparator("Edge Cases & Exceptions");
//     {
//         Array<int> empty(0);
//         std::cout << "Empty array size: " << empty.size() << std::endl;

//         Array<int> test(2);
//         try {
//             std::cout << "Trying to access index 5..." << std::endl;
//             std::cout << test[5] << std::endl; // throw
//         } catch (const std::exception& e) {
//             std::cerr << "Caught expected error: " << e.what() << std::endl;
//         }

//         try {
//             std::cout << "Trying to access negative index (cast to size_t)..." << std::endl;
//             std::cout << test[-1] << std::endl; 
//         } catch (const std::exception& e) {
//             std::cerr << "Caught expected error: " << e.what() << std::endl;
//         }
//     }

//     return 0;
// }
