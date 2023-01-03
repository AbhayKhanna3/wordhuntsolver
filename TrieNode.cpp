// File name: TrieNode.cpp
// Author: Abhay Khanna
// Email: abhay.khanna@vanderbilt.edu
// Description: This program contains the definitions for the TrieNode class. The Big-3
// Constructors are all fleshed out because it is a common type of class, but all of them may not
// be necessary for this specific program, since there in only one Trie being created.
// Last Changed: 12/22/2022

#include "TrieNode.h"
#include <string>

//The constructor. Takes a character for the node, and a bool
//indicating whether it represents the end of a word. Note, there is no
//default ctor.
TrieNode::TrieNode(char c, bool b) : letter(c), endOfWord(b){
    for (size_t i = 0; i < NUMBER_LETTERS; ++i){
        children[i] = nullptr;
    }
}

// Copy Constructor
// pre:  Class object, a TrieNode, exists
// post: Object is initialized to be a copy of the parameter
TrieNode::TrieNode(const TrieNode& rhs) : letter(rhs.letter), endOfWord(rhs.endOfWord){
    for (size_t i = 0; i < NUMBER_LETTERS; ++i){
        children[i] = rhs.children[i];
    }
}

// Class Destructor
// Destroys a TrieNode
// pre:  Class object exists
// post: Class object does not exist
TrieNode::~TrieNode(){
    for (size_t i = 0; i < NUMBER_LETTERS; ++i){
        children[i] = nullptr;
        delete children[i];
    }
}

// Assignment operator
// Assigns a TrieNode to another
// pre: both class objects exist
// post: this class object gets assigned a copy of the parameter class
// object
const TrieNode &TrieNode::operator=(const TrieNode& rhs){
    if (this == &rhs) {
        return *this;
    }

    TrieNode tmp(rhs);
    std::swap(letter, tmp.letter);
    std::swap(endOfWord, tmp.endOfWord);
    std::swap(children, tmp.children);

    return *this;
}

//Insert str starting with the given TrieNode. Create new TrieNodes
//as needed and be sure to set the boolean flag on the last node to
//true
// pre: TrieNode and Trie exist, string is provided
// post: string is inserted
void TrieNode::insert(const std::string& str){
    if (str == ""){
        endOfWord = true;
        return;
    }
    char frontLetter = tolower(str[0]);

    if (children[frontLetter - 'a'] == nullptr){
        children[frontLetter - 'a'] = new TrieNode(str.front(), (str.length() == 1));
    }

    children[frontLetter - 'a']->insert(str.substr(1));
}

//Returns true if str is in the sub-Trie starting at the given TrieNode,
//else returns false
// pre: TrieNode and Trie exist, string exists
// post: returns true if the string is a word in the subTrie, false otherwise
bool TrieNode::isWord(const std::string& str) const{
    if (str == ""){
        return endOfWord;
    }
    char frontLetter = tolower(str[0]);
    if (children[frontLetter - 'a'] == nullptr){
        return false;
    } else {
        return children[frontLetter - 'a']->isWord(str.substr(1));
    }
}

//Returns true if pre is a prefix in the sub-Trie starting at the given TrieNode,
//else returns false
// pre: TrieNode and Trie exist, string exists
// post: returns true if the string is a prefix in the subTrie, false otherwise
bool TrieNode::isPrefix(const std::string& pre) const{
    if (pre == ""){
        return true;
    }
    //Just in case the letter is not lowercase already
    char frontLetter = tolower(pre[0]);

    if (children[frontLetter - 'a'] == nullptr){
        return false;
    } else {
        return children[frontLetter - 'a']->isPrefix(pre.substr(1));
    }
}

#include "TrieNode.h"
