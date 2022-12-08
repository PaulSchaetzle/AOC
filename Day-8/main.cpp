#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>

void parseInput(std::vector<std::vector<long>>& forrest) {
  std::ifstream inputFile;
  inputFile.open("inputs.txt");

  std::string strLine;
  for(int i = 0; std::getline(inputFile, strLine); i++) {
    std::vector<long> trees;
    for(int j = 0; j < strLine.size(); j++) {
      trees.push_back((int)(strLine.at(j) - 48)); // see ascii table
    }
    forrest.push_back(trees);
  }
}

void print(const std::vector<std::vector<long>>& forrest) {
  for(auto trees : forrest) {
    for(auto tree : trees) {
      std::cout << tree << ", ";
    }
    std::cout << std::endl;
  }
}

bool visibleTree(const std::vector<std::vector<long>>& forrest, int x, int y) {
  int treeColSize = forrest.size();
  int treeRowSize = forrest[y].size();

  bool visibleRight = true;
  bool visibleLeft = true;
  bool visibleTop = true;
  bool visibleBottom = true;

  if((((x || y) == 0) || (x == (treeRowSize - 1) || y == (treeColSize - 1)))) return true;
  for(int i = 0; i < x; i++) 
    if(forrest[y][i] >= forrest[y][x]) {
      visibleLeft = false;
      break;
    }
  for(int i = x + 1 ; i < treeRowSize; i++)
    if(forrest[y][i] >= forrest[y][x]) {
      visibleRight = false;
      break;
    }
  for(int i = 0; i < y; i++)
    if(forrest[i][x] >= forrest[y][x]) {
      visibleTop = false;
      break;
    }
  for(int i = y + 1; i < treeColSize; i++)
    if(forrest[i][x] >= forrest[y][x]) {
      visibleBottom = false;
      break;
    }
  if(visibleLeft || visibleRight || visibleTop || visibleBottom) {
    return true;
  }
  return false;
}

int scenicScore(const std::vector<std::vector<long>>& forrest, int x, int y) {
  int treeColSize = forrest.size();
  int treeRowSize = forrest[y].size();

  int visibleRight = 0;
  int visibleLeft = 0;
  int visibleTop = 0;
  int visibleBottom = 0;

  for (int i = x - 1; i >= 0; i--) {
    visibleLeft++; 
    if (forrest[y][i] >= forrest[y][x]) 
      break;
  }
  for (int i = x + 1; i < treeRowSize; i++) {
    visibleRight++;
    if (forrest[y][i] >= forrest[y][x]) 
      break;
  }
  for (int i = y - 1; i >= 0; i--) {
    visibleTop++;
    if (forrest[i][x] >= forrest[y][x])
      break;
  }
  for (int i = y + 1; i < treeColSize; i++) {
    visibleBottom++;
    if (forrest[i][x] >= forrest[y][x])
      break;
  }
  return visibleLeft * visibleRight * visibleTop * visibleBottom;
}

int main(int argc, char *argv[]) {
  std::vector<std::vector<long>> forrest;
  parseInput(forrest);
  size_t result = 0;
  size_t maxScenicScore = 0;
  for (int y = 0; y < forrest.size(); y++) {
    for (int x = 0; x < forrest[y].size(); x++) {
       if (visibleTree(forrest, x, y)) {
       	result++;
       }
      int temp = scenicScore(forrest, x, y);
      if (temp > maxScenicScore)
	maxScenicScore = temp;
    }
  }
  std::cout << "Part 1: " << result << std::endl;
  std::cout << "Part 2: " << maxScenicScore << std::endl;
}
