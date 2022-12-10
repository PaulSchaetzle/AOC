#include <iostream>
#include <string.h>
#include <fstream>
#include "../Utils/util.h"

void calculateSignalStrength(const int& cycle, const int& X, int& rssi) {
  rssi += cycle * X;
}

void drawScreen(const int& cycle, const int& X) {
  int position = cycle - ((cycle / 40) * 40) -1; // looks goofy but works
  if((position == X) || (position == X-1) || (position == X+1))
    std::cout << '#';
  else
    std::cout << '.';
  if(!(cycle % 40)) std::cout << std::endl;
}

void noop(int& cycle, const int X, int& rssi) {
  if(!((cycle+20) % 40)) calculateSignalStrength(cycle, X, rssi);
  drawScreen(cycle, X);
  cycle++;
}

void addx(int& cycle, int& X, int dX, int& rssi) {
  for(int i = 0; i < 2; i++) {
    if(!((cycle + 20) % 40)) calculateSignalStrength(cycle, X, rssi);
    drawScreen(cycle, X);
    cycle++;
  }
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
