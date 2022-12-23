#include <iostream>
#include <cstdio>
#include <string>

#include "levenshtein.h"

int main()
{
    std::string str_1, str_2;
    std::cout << "Enter first string: ";
    std::cin >> str_1;
    std::cout << "Enter second string: ";
    std::cin >> str_2;
    int choice = 0;
    std::cout << "1. Levenshtein.\n2. Damerau-Levenshtein.\n"
                 "3. Recursive Damerau-Levenshtein.\n"
                 "4. Recursive Damerau-Levenshtein with cache." << std::endl;
    std::cout << "Choose an algorithm (1 - 4): ";
    int result = 0;
    if (scanf("%d", &choice) != 1)
    {
        std::cout << "Error: incorrect data type." << std::endl;
        return -1;
    }
    if (choice < 1 || choice > 4)
    {
        std::cout << "Error: choice should be from 1 to 4." << std::endl;
        return -2;
    }
    switch (result)
    {
        case 1:
        result = levenshtein(str_1, str_1.size(), str_2, str_2.size());
        break;
        case 2:
        result = damerau_levenshtein(str_1, str_1.size(), str_2, str_2.size());
        break;
        case 3:
        result = damerau_levenshtein_rec(str_1, str_1.size(), str_2, str_2.size());
        break;
        default:
        result = damerau_levenshtein_cache(str_1, str_1.size(), str_2, str_2.size());
        break;
    }
    std::cout << "Result: " << result << std::endl;
    return 0;
}
