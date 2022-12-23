#include <cstring>

static void compute_lps_array(const char *const substring, int substring_len, int *const lps)
{
	int len = 0, i = 1;
	lps[0] = 0;
	while (i < substring_len)
	{
		if (substring[i] == substring[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0)
				len = lps[len - 1];
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

int search_kmp(const char *const substring, const char *const text, int *const occurrences, int *const num_of_occur)
{
	*num_of_occur = 0;
	int num_of_cmp = 0;
	int substring_len = strlen(substring);
	int text_len = strlen(text);
	int lps[substring_len];
	compute_lps_array(substring, substring_len, lps);
	int i = 0, j = 0;
	while ((text_len - i) >= (substring_len - j))
	{
		if (substring[j] == text[i])
		{
			j++;
			i++;
		}
		if (j == substring_len)
		{
			occurrences[*num_of_occur] = i - j;
			(*num_of_occur)++;
			j = lps[j - 1];
		}
		else if (i < text_len && substring[j] != text[i])
		{
			if (j != 0)
				j = lps[j - 1];
			else
				i++;
		}
		num_of_cmp++;
	}
	if (*num_of_occur == 0)
		(*num_of_occur)--;
	return num_of_cmp;
}
