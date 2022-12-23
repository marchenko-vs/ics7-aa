int damerau_levenshtein(std::string str_1, const std::size_t len_1, std::string str_2, const std::size_t len_2)
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
		str_21[j] = find_min(3, str_21[j - 1] + 1, str_11[j] + 1, str_11[j - 1] + flag_diff);
	}
	str_31 = str_21;
	for (std::size_t i = 2; i < n; i++)
	{
		str_31[0] = i;
		if (1 < m)
		{
			bool flag_diff = str_1[i - 1] == str_2[0] ? false : true;
			str_31[1] = find_min(3, str_31[0] + 1, str_21[1] + 1, 
			str_21[0] + flag_diff);
		}
		for (std::size_t j = 2; j < m; j++)
		{
			bool flag_diff = str_1[i - 1] == str_2[j - 1] ? false : true;
			int flag_swap = ((str_1[i - 1] == str_2[j - 2]) && (str_1[i - 2] == str_2[j - 1])) ? 1 : INT_MAX - str_11[j - 2];
			str_31[j] = find_min(4, str_31[j - 1] + 1, str_21[j] + 1, str_21[j - 1] + flag_diff, str_11[j - 2] + flag_swap);
		}
		str_11 = str_21;
		str_21 = str_31;
	}
	return str_31[m - 1];
}
