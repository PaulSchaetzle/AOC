#include <iostream>
#include <string.h>
#include <fstream>

char findDoubles(const std::string& strRucksack)
{
  std::size_t pos;
  int halfSize = strRucksack.size() / 2;
  for (int i = 0; i < halfSize; i++) {
    pos = strRucksack.find(strRucksack.at(i), halfSize);
    if (pos != std::string::npos) {
      break;
    }
  }
  return strRucksack.at(pos);
}

char findTriblets(const std::string& strFirstRucksack, const std::string& strSecondRuckSack, const std::string& strThirdRuckSack) {
  std::size_t pos;
  for(int i = 0; i < strFirstRucksack.size(); i++) {
    pos = strSecondRuckSack.find(strFirstRucksack.at(i));
    if((pos != std::string::npos) && (strThirdRuckSack.find(strSecondRuckSack.at(pos)) != std::string::npos)) {
      break;
    }
  }
  return strSecondRuckSack.at(pos);
}
  
int calculatePriority(char item) {
  if(isupper(item))
    return (int)item - 38;
  else
    return (int)item - 96;
}

int main(int argc, char *argv[]) {
  std::ifstream instream;
  instream.open("inputs.txt");

  std::string strLine;
  int i = 0;
  int j = 0;
  int k = 0;
  std::string stringList[3];
  while (std::getline(instream, strLine)) {
    i+= calculatePriority(findDoubles(strLine));
    stringList[j] = strLine;
    j++;
    if (j > 2) {
      k += calculatePriority(findTriblets(stringList[0], stringList[1], stringList[2]));
      j=0;
    }
  }
  std::cout << "Part 1: " << i << std::endl;
  std::cout << "Part 2: " << k << std::endl;
}
