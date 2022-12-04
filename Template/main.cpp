#include <iostream>
#include <string.h>
#include <fstream>

int main(int argc, char *argv[]) {
  std::ifstream inputFile;
  inputFile.open("inputs.txt");

  std::string strLine;
  while (std::getline(inputFile, strLine)) {
  }
}
