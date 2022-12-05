#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <regex>

namespace utils {
  std::vector<int> getIntsFromString(const std::string& strLine) {
    std::vector<int> result;
    std::regex integer_regex("(\\d+)");

    // See: https://en.cppreference.com/w/cpp/regex/regex_iterator
    auto string_begin = std::sregex_iterator(strLine.begin(), strLine.end(), integer_regex);

    auto string_end = std::sregex_iterator();

    for (std::sregex_iterator i = string_begin; i != string_end; i++) {
      std::smatch sm = *i;
      result.push_back(std::stoi(sm.str()));
    }
    return result;
  }

  std::vector<std::string> splitStringAt(const std::string& strString, const char separator) {
    std::vector<std::string> result;
    std::size_t pos = 0;
    std::size_t count = 0;
    while((count = strString.find(separator, pos)) != std::string::npos) {
      result.push_back(strString.substr(pos, count - pos));
      pos = count + 1;
    }     
    result.push_back(strString.substr(pos)); // Return the whole string if no separator occurences are found
    return result;
  }
} // namespace utils
