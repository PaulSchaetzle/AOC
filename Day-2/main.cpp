#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <algorithm>

#define OTHER_MAGIC_NUMBER 64

int selectedEnemyShape(const char &shape) {
  return (int)shape - OTHER_MAGIC_NUMBER;
}

int loose (int enemyShape) {
  if (enemyShape == 1) return 3;
  else return enemyShape - 1;
}

int win (int enemyShape) {
  if (enemyShape == 3) return 1;
  else return enemyShape + 1;
}

int matchResult(const char &enemy, const char &player) {
  int enemyShape = selectedEnemyShape(enemy);
  switch (player) {
  case 'X':
    return 0 + loose(enemyShape);
    break;
  case 'Y':
    return 3 + enemyShape;
    break;
  case 'Z':
    return 6 + win(enemyShape);
    break;
  default:
    return -1;
    break;
  }
 }

int main(int argc, char *argv[]) {
  std::ifstream instream;
  instream.open("inputs.txt");

  std::string strLine;
  int i = 0;
  while (std::getline(instream, strLine)) {
    i += matchResult(strLine.at(0), strLine.at(2));
  }
  std::cout << "Part 2: " << i << std::endl;
}
