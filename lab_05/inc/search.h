#ifndef _SEARCH_H_
#define _SEARCH_H_

#include <stdio.h>

int search_kmp(const char *const substring, const char *const text, int *const occurrences, int *const num_of_occur);
int search_default(const char *const substring, const char *const text, int *const occurrences, int *const num_of_occur);

#endif // _SEARCH_H_
