#include <cstdio>
#include <iostream>

#include "testing_sort.h"
#include "sort.h"

#define SIZE 2048

int main(void)
{
    std::vector<int> array;
    int option = 0, size = 0, element = 0;

    while (option != 4)
    {
        array.clear();

        printf("Enter size of an array: ");

        if (scanf("%d", &size) != 1)
        {
            printf("Error: incorrect data type.\n");
            return 3;
        }

        if (size < 1)
        {
            printf("Error: size should be from 1 to %d.\n", SIZE);
            return 4;
        }

        printf("Enter elements of an array:\n");

        for (int i = 0; i < size; i++)
            if (scanf("%d", &element) != 1)
            {
                printf("Error: incorrect data type.\n");
                return 5;
            }
            else
                array.push_back(element);

        printf("Sorting algorithms:\n1. Radix sort.\n2. Bucket sort.\n"
               "3. Cocktail sort.\n4. Exit.\nChoose the option (1-4): ");

        if (scanf("%d", &option) != 1)
        {
            printf("Error: incorrect data type.\n");
            return 1;
        }

        if (option < 1 || option > 4)
        {
            printf("Error: option should be from 1 to 3.\n");
            return 2;
        }
        
        switch (option)
        {
            case 1:
                radix_sort(array, size);
                break;
            case 2:
                bucket_sort(array, size);
                break;
            case 3:
                cocktail_sort(array, size);
                break;
            case 4:
                return 0;
        }

        print_array(array, size);
    }

    return 0;
}
