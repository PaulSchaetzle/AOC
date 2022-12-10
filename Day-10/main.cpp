#include <iostream>
#include <string.h>
#include <fstream>
#include "../Utils/util.h"

void calculateSignalStrength(const int& cycle, const int& X, int& rssi) {
  std::cout << "Cycle: " << cycle << " X: " << X << " RSSI: "  << rssi << std::endl;
  rssi += cycle * X;
}

void noop(int& cycle, const int X, int& rssi) {
  if(!((cycle+20) % 40)) calculateSignalStrength(cycle, X, rssi);
  cycle++;
}

void addx(int& cycle, int& X, int dX, int& rssi) {
  for(int i = 0; i < 2; i++) {
    if(!((cycle + 20) % 40)) calculateSignalStrength(cycle, X, rssi);
    cycle++;
  }
  std::cout << "X: " << X << " dX: " << dX << std::endl;
  X += dX;
}


int main(int argc, char *argv[]) {
  std::ifstream inputFile;
  inputFile.open("inputs.txt");

  int X = 1;  // Advent od Code? More like Advent of Reading Comprehention
  int cycle = 1; // AGAIN?????
  int rssi = 0;
  std::vector<std::string> input;
  std::string strLine;
  while (std::getline(inputFile, strLine)) {
    input = utils::splitStringAt(strLine, ' ');
    if(strLine.at(0) == 'n') noop(cycle, X, rssi);
    else addx(cycle, X, std::stoi(input.back()), rssi);
  }
  std::cout << "Part 1: " << rssi << std::endl;
}
