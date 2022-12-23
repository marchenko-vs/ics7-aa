int damerau_levenshtein_rec(std::string str_1, const std::size_t len_1, std::string str_2, const std::size_t len_2)
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
		return find_min(4,
			(damerau_levenshtein_rec(str_1, len_1 - 1, str_2, len_2) + 1),
			(damerau_levenshtein_rec(str_1, len_1, str_2, len_2 - 1) + 1),
			(damerau_levenshtein_rec(str_1, len_1 - 1, str_2, len_2 - 1) + flag_diff),
			(damerau_levenshtein_rec(str_1, len_1 - 2, str_2, len_2 - 2) + 1));
	else
		return find_min(3,
			(damerau_levenshtein_rec(str_1, len_1 - 1, str_2, len_2) + 1),
			(damerau_levenshtein_rec(str_1, len_1, str_2, len_2 - 1) + 1),
			(damerau_levenshtein_rec(str_1, len_1 - 1, str_2, len_2 - 1) + flag_diff));
}
