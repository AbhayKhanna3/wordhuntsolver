//
// Created by araze on 12/17/2022.
//

#ifndef WORDHUNTSOLVER_TRIE_H
#define WORDHUNTSOLVER_TRIE_H

#include <cstddef>
#include <cstdlib>
#include <string>
#include <fstream>
#include "TrieNode.h"

class Trie
{
private:
    TrieNode root;

public:

    // Class Constructor
    //Insert all words in the specified file into the Trie. Throws a
    //std::invalid_argument exception if the specified file cannot be
    //opened.
    // pre: file exists and is readable
    // post: all words in the file are inserted
    Trie(const std::string& filename);


    // Class Destructor
    // Destroys a Trie
    // pre:  Class object exists
    // post: Class object does not exist
    ~Trie();


    //Insert parameter word into trie
    // pre: parameter word exists
    // post: the parameter word is inserted into the Trie
    void insert(const std::string& word);

    //Returns true if word is in the Trie, else returns false
    // pre: a string word is provided, trie exists
    // post: returns true if the word is in the trie, false otherwise
    bool isWord(const std::string& word) const;

    //Returns true if pre is a prefix of a word in the Trie, else returns false
    // pre: a string prefix is provided, trie exists
    // post: returns true if the prefix is a prefix of a word in the trie, false otherwise
    bool isPrefix (const std::string& pre) const;

};

#endif //WORDHUNTSOLVER_TRIE_H
