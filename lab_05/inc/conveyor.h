#ifndef _CONVEYOR_H_
#define _CONVEYOR_H_

#include <cstdio>

#define get_time(time) __asm__ __volatile__("rdtsc" :"=A"(time))

#define N 1024
#define THREADS_COUNT 3

typedef struct
{
    char *text;
    char *substring;
    int occurrences_1[N], occurrences_2[N];
    int noc_1, noc_2;
    int noo_1, noo_2;
    FILE *f;
} request_t;

typedef struct request_state
{
    bool stage_1;
    bool stage_2;
    bool stage_3;
} request_state_t;

void log_data(const request_t *const request);
void linear_processing(int num_of_requests, char *text, char substrings[][50]);
void conveyor_processing(int num_of_requests, char *text, char substrings[][50]);

#endif // _CONVEYOR_H_
