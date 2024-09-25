#include "Trie.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

/*
Name: Shu Chen
HW4
This is the tester for the Trie class, which user need to input two file name, one for
words in dictionary, one for checking words that start with this prefix
It also tested rule of three for Trie class.
*/

std::vector<std::string> readFile(char *fileName)
{

    std::ifstream file(fileName); // Open File
    if (!file.is_open())
    {
        std::cerr << "Error occur when opening the file" << std::endl;
        return std::vector<std::string>();
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line))
    {                          // read file per line
        lines.push_back(line); // add line to string
    }

    file.close(); // close file
    return lines;
}

int main(int args, char *argv[])
{
    if (args != 3)
    {
        std::cout << "Pleas input two command-line arguments, each one a filename.";
        return 0;
    }

    std::vector<std::string> lines = readFile(argv[1]);
    if (lines.size() == 0)
    {
        std::cout << "no word added, exiting the program" << std::endl;
        return 0;
    }

    Trie tree;
    for (std::string &word : lines)
    {
        tree.addWord(word);
    }

    lines = readFile(argv[2]);
    if (lines.size() == 0)
    {
        std::cout << "no word to check, exiting the program" << std::endl;
        return 0;
    }

    for (std::string &word : lines)
    {
        std::cout << "Checking " << word << "\n";
        if (tree.isWord(word))
            std::cout << "Word found";
        else
            std::cout << "Word not found";

        std::vector<std::string> wordsFound = tree.allWordsStartingWithPrefix(word);
        if (wordsFound.size() > 0)
        {
            for (std::string &word : wordsFound)
            {
                std::cout << " " << word;
            }
        }
        std::cout << std::endl;
    }

    // test rule of three
    Trie smallTree;
    smallTree.addWord("test");
    smallTree.addWord("table");
    smallTree.addWord("apple");
    // Test copy constructor
    Trie smallTreeCopy(smallTree);
    smallTree.addWord("bear");
    if (smallTreeCopy.allWords().size() != 3)
        std::cout << "didn't copy correctly" << std::endl;

    // Test copy operator
    smallTreeCopy = smallTree;
    smallTree.addWord("cat");
    if (smallTreeCopy.allWords().size() != 4)
        std::cout << "didn't copy correctly" << std::endl;

    // Test deconstructor
    Trie *deletedTree = new Trie();
    deletedTree->addWord("aaa");
    deletedTree->addWord("bbb");
    delete deletedTree;
}