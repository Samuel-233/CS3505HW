#include "Trie.h"

#include <cstring>
#include <iostream>

/*
Name: Shu Chen
HW4
This is the implementation for the Trie class, which can store word, and check word by prefix.
It also implement rules of three: copy constructor, equal assign, and deconstructor
*/

Trie::Trie() : endOfWord(false)
{
    for (int i = 0; i < 26; i++)
    {
        this->nextChar[i] = nullptr;
    }
}

Trie::Trie(const Trie &other) : endOfWord(other.endOfWord)
{
    for (int i = 0; i < 26; i++)
    {
        if (other.nextChar[i])
            this->nextChar[i] = new Trie(*(other.nextChar[i]));
        else
            this->nextChar[i] = nullptr;
    }
}

Trie &Trie::operator=(Trie other)
{
    this->endOfWord = other.endOfWord;
    for (int i = 0; i < 26; i++)
    {
        std::swap(this->nextChar[i], other.nextChar[i]);
    }
    return *this;
}

Trie::~Trie()
{
    for (int i = 0; i < 26; i++)
    {
        delete this->nextChar[i];
        this->nextChar[i] = nullptr;
    }
}

void Trie::addWord(std::string word)
{
    char firstChar = word[0];
    int index = firstChar - 'a';
    if (index < 26 && index > -1)
    {
        if (word.length() > 1)
        {
            if (!this->nextChar[index])
                this->nextChar[index] = new Trie();
            this->nextChar[index]->addWord(word.erase(0, 1));
        }
        else
        {
            if (!this->nextChar[index])
                this->nextChar[index] = new Trie();
            this->nextChar[index]->endOfWord = true;
        }
    }
}

bool Trie::isWord(std::string word)
{
    if (word.length() > 0)
    {
        int index = word[0] - 'a';
        if (!this->nextChar[index])
            return false; // If it point to a null Trie, we do not need to check any more
        return this->nextChar[index]->isWord(word.erase(0, 1));
    }
    return this->endOfWord;
}

std::vector<std::string> Trie::allWords()
{
    std::vector<std::string> result;

    for (int i = 0; i < 26; i++)
    {
        Trie *nextChar = this->nextChar[i];
        if (nextChar) // If there exist a next char, we want to find all possible words.
        {
            std::string currentChar = std::string(1, 'a' + i); // find out current node's char
            if (nextChar->endOfWord)
                result.push_back(currentChar);                       // if current node is also end of word, add it to result
            std::vector<std::string> wordVec = nextChar->allWords(); // get all chars behind current node
            for (std::string &word : wordVec)
            {
                result.push_back(currentChar + word); // add current node char to all words then return
            }
        }
    }
    return result;
}

std::vector<std::string> Trie::allWordsStartingWithPrefix(std::string prefix)
{
    Trie *endOfPrefix = this; // First get the end of prefix, then find all words under this node
    std::string prefixLeft = prefix;
    std::vector<std::string> result;

    while (prefixLeft.length() > 0)
    {
        int index = prefixLeft[0] - 'a';
        if (!endOfPrefix->nextChar[index] || index > 25 || index < 0)
        {
            return std::vector<std::string>();
        }
        if (!endOfPrefix->nextChar[index])
            return std::vector<std::string>(); // Same, if pointer is null, there is no word
        endOfPrefix = endOfPrefix->nextChar[index];
        prefixLeft.erase(0, 1);
    }
    if (endOfPrefix->endOfWord)
        result.push_back(prefix);

    std::vector<std::string> words = endOfPrefix->allWords();
    for (std::string &word : words)
    {
        result.push_back(prefix + word);
    }

    return result;
}
