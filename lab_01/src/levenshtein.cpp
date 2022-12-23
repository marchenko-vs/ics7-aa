#include <vector>
#include <cstdlib>

#include "levenshtein.h"

using matrix_t = std::vector<std::vector<int>>;

static int find_min(const int num_1, const int num_2, const int num_3)
{
	int min = num_1;
	if (num_2 < min)
		min = num_2;
	if (num_3 < min)
		min = num_3;
	return min;
}

static int find_min(const int num_1, const int num_2, const int num_3,
					const int num_4)
{
	int min = num_1;
	if (num_2 < min)
		min = num_2;
	if (num_3 < min)
		min = num_3;
	if (num_4 < min)
		min = num_4;
	return min;
}

int levenshtein(std::string str_1, const std::size_t len_1, 
			    std::string str_2, const std::size_t len_2)
{
	size_t n = len_1 + 1;
	size_t m = len_2 + 1;
	if (n < m)
	{
		std::swap(n, m);
		std::swap(str_1, str_2);
	}
	std::vector<int> prev_str_1(m), curr_str_1(m);
	for (std::size_t i = 0; i < m; i++)
		prev_str_1[i] = i;
	for (std::size_t i = 1; i < n; i++)
	{
		curr_str_1[0] = i;
		for (std::size_t j = 1; j < m; j++)
		{
			bool flag = str_1[i - 1] == str_2[j - 1] ? false : true;
			curr_str_1[j] = find_min(curr_str_1[j - 1] + 1, 
			prev_str_1[j] + 1, prev_str_1[j - 1] + flag);
		}
		prev_str_1 = curr_str_1;
	}
	return curr_str_1[m - 1];
}

int damerau_levenshtein(std::string str_1, const std::size_t len_1, 
			            std::string str_2, const std::size_t len_2)
{
	if (len_1 == 0)
		return len_2;
	if (len_2 == 0)
		return len_1;
	size_t n = len_1 + 1;
	size_t m = len_2 + 1;
	if (n < m)
	{
		std::swap(n, m);
		std::swap(str_1, str_2);
	}
	std::vector<int> str_11(m), str_21(m), str_31(m);
	for (std::size_t i = 0; i < m; i++)
		str_11[i] = i;
	str_21[0] = 1;
	for (std::size_t j = 1; j < m; j++)
	{
		bool flag_diff = str_1[0] == str_2[j - 1] ? false : true;
		str_21[j] = find_min(str_21[j - 1] + 1, str_11[j] + 1, str_11[j - 1] + flag_diff);
	}
	str_31 = str_21;
	for (std::size_t i = 2; i < n; i++)
	{
		str_31[0] = i;
		if (1 < m)
		{
			bool flag_diff = str_1[i - 1] == str_2[0] ? false : true;
			str_31[1] = find_min(str_31[0] + 1, str_21[1] + 1, 
			str_21[0] + flag_diff);
		}
		for (std::size_t j = 2; j < m; j++)
		{
			bool flag_diff = str_1[i - 1] == str_2[j - 1] ? false : true;
			int flag_swap = ((str_1[i - 1] == str_2[j - 2]) && (str_1[i - 2] == str_2[j - 1])) ? 1 : INT_MAX - str_11[j - 2];
			str_31[j] = find_min(str_31[j - 1] + 1, str_21[j] + 1, str_21[j - 1] + flag_diff, str_11[j - 2] + flag_swap);
		}
		str_11 = str_21;
		str_21 = str_31;
	}
	return str_31[m - 1];
}

int damerau_levenshtein_rec(std::string str_1, const std::size_t len_1, 
                            std::string str_2, const std::size_t len_2)
{
	if (len_1 == 0)
		return len_2;
	if (len_2 == 0)
		return len_1;
	bool flag_diff;
	if (str_1[len_1 - 1] == str_2[len_2 - 1])
		flag_diff = false;
	else
		flag_diff = true;
	if ((len_1 > 1) && (len_2 > 1) && (str_1[len_1 - 1] == str_2[len_2 - 2]) && (str_1[len_1 - 2] == str_2[len_2 - 1]))
		return find_min(
			(damerau_levenshtein_rec(str_1, len_1 - 1, str_2, len_2) + 1),
			(damerau_levenshtein_rec(str_1, len_1, str_2, len_2 - 1) + 1),
			(damerau_levenshtein_rec(str_1, len_1 - 1, str_2, len_2 - 1) + flag_diff),
			(damerau_levenshtein_rec(str_1, len_1 - 2, str_2, len_2 - 2) + 1));
	else
		return find_min(
			(damerau_levenshtein_rec(str_1, len_1 - 1, str_2, len_2) + 1),
			(damerau_levenshtein_rec(str_1, len_1, str_2, len_2 - 1) + 1),
			(damerau_levenshtein_rec(str_1, len_1 - 1, str_2, len_2 - 1) + flag_diff));
}

static int damerau_levenshtein_cache_function(std::string str_1, const std::size_t len_1, 
                                              std::string str_2, const std::size_t len_2, 
						                      matrix_t &matrix)
{
	if (len_1 == 0)
		return len_2;
	if (len_2 == 0)
		return len_1;
	if (matrix[len_1 - 1][len_2 - 1] != INT_MAX)
		return matrix[len_1 - 1][len_2 - 1];
	bool flag_diff;
	if (str_1[len_1 - 1] == str_2[len_2 - 1])
		flag_diff = false;
	else
		flag_diff = true;
	if ((len_1 > 1) && (len_2 > 1) && (str_1[len_1 - 1] == str_2[len_2 - 2]) && (str_1[len_1 - 2] == str_2[len_2 - 1]))
		matrix[len_1 - 1][len_2 - 1] = find_min(
			damerau_levenshtein_cache_function(str_1, len_1 - 1, str_2, len_2, matrix) + 1,
			damerau_levenshtein_cache_function(str_1, len_1, str_2, len_2 - 1, matrix) + 1,
			damerau_levenshtein_cache_function(str_1, len_1 - 1, str_2, len_2 - 1, matrix) + flag_diff,
			damerau_levenshtein_cache_function(str_1, len_1 - 2, str_2, len_2 - 2, matrix) + 1);
	else
		matrix[len_1 - 1][len_2 - 1] = find_min(
			damerau_levenshtein_cache_function(str_1, len_1 - 1, str_2, len_2, matrix) + 1,
			damerau_levenshtein_cache_function(str_1, len_1, str_2, len_2 - 1, matrix) + 1,
			damerau_levenshtein_cache_function(str_1, len_1 - 1, str_2, len_2 - 1, matrix) + flag_diff);
	return matrix[len_1 - 1][len_2 - 1];
}

int damerau_levenshtein_cache(std::string str_1, const std::size_t len_1, 
					          std::string str_2, const std::size_t len_2)
{
	matrix_t matrix(len_1, std::vector<int>(len_2, INT_MAX));
	return damerau_levenshtein_cache_function(str_1, len_1, str_2, len_2, matrix);
}
