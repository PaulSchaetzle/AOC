#include <iostream>
#include <string.h>
#include <fstream>
#include <unordered_set>
#include "../Utils/util.h"

struct rope {
  long X;
  long Y;
  bool operator==(const rope& other) const {
    return ((this->X == other.X && this->Y == other.Y));
  }
};

class RopeHashFunction {
public:
  size_t operator()(const rope& t) const {
    return t.X;
  }
};

void moveRight(struct rope& rope) {
  rope.X++;
}

void moveLeft(struct rope& rope) {
  rope.X--;
}

void moveUp(struct rope& rope) {
  rope.Y++;
}

void moveDown(struct rope& rope) {
  rope.Y--;
}

void tailAdjust(struct rope& tail, const rope& head) {
  int dX = head.X - tail.X;
  int dY = head.Y - tail.Y;

  if((dX) > 1) {
    moveRight(tail);
    if(dY > 0) moveUp(tail);
    else if(dY < 0) moveDown(tail);
    std::cout << "move Right" << std::endl;
  }

  else if(dX < -1) {
    moveLeft(tail);
    if(dY > 0) moveUp(tail);
    else if(dY < 0) moveDown(tail);
    std::cout << "move Left" << std::endl;
  }

  else if(dY > 1) {
    moveUp(tail);
    if(dX > 0) moveRight(tail);
    else if(dX < 0) moveLeft(tail);
    std::cout << "move Up" << std::endl;
  }

  else if(dY < -1) {
    moveDown(tail);
    if(dX > 0) moveRight(tail);
    else if(dX < 0) moveLeft(tail);
    std::cout << "move Down" << std::endl;
  }
}

int main(int argc, char *argv[]) {
  std::ifstream inputFile;
  inputFile.open("inputs.txt");

  std::unordered_set<struct rope, RopeHashFunction> result1;
  std::unordered_set<struct rope, RopeHashFunction> result2;
  
  struct rope head = {0, 0};
  struct rope one = {0, 0};
  struct rope two = {0, 0};
  struct rope three = {0, 0};
  struct rope four = {0, 0};
  struct rope five = {0, 0};
  struct rope six = {0, 0};
  struct rope seven = {0, 0};
  struct rope eight = {0, 0};
  struct rope nine = {0, 0};
  struct rope tail = {0, 0};

  char dir;
  long steps;
  std::vector<std::string> input;
  std::string strLine;
  while (std::getline(inputFile, strLine)) {
    input = utils::splitStringAt(strLine, ' ');
    dir = strLine.front();
    steps = std::stoi(input.back());
    std::cout << "Direction: " << dir << "; Steps: " << steps << std::endl;
    for(int i = 0; i < steps; i++) {
      switch (dir) {
      case 'L':
	moveLeft(head);
	break;
      case 'R':
	moveRight(head);
	break;
      case 'U':
	moveUp(head);
	break;
      case 'D':
	moveDown(head);
      }
      tailAdjust(one, head);
      tailAdjust(two, one);
      tailAdjust(three, two);
      tailAdjust(four, three);
      tailAdjust(five, four);
      tailAdjust(six, five);
      tailAdjust(seven, six);
      tailAdjust(eight, seven);
      tailAdjust(tail, eight);
      result1.insert(one);
      result2.insert(tail);
      std::cout << "Head X: " << head.X << "; Head Y: " << head.Y << std::endl;
      std::cout << "Tail X: " << tail.X << "; Tail Y: " << tail.Y << std::endl;
    }
  }

  std::cout << "Part 1: " << result1.size() << std::endl;
  std::cout << "Part 2: " << result2.size() << std::endl;
}
