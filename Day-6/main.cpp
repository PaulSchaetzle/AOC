#include <iostream>
#include <string.h>
#include <fstream>

bool containsCharTwice(const std::string& strLine) {
  for(int i = 0; i < strLine.size(); i ++) {
    if(strLine.find(strLine.at(i), i+1) != std::string::npos)
      return true;
  }
  return false;
}

int startOfPacket(const std::string& strLine) {
  std::string strPossibleMarker;
  int position = 0;
  for(int i = 0; i < strLine.size(); i++) {
    strPossibleMarker = strLine.substr(i, 4);
    if(!containsCharTwice(strPossibleMarker)) {
      std::cout << "Possible Marker: " << strPossibleMarker << std::endl;
      position = i + 4; // Plus 4 because is wants the character AFTER which the sequence is complete, not the first one of the sequence!
      break;
    }
  }
  return position;
}

int startOfMessage(const std::string& strLine) {
  std::string strPossibleMarker;
  int position = 0;
  for(int i = 0; i < strLine.size(); i++) {
    strPossibleMarker = strLine.substr(i, 14);
    if(!containsCharTwice(strPossibleMarker)) {
      std::cout << "Possible Marker: " << strPossibleMarker << std::endl;
      position = i + 14; // Plus 14 because is wants the character AFTER which the sequence is complete, not the first one of the sequence!
      break;
    }
  }
  return position;
}

int main(int argc, char *argv[]) {
  std::ifstream inputFile;
  inputFile.open("inputs.txt");

  std::string strLine;
  int packet = 0;
  int message = 0;
  while (std::getline(inputFile, strLine)) {
    packet = startOfPacket(strLine);
    message = startOfMessage(strLine);
  }
  std::cout << "Part 1: " << packet << std::endl;
  std::cout << "Part 2: " << message << std::endl;
}
