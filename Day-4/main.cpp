#include <iostream>
#include <string.h>
#include <fstream>
#include <array>

std::array<std::string, 2> splitStringAt(const std::string& strString, const char separator) {
  std::size_t middle = strString.find(separator);
  std::array<std::string, 2> result;
  result[0] = strString.substr(0, middle);
  result[1] = strString.substr(middle + 1);
  return result;
}

bool fullyContains(const std::string& strSectionID) {
  std::array<std::string, 2> elves = splitStringAt(strSectionID, ',');
  std::array<std::string, 2> firstElve = splitStringAt(elves.front(), '-');
  std::array<std::string, 2> secondElve = splitStringAt(elves.back(), '-');
  return std::stoi(firstElve.front()) <= std::stoi(secondElve.front())
    && std::stoi(firstElve.back()) >= std::stoi(secondElve.back())
    || std::stoi(secondElve.front()) <= std::stoi(firstElve.front())
    && std::stoi(secondElve.back()) >= std::stoi(firstElve.back());
}

bool partialyContains(const std::string& strSectionID) {
  std::array<std::string, 2> elves = splitStringAt(strSectionID, ',');
  std::array<std::string, 2> firstElve = splitStringAt(elves.front(), '-');
  std::array<std::string, 2> secondElve = splitStringAt(elves.back(), '-');
  return std::stoi(firstElve.back()) >= std::stoi(secondElve.front())
    && (std::stoi(firstElve.back()) <= std::stoi(secondElve.back())
	|| std::stoi(firstElve.front()) <= std::stoi(secondElve.back()));
}

int main(int argc, char *argv[]) {
  std::ifstream inputFile;
  inputFile.open("inputs.txt");

  std::string strLine;
  int i = 0;
  int j = 0;
  while (std::getline(inputFile, strLine)) {
    if (fullyContains(strLine))
      i++;
    if (partialyContains(strLine))
      j++;
  }
  std::cout << "Part 1: " << i << std::endl;
  std::cout << "Part 2: " << j << std::endl;
}
