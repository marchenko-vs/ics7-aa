int levenshtein(std::string str_1, const std::size_t len_1, std::string str_2, const std::size_t len_2)
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
			curr_str_1[j] = find_min(3, curr_str_1[j - 1] + 1, 
			prev_str_1[j] + 1, prev_str_1[j - 1] + flag);
		}
		prev_str_1 = curr_str_1;
	}
	return curr_str_1[m - 1];
}
