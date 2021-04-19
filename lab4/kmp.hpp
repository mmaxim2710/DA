#pragma once

#include <vector>
#include <string>

std::vector<size_t> CountPrefixFunction (const std::vector<std::string>& str);
bool EqualToNextPatternWord(const std::vector<std::string>& pattern, const std::string& str, size_t idx);
size_t KMPSearch(const std::vector<std::vector<std::string>>& text, const std::vector<std::string>& pattern);
