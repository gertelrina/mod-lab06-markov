// Copyright 2023 UNN-IASR
#ifndef INCLUDE_TEXTGEN_H_
#define INCLUDE_TEXTGEN_H_
#include "deque"
#include "map"
#include "vector"
#include "string"

class MarkovChain {
 private:
  typedef std::deque<std::string> prefix;
  std::map<prefix, std::vector<std::string>> statetab;
  std::size_t words_in_prefix;

  std::string ConvertFromDeque(const prefix &prx);

 public:
  MarkovChain() = delete;
  MarkovChain(const std::string &base_str, std::size_t _words_in_prefix = 2);
  std::string GenerateText(const std::size_t result_size = 1000);
  ~MarkovChain() {}
};
#endif // INCLUDE_TEXTGEN_H_
