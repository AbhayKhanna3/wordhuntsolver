//
// Created by araze on 12/17/2022.
//

#ifndef WORDHUNTSOLVER_TRIENODE_H
#define WORDHUNTSOLVER_TRIENODE_H

#include <string>

const size_t NUMBER_LETTERS = 26;


class TrieNode
{
private:
    TrieNode *children[NUMBER_LETTERS];
    char letter;
    bool endOfWord;

public:
    //The constructor. Takes a character for the node, and a bool
    //indicating whether it represents the end of a word. Note, there is no
    //default ctor.
    TrieNode(char c, bool b);

    // Copy Constructor
    // pre:  Class object, a TrieNode, exists
    // post: Object is initialized to be a copy of the parameter
    TrieNode(const TrieNode& rhs);

    // Class Destructor
    // Destroys a TrieNode
    // pre:  Class object exists
    // post: Class object does not exist
    ~TrieNode();

    // Assignment operator
    // Assigns a TrieNode to another
    // pre: both class objects exist
    // post: this class object gets assigned a copy of the parameter class
    // object
    const TrieNode& operator=(const TrieNode& rhs);

    //Insert str starting with the given TrieNode. Create new TrieNodes
    //as needed and be sure to set the boolean flag on the last node to
    //true
    // pre: TrieNode and Trie exist, string is provided
    // post: string is inserted
    void insert(const std::string& str);

    //Returns true if str is in the sub-Trie starting at the given TrieNode,
    //else returns false
    // pre: TrieNode and Trie exist, string exists
    // post: returns true if the string is a word in the subTrie, false otherwise
    bool isWord(const std::string& str) const;

    //Returns true if pre is a prefix in the sub-Trie starting at the given TrieNode,
    //else returns false
    // pre: TrieNode and Trie exist, string exists
    // post: returns true if the string is a prefix in the subTrie, false otherwise
    bool isPrefix(const std::string& pre) const;
};

#endif //WORDHUNTSOLVER_TRIENODE_H
