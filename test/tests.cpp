// Copyright 2021 GHA Test Team
#include "textgen.h"
#include <gtest/gtest.h>
#include "string"

TEST(markovTest, checkOneSuffix) {
  int wordsInPrefix = 1;
  std::string str("a");
  std::string exp("a");
  auto generator = MarkovChain(str, wordsInPrefix);
  auto table = generator.GenerateText();
  EXPECT_EQ(str, exp);
}

TEST(markovTest, checkTwoSuffix) {
  int wordsInPrefix = 2;
  std::string str("a b c d e a b c d e ");
  std::string exp("a a c");
  auto generator = MarkovChain(str);
  auto result = generator.GenerateText();
  EXPECT_TRUE(result.size());
}

TEST(markovTest, checkZeroSize) {
  std::string str("");
  std::string exp("");
  auto generator = MarkovChain(str);
  auto result = generator.GenerateText();
  EXPECT_EQ(result, exp);
}

TEST(markovTest, checkNonDetermenistic) {
  int wordsInPrefix = 1;
  std::string str("a c a d");
  auto generator = MarkovChain(str, wordsInPrefix);
  auto result = generator.GenerateText();
  for (auto i = 0; i < result.size(); i += 2) {
    if (i == result.size() - 1) {
      EXPECT_EQ(result[i], 'd');
    } else if (i % 4 == 0) {
      EXPECT_EQ(result[i], 'a');
    } else {
      EXPECT_EQ(result[i], 'c');
    }
  }
}
