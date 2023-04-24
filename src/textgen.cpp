// Copyright 2023 UNN-IASR
#include "textgen.h"
#include "chrono"
#include "iostream"
#include "random"
#include "sstream"
#include "string"

MarkovChain::MarkovChain(const std::string &base_str,
                         std::size_t _words_in_prefix)
    : words_in_prefix(_words_in_prefix) {

  std::stringstream ifs(base_str);
  prefix curr_pref;

  std::string word;
  for (std::size_t i = 0; i < words_in_prefix; i++) {
    if (ifs >> word) {
      curr_pref.push_back(word);
    }
  }

  while (ifs >> word) {
    statetab[curr_pref].push_back(word);
    curr_pref.pop_front();
    curr_pref.push_front(word);
  }
}

std::string MarkovChain::GenerateText(const std::size_t result_size) {
  std::string result;
  if (statetab.size() == 0)
    return "";
  prefix currPref = statetab.begin()->first;
  for (size_t i = 0; i < words_in_prefix; i++) {
    result += currPref[0];
    if (i != words_in_prefix - 1)
      result += " ";
  }
  std::mt19937 gen(
      std::chrono::high_resolution_clock::now().time_since_epoch().count());
  std::size_t size_in_words = words_in_prefix;
  while (size_in_words < result_size) {
    const auto iter = statetab.find(currPref);
    if (iter == statetab.end()) {
      break;
    }
    std::string word = iter->second[gen() % iter->second.size()];
    result += " " + word;
    currPref.pop_front();
    currPref.push_back(word);
  }
  return result;
}
