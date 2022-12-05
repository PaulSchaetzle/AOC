#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <regex>

namespace utils {
  std::vector<int> getIntsFromString(const std::string& strLine) {
    std::vector<int> result;
    std::regex integer_regex("(\\d+)");

    auto string_begin = std::sregex_iterator(strLine.begin(), strLine.end(), integer_regex);

    auto string_end = std::sregex_iterator();

    for (std::sregex_iterator i = string_begin; i != string_end; i++) {
      std::smatch sm = *i;
      result.push_back(std::stoi(sm.str()));
      std::cout << sm.str() << std::endl;
    }
    return result;
  }
}
