#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]) {
  std::ifstream instream;
  instream.open("inputs.txt");
  std::vector<int> vOutput;

  std::string strLine;
  int i = 0;
  while (std::getline(instream, strLine)) {
    if (!strLine.size()) {
      vOutput.push_back(i);
      i = 0;
    } else {
      i += std::stoi(strLine);
    }
  }

  std::sort(vOutput.begin(), vOutput.end());
  if (!vOutput.empty()) {
    for (int i = 1; i < 4; i++) {
      std::cout << vOutput.at(vOutput.size() - i) << std::endl;
    }
  }
  return 0;
}
