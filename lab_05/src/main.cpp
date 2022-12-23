#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "conveyor.h"
#include "fio.h"

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		printf("Error: there should be 3 command line arguments.\n");
		return 1;
	}
	FILE *f_text = fopen(argv[1], "r");
	if (!f_text)
	{
		printf("Error: file %s doesn't exists.\n", argv[1]);
		return 2;
	}
	FILE *f_substrings = fopen(argv[2], "r");
	if (!f_substrings)
	{
		printf("Error: file %s doesn't exists.\n", argv[2]);
		return 2;
	}
	char text[N];
	if (fscan_text(f_text, text) == -1)
	{
		printf("Error: text in file %s can't be read.\n", argv[1]);
		return 3;
	}
	char substrings[50][50];
	int num_of_subs = fscan_substrings(f_substrings, substrings);
	if (num_of_subs == -1)
	{
		printf("Error: substrings in file %s can't be read.\n", argv[2]);
		return 3;
	}
	linear_processing(num_of_subs, text, substrings);
	conveyor_processing(num_of_subs, text, substrings);
	return 0;
}
