#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include "../Utils/util.h"

std::vector<std::stack<char>> crateStacks {
  std::stack<char>(),
  std::stack<char>({'F', 'T', 'C', 'L', 'R', 'P', 'G', 'Q'}),
  std::stack<char>({'N', 'Q', 'H', 'W', 'R', 'F', 'S', 'J'}),
  std::stack<char>({'F', 'B', 'H', 'W', 'P', 'M', 'Q'}),
  std::stack<char>({'V', 'S', 'T', 'D', 'F'}),
  std::stack<char>({'Q', 'L', 'D', 'W', 'V', 'F', 'Z'}),
  std::stack<char>({'Z', 'C', 'L', 'S'}),
  std::stack<char>({'Z', 'B', 'M', 'V', 'D', 'F'}),
  std::stack<char>({'T', 'J', 'B'}),
  std::stack<char>({'Q', 'N', 'B', 'G', 'L', 'S', 'P', 'H'}),
};

void printTops(const std::vector<std::stack<char>>& stacks) {
  for (int i = 1; i < stacks.size(); i++) {
    std::cout << stacks[i].top(); 
  }
  std::cout << std::endl;
}

void moveCranes(std::vector<std::stack<char>>& crates,
		std::vector<int> instructions) {
  int cratesToMove = instructions.front();
  int sourceStack = instructions[1];
  int targetStack = instructions.back();
  for(int i = 0; i < cratesToMove; i++) {
    crates[targetStack].push(crates[sourceStack].top());
    crates[sourceStack].pop();
  }
}

int main(int argc, char *argv[]) {
  std::ifstream inputFile;
  inputFile.open("inputs.txt");

  std::string strLine;
  bool atInstructions = false;
  while (std::getline(inputFile, strLine)) {
   
    if(atInstructions) {
      std::vector<int> instructions = utils::getIntsFromString(strLine);
      moveCranes(crateStacks, instructions);
    }

    if(strLine.empty())
      atInstructions = true;
  }

  std::cout << "Part 1: ";
  printTops(crateStacks);
  std::cout << std::endl;
  return 0;
}
