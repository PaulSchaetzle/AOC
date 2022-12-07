#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "../Utils/util.h"

#define LIMIT 700000000
#define DISK 3000000000
std::vector<size_t> mSizes;

class Node {
public:
  virtual size_t getSize() = 0;
  virtual std::shared_ptr<Node> getParent() = 0;
  virtual std::shared_ptr<Node> getSubdir(const std::string& name) = 0;
  virtual void add(const std::string& name, const std::shared_ptr<Node>& sptrNode) = 0;
};

class Dir : public Node {
public:
  Dir() {}
  Dir(const std::shared_ptr<Node>& sptrParent) : m_sptrParent(sptrParent) {}
  size_t getSize() override {
    size_t result = 0;
    for (const std::pair<std::string, std::shared_ptr<Node>> &n : m_subdirs) {
      result += n.second->getSize();
    }
    mSizes.push_back(result);
    return result;
  }

  void add(const std::string& name, const std::shared_ptr<Node>& sptrNode) override {
    m_subdirs[name] = sptrNode;
  }

  std::shared_ptr<Node> getSubdir(const std::string& name) override {
    return m_subdirs.at(name);
  }

  std::shared_ptr<Node> getParent() override {
    return m_sptrParent;
  }

private:
  std::unordered_map<std::string, std::shared_ptr<Node>> m_subdirs;
  std::string m_name;
  std::shared_ptr<Node> m_sptrParent;
  size_t otherSize = 0;
};

class File : public Node {
public:
  File(size_t size) : m_size(size) {}
  size_t getSize() override {
    return m_size;
  }
  std::shared_ptr<Node> getParent() override {;}
  std::shared_ptr<Node> getSubdir(const std::string& name) override {;}
  void add(const std::string& name, const std::shared_ptr<Node>& sptrNode) override{;}
private:
  size_t m_size;
};

bool isCommand(const std::string& strLine) {
  return strLine.starts_with('$');
}

bool isDir(const std::string& strLine) {
  return strLine.starts_with('d');
}

int main(int argc, char *argv[]) {
  std::ifstream inputFile;
  inputFile.open("inputs.txt");

  std::vector<size_t> sizes;
  std::string strLine;
  std::vector<std::string> input; 
  std::shared_ptr<Node> currentDir;
  std::shared_ptr<Dir> rootDir(new Dir);

  while (std::getline(inputFile, strLine)) {
    input = utils::splitStringAt(strLine, ' ');
    if(isCommand(strLine) && input.size() == 3) {
      if(input.back() == "/") {
	currentDir = rootDir;
      } else if (input.back() == "..") {
	currentDir = currentDir->getParent();
      } else {
	currentDir = currentDir->getSubdir(input.back());
      } 
    }
    else if(isCommand(strLine)) {;} // do nothing in case of "$ ls"
    else {
      if(isDir(strLine)) {
	currentDir->add(input.back(), std::make_shared<Dir>(currentDir));
      } else {
	currentDir->add(input.back(), std::make_shared<File>(std::stol(input.front())));
      }
    }
  }

  size_t filesystemSize = rootDir->getSize();

  size_t size = 0;
  std::sort(mSizes.begin(), mSizes.end());
  for(size_t i : mSizes) {
    if(i <= 100000)
      size += i; 
  }

  std::cout << "Part 1: " << size << std::endl;

  for(size_t i : mSizes) {
    if(i > (filesystemSize - (DISK - LIMIT))) {
      std::cout << "Part 2: " << i << std::endl;
      break;
    }
  }
}
