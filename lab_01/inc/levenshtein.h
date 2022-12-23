#ifndef _LEVENSHTEIN_H_
#define _LEVENSHTEIN_H_

#include <string>
#include <cstdlib>

int levenshtein(std::string str_1, const std::size_t len_1, 
			    std::string str_2, const std::size_t len_2);
int damerau_levenshtein(std::string str_1, const std::size_t len_1, 
               std::string str_2, const std::size_t len_2);
int damerau_levenshtein_rec(std::string  str_1, const std::size_t len_1, 
                  std::string str_2, const std::size_t len_2);
int damerau_levenshtein_cache(std::string str_1, const std::size_t len_1, 
                      std::string str_2, const std::size_t len_2);

#endif // _LEVENSHTEIN_H_
