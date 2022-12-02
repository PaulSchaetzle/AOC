#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <algorithm>

#define MAGIC_NUMBER 87
#define OTHER_MAGIC_NUMBER 64

int selectedPlayerShape(const char &shape) {
  return (int)shape - MAGIC_NUMBER;
}

int selectedEnemyShape(const char &shape) {
  return (int)shape - OTHER_MAGIC_NUMBER;
}

int matchResult(const char &enemy, const char &player) {
  int enemyShapeSelected = selectedEnemyShape(enemy);
  int playerShapeSelected = selectedPlayerShape(player);
  int diff = enemyShapeSelected - playerShapeSelected;

  if (!diff) {
    return 3;
  }
  else if (diff == -1 || diff == 2) {
    return 6;
  }
  else {
    return 0;
  }
}

int main(int argc, char *argv[]) {
  std::ifstream instream;
  instream.open("inputs.txt");

  std::string strLine;
  int i = 0;
  while (std::getline(instream, strLine)) {
    i += selectedPlayerShape(strLine.at(2));
    i += matchResult(strLine.at(0), strLine.at(2));
  }
  std::cout << "Part 1: " << i << std::endl;
}
