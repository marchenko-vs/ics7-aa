#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fio.h"

int fscan_text(FILE *f, char text[])
{
    if (fgets(text, 1001, f) == NULL)
        return -1;
    text[strlen(text) - 1] = '\0';
    return 0;
}

int fscan_substrings(FILE *f, char substrings[50][50])
{
    int num_of_subs = 0;
    if (fscanf(f, "%d\n", &num_of_subs) != 1)
        return -1;
    if (num_of_subs < 1 || num_of_subs > 50)
        return -1;
    int i = 0;
    while(!feof(f) && i < num_of_subs)
    {
        if (!fgets(substrings[i], 51, f))
        {
            if (substrings[i][0] == '\0')
                break;
            else
                return -1;
        }
        else
        {
            substrings[i][strlen(substrings[i]) - 1] = '\0';
            i++;
        }
    }
    return i;
}
