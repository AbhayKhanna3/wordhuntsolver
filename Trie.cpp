// File name: Trie.cpp
// Author: Abhay Khanna
// Email: abhay.khanna@vanderbilt.edu
// Description: This program contains the definitions for the Trie class. This class creates a
// Trie using TrieNodes, and handles the file input and the program interaction of TrieNodes
// Last Changed: 12/22/2022


#include "Trie.h"
#include <stdexcept>

// Class Constructor
//Insert all words in the specified file into the Trie. Throws a
//std::invalid_argument exception if the specified file cannot be
//opened.
// pre: file exists and is readable
// post: all words in the file are inserted
// Collins Scrabble Words (2019). 279,496 words. Words only.
Trie::Trie(const std::string& filename) : root(' ', false){

    std::ifstream infile;
    infile.open(filename.c_str());
    std::string word;

    if (infile.fail()) {
        throw std::invalid_argument("File cannot be opened");
    }

    while (infile >> word){
        if (word.length() >= 3){
            insert(word);
        }
    }
    infile.close();
}

// Class Destructor
// Destroys a Trie
// pre:  Class object exists
// post: Class object does not exist
Trie::~Trie(){

}

//Insert parameter word into trie
// pre: parameter word exists
// post: the parameter word is inserted into the Trie
void Trie::insert(const std::string& word){
    root.insert(word);
}

//Returns true if word is in the Trie, else returns false
// pre: a string word is provided, trie exists
// post: returns true if the word is in the trie, false otherwise
bool Trie::isWord(const std::string& word) const{
    return root.isWord(word);
}

//Returns true if pre is a prefix of a word in the Trie, else returns false
// pre: a string prefix is provided, trie exists
// post: returns true if the prefix is a prefix of a word in the trie, false otherwise
bool Trie::isPrefix(const std::string& pre) const{
    return root.isPrefix(pre);
}
