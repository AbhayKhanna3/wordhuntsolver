// File name: Solver.h
// Author: Abhay Khanna
// Email: abhay.khanna@vanderbilt.edu
// Description: This program contains the declarations for the Solver class. It includes the bulk
// of the important functions of the program as a whole, including the recursive backtracking
// solver.
// Last Changed: 12/22/2022

#include <cstdlib>
#include <iostream>
#include "Trie.h"
#include <map>
#include <vector>
#include <utility>

#ifndef WORDHUNTSOLVER_SOLVER_H
#define WORDHUNTSOLVER_SOLVER_H

class Solver {
private:
    std::map<int, int> lenToPoints;
    std::map<std::string, bool> checkDuplicates;
    std::vector<std::string> answers; //answer is stored as (word, path)
    size_t numWords = 0;
    Trie dictionary;


public:
    // Class Constructor
    //Insert all words in the specified dictionary file into the Trie. Also assigns the correct point
    // values for each word length using lenToPoints
    // pre: file exists and is readable
    // post: all words in the file are inserted, lenToPoints is correct
    // NASPA Word List 2019
    Solver();

    // inserts inputted letters into gameboard, checks if they are letters
    // pre: gameBoard array and rowNum are passed
    // post: letters in that row are now in the gameBoard
    void static buildBoard(std::string row, char gameBoard[4][4], size_t rowNum);

    // Gives prompts for entering the first row of letters, checks number of letters entered, calls
    // buildBoard
    // pre: gameBoard array is passed
    // post: letters in that row are now in the gameBoard
    void static rowOne(char gameBoard[4][4]);

    // Gives prompts for entering the second row of letters, checks number of letters entered, calls
    // buildBoard
    // pre: gameBoard array is passed
    // post: letters in that row are now in the gameBoard
    void static rowTwo(char gameBoard[4][4]);

    // Gives prompts for entering the first third of letters, checks number of letters entered, calls
    // buildBoard
    // pre: gameBoard array is passed
    // post: letters in that row are now in the gameBoard
    void static rowThree(char gameBoard[4][4]);

    // Gives prompts for entering the fourth row of letters, checks number of letters entered, calls
    // buildBoard
    // pre: gameBoard array is passed
    // post: letters in that row are now in the gameBoard
    void static rowFour(char gameBoard[4][4]);

    // Simply prints the game board
    // pre: gameBoard array is passed
    // post: game board is printed
    void static printBoard(char gameBoard[4][4]);

    // Finds all possible 3+ letter words on the board with the given tile as the starting tile, adds
    // all those words to the answers vector
    // pre: gameBoard array is passed, a bool array (visited) is also passed to keep track of visited
    // letters, tile is specified with row and column
    // post: all possible 3+ letter words on the board with the given tile as the starting tile are
    // in the vector, visited[][] is still false for all valued
    void recurse(char gameBoard[4][4], std::string word, int row, int column, bool visited[4][4]);

    // Sorts the answers by word length decreasing
    // pre: answers are unsorted
    // post: answers are sorted
    void sortArray();

    // Prints out the answers, resets the answers
    // pre: n/a
    // post: answers are printed, answers are reset
    void print();

    };


#endif //WORDHUNTSOLVER_SOLVER_H
