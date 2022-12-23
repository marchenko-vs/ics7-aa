static int damerau_levenshtein_cache_function(std::string str_1, const std::size_t len_1, std::string str_2, const std::size_t len_2, std::vector<std::vector<int>>& matrix)
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
		matrix[len_1 - 1][len_2 - 1] = find_min(4,
			damerau_levenshtein_cache_function(str_1, len_1 - 1, str_2, len_2, matrix) + 1,
			damerau_levenshtein_cache_function(str_1, len_1, str_2, len_2 - 1, matrix) + 1,
			damerau_levenshtein_cache_function(str_1, len_1 - 1, str_2, len_2 - 1, matrix) + flag_diff,
			damerau_levenshtein_cache_function(str_1, len_1 - 2, str_2, len_2 - 2, matrix) + 1);
	else
		matrix[len_1 - 1][len_2 - 1] = find_min(3, 
			damerau_levenshtein_cache_function(str_1, len_1 - 1, str_2, len_2, matrix) + 1,
			damerau_levenshtein_cache_function(str_1, len_1, str_2, len_2 - 1, matrix) + 1,
			damerau_levenshtein_cache_function(str_1, len_1 - 1, str_2, len_2 - 1, matrix) + flag_diff);
	return matrix[len_1 - 1][len_2 - 1];
}

int damerau_levenshtein_cache(std::string str_1, const std::size_t len_1, std::string str_2, const std::size_t len_2)
{
	std::vector<std::vector<int>> matrix(len_1, std::vector<int>(len_2, INT_MAX));
	return damerau_levenshtein_cache_function(str_1, len_1, str_2, len_2, matrix);
}
