#include <cstdio>

#define N 1024

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
