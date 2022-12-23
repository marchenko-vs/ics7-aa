#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>

#include "sort.h"

#define NUM_OF_BUCKETS 5

static void reverse_array(std::vector<int> &array, const std::size_t size)
{
    if (size < 2)
        return;
    std::size_t last_elem_index = size / 2;
    for (std::size_t i = 0; i < last_elem_index; i++)
        std::swap(array[i], array[size - i - 1]);
}

static int get_max(const std::vector<int> &array, const std::size_t size)
{
    int max = array[0];
    for (std::size_t i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

static int get_min(const std::vector<int> &array, const std::size_t size)
{
    int min = array[0];
    for (std::size_t i = 1; i < size; i++)
        if (array[i] < min)
            min = array[i];
    return min;
}

void cocktail_sort(std::vector<int> &array, const std::size_t size)
{
    if (size < 2)
        return;
    bool flag = true;
    int start = 0, end = size - 1;
    while (flag)
    {
        flag = false;
        for (int i = start; i < end; ++i)
        {
            if (array[i] > array[i + 1])
            {
                std::swap(array[i], array[i + 1]);
                flag = true;
            }
        }
        if (!flag)
            break;
        flag = false;
        --end;
        for (int i = end - 1; i >= start; --i)
        {
            if (array[i] > array[i + 1])
            {
                std::swap(array[i], array[i + 1]);
                flag = true;
            }
        }
        ++start;
    }
}

static void pos_bucket_sort(std::vector<int> &array, const std::size_t size)
{  
    if (size < 2)
        return;
    double max = get_max(array, size);
    double min = get_min(array, size);
    int range = std::ceil((max - min) / NUM_OF_BUCKETS);
    std::vector<int> buckets[NUM_OF_BUCKETS];
    for (std::size_t i = 0; i < size; i++)
    {
        int bucket_index = std::floor((array[i] - min) / range);
        if (bucket_index == NUM_OF_BUCKETS)
            bucket_index--;
        buckets[bucket_index].push_back(array[i]);
    }
    for (int i = 0; i < NUM_OF_BUCKETS; i++)
        cocktail_sort(buckets[i], buckets[i].size());
    int index = 0;
    for (int i = 0; i < NUM_OF_BUCKETS; i++)
    {
        for (std::size_t j = 0; j < buckets[i].size(); j++)
        {
            array[index] = buckets[i][j];
            index++;
        }
    }
}

void bucket_sort(std::vector<int> &array, const std::size_t size)
{ 
    if (size < 2)
        return;
    int pos_elements_count = 0, neg_elements_count = 0;
    for (std::size_t i = 0; i < size; i++)
    {
        if (array[i] >= 0)
            pos_elements_count++;
        else
            neg_elements_count++;
    }
    std::vector<int> pos_array;
    std::vector<int> neg_array;
    int index = 0;
    if (neg_elements_count > 0)
    {
        for (std::size_t i = 0; i < size; i++)
            if (array[i] < 0)
                neg_array.push_back(-array[i]);
        pos_bucket_sort(neg_array, neg_array.size());
        reverse_array(neg_array, neg_array.size());
    }
    if (pos_elements_count > 0)
    {
        for (std::size_t i = 0; i < size; i++)
            if (array[i] >= 0)
                pos_array.push_back(array[i]);
        pos_bucket_sort(pos_array, pos_array.size());
    }
    if (neg_elements_count > 0)
    {
        for (std::size_t i = 0; i < neg_array.size(); i++)
        {
            array[index] = -neg_array[i];
            index++;
        }
    }
    if (pos_elements_count > 0)
    {
        for (std::size_t i = 0; i < pos_array.size(); i++)
        {
            array[index] = pos_array[i];
            index++;
        }
    }
}

static void counting_sort(std::vector<int> &array, const std::size_t size, int exp)
{
    if (size < 2)
        return;
    std::vector<int> output_array(size, 0);
    std::vector<int> count(10, 0);
    for (std::size_t i = 0; i < size; i++)
    {
        int index = (array[i] / exp) % 10;
        count[index]++;
    }
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = size - 1; i >= 0; i--)
    {
        int index = (array[i] / exp) % 10;
        output_array[count[index] - 1] = array[i];
        count[index]--;
    }
    for (std::size_t i = 0; i < size; i++)
        array[i] = output_array[i];
}
 
void radix_sort(std::vector<int> &array, const std::size_t size)
{
    if (size < 2)
        return;
    int pos_elements_count = 0, neg_elements_count = 0;
    for (std::size_t i = 0; i < size; i++)
    {
        if (array[i] >= 0)
            pos_elements_count++;
        else
            neg_elements_count++;
    }
    std::vector<int> pos_array;
    std::vector<int> neg_array;
    int index = 0;
    if (neg_elements_count > 0)
    {
        for (std::size_t i = 0; i < size; i++)
            if (array[i] < 0)
                neg_array.push_back(-array[i]);
        int max = get_max(neg_array, neg_array.size());
        for (int exp = 1; max / exp > 0; exp *= 10)
            counting_sort(neg_array, neg_array.size(), exp);
        reverse_array(neg_array, neg_array.size());
    }
    if (pos_elements_count > 0)
    {
        for (std::size_t i = 0; i < size; i++)
            if (array[i] >= 0)
                pos_array.push_back(array[i]);
        int max = get_max(pos_array, pos_array.size());
        for (int exp = 1; max / exp > 0; exp *= 10)
            counting_sort(pos_array, pos_array.size(), exp);
    }
    if (neg_elements_count > 0)
    {
        for (std::size_t i = 0; i < neg_array.size(); i++)
        {
            array[index] = -neg_array[i];
            index++;
        }
    }
    if (pos_elements_count > 0)
    {
        for (std::size_t i = 0; i < pos_array.size(); i++)
        {
            array[index] = pos_array[i];
            index++;
        }
    }
}
