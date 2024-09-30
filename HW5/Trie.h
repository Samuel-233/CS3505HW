#ifndef TRIE_H
#define TRIE_H
#include <iostream>
#include <string>
#include <vector>
/*
Name: Shu Chen
HW4
A trie class which can store word in a trie tree form.
this class will make a string in to array of single char, and put it in to tree in order.
Each level have 26 pointers point to all possible char (a~z) behind current char.
*/
class Trie
{
  // Array of pointer, each pointer means a different char
  Trie *nextChar[26];
  // If current node is end of the word, means all node's parent and node itself can form a word
  bool endOfWord;

public:
  /// @brief constructor of the tree
  Trie();

  /// @brief Copy constructor of the tree
  /// @param other the tree we want to copy from
  Trie(const Trie &other);

  /// @brief Deconstructor of Trie Class
  ~Trie();

  /// @brief override the = operator to achieve copy function
  /// @param other the data we want to copy
  /// @return a new copy of the other
  Trie &operator=(Trie other);

  /// @brief Add word to trie tree
  /// @param wordToAdd word that want to add
  void addWord(std::string wordToAdd);

  /// @brief Check if this word store in the tree
  /// @param word word want to check
  /// @return a boolean show if the word exist
  bool isWord(std::string word);

  /// @brief Return all word start with given prefix
  /// @param prefix prefix constrain
  /// @return a vector of prefix
  std::vector<std::string> allWordsStartingWithPrefix(std::string prefix);

  /// @brief Get all words
  /// @return a vector contains all words of this object
  std::vector<std::string> allWords();
};

#endif