#ifndef _SORT_H_
#define _SORT_H_

#include <vector>

void cocktail_sort(std::vector<int> &array, const std::size_t size);
void radix_sort(std::vector<int> &array, const std::size_t size);
void bucket_sort(std::vector<int> &array, const std::size_t size);

#endif // _SORT_H_
