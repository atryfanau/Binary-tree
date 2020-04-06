#include <iostream>
#include <fstream>
#include <vector>

#include "BinaryTree.h"

using namespace std;

const int lower = 'A' - 'a';

string trim(string input) {
  string result = "";
  for (auto c: input) {
    if (c >= 'A' && c <= 'Z')
      result += c - lower;
    else if (c >= 'a' && c <= 'z')
      result += c;
    else if (c >= '0' && c <= '9')
      result += c;
    else if (c == '-')
      result += c;
  }
  return result;
}

int main(int argc, char **argv)
{
  if (argc < 2) {
    cout << "Input file not set!" << endl;
    return 1;
  }

  ifstream input = ifstream(argv[1]);
  BinaryTree bt;

  while(!input.eof()) {
    string word;
    input >> word;
    word = trim(word);
    if (word.length() > 0) {
      if (!bt.useNode(word)) {
        bt.insertNode(word);
      }
    }
  }

  bt.displayInOrder();

  return 0;
}
