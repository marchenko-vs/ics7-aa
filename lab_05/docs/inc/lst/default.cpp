#include <cstring>

int search_default(const char *const substring, const char *const text, int *const occurrences, int *const num_of_occur)
{
	*num_of_occur = 0;
	int num_of_cmp = 0;
	int substring_len = strlen(substring);
	int text_len = strlen(text);
	for (int i = 0, j = 0; i < text_len; i++)
	{
		if (text[i] == substring[j])
			j++;
		else
			j = 0;
		if (j == substring_len)
		{
			occurrences[*num_of_occur] = i - j + 1;
			(*num_of_occur)++;
			j = 0;
			i -= (substring_len - 1);
		}
		num_of_cmp++;
	}
	if (*num_of_occur == 0)
		(*num_of_occur)--;
	return num_of_cmp;
}
