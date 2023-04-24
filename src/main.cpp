// Copyright 2023 UNN-IASR
#include "fstream"
#include "iostream"
#include "string"

#include "textgen.h"

int main() {
  std::ifstream ifs("datafile.txt");
  std::string str;
  std::string word;
  while (ifs >> word) {
    str += word + " ";
  }

  MarkovChain markovChain(str, 1);
  std::cout << markovChain.GenerateText() << "\n";
}
