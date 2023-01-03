// File name: Solver.cpp
// Author: Abhay Khanna
// Email: abhay.khanna@vanderbilt.edu
// Description: This program contains the definitions for the Solver class. It includes the bulk
// of the important functions of the program as a whole, including the recursive backtracking
// solver.
// Last Changed: 12/22/2022

#include "Solver.h"
#include <algorithm>

// Class Constructor
//Insert all words in the specified dictionary file into the Trie. Also assigns the correct point
// values for each word length using lenToPoints
// pre: file exists and is readable
// post: all words in the file are inserted, lenToPoints is correct
// NASPA Word List 2019
Solver::Solver() : dictionary("Dictionary.txt"){
    //Assigning the point values per word length
    lenToPoints[3] = 100;
    lenToPoints[4] = 400;
    lenToPoints[5] = 800;
    for (size_t i = 6; i < 17; ++i){
        lenToPoints[i] = 1400 + (400 * (i - 6));
    }
    //lenToPoints only goes till 16, since that is the longest word possible. The point values
    //are the same values used in the actual game.
}

// inserts inputted letters into game board, checks if they are letters
// pre: gameBoard array and rowNum are passed
// post: letters in that row are now in the gameBoard
void Solver::buildBoard(std::string row, char gameBoard[4][4], size_t rowNum){
    for (size_t i = 0; i < 4; ++i) {
        if (!isalpha(row[i])) {
            throw std::invalid_argument("Must input letters.");
        } else {
            gameBoard[rowNum][i] = row[i];
        }
    }
}

// Gives prompts for entering the first row of letters, checks number of letters entered, calls
// buildBoard
// pre: gameBoard array is passed
// post: letters in that row are now in the gameBoard
void Solver::rowOne(char gameBoard[4][4]){
    bool correctInput = false;
    do
    {
        std::cout << "Enter four letters to make the top row (ex: 'abcd'): \n";
        std::string topRow;
        std::cin >> topRow;
        if (topRow.length() == 4) {
            buildBoard(topRow, gameBoard, 0);
            correctInput = true;
        } else {
            std::cout << "Must input exactly four letters without spaces." << std::endl;
        }

    }while(!correctInput);
}

// Gives prompts for entering the second row of letters, checks number of letters entered, calls
// buildBoard
// pre: gameBoard array is passed
// post: letters in that row are now in the gameBoard
void Solver::rowTwo(char gameBoard[4][4]){
    bool correctInput = false;
    do
    {
        std::cout << "Enter four more letters to make the second row: " << std::endl;
        std::string secondRow;
        std::cin >> secondRow;
        if (secondRow.length() == 4) {
            buildBoard(secondRow, gameBoard, 1);
            correctInput = true;
        } else {
            std::cout << "Must input exactly four letters without spaces." << std::endl;
        }

    }while(!correctInput);
}

// Gives prompts for entering the first third of letters, checks number of letters entered, calls
// buildBoard
// pre: gameBoard array is passed
// post: letters in that row are now in the gameBoard
void Solver::rowThree(char gameBoard[4][4]){
    bool correctInput = false;
    do
    {
        std::cout << "Enter four more letters to make the third row: " << std::endl;
        std::string thirdRow;
        std::cin >> thirdRow;
        if (thirdRow.length() == 4) {
            buildBoard(thirdRow, gameBoard, 2);
            correctInput = true;
        } else {
            std::cout << "Must input exactly four letters without spaces." << std::endl;
        }

    }while(!correctInput);
}

// Gives prompts for entering the fourth row of letters, checks number of letters entered, calls
// buildBoard
// pre: gameBoard array is passed
// post: letters in that row are now in the gameBoard
void Solver::rowFour(char gameBoard[4][4]){
    bool correctInput = false;
    do
    {
        std::cout << "Enter four more letters to make the bottom row: " << std::endl;
        std::string bottomRow;
        std::cin >> bottomRow;
        if (bottomRow.length() == 4) {
            buildBoard(bottomRow, gameBoard, 3);
            correctInput = true;
        } else {
            std::cout << "Must input exactly four letters without spaces." << std::endl;
        }

    }while(!correctInput);
}

// Simply prints the game board
// pre: gameBoard array is passed
// post: game board is printed
void Solver::printBoard(char gameBoard[4][4]){
    std::cout << "\n\nHere is the game board you entered: \n" << std::endl;

    for (size_t y = 0; y < 4; ++y){
        for (size_t x = 0; x < 4; ++x){
            std::cout << gameBoard[y][x] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "\nLets Play!\n" << std::endl;
}

// Finds all possible 3+ letter words on the board with the given tile as the starting tile, adds
// all those words to the answers vector
// pre: gameBoard array is passed, a bool array (visited) is also passed to keep track of visited
// letters, tile is specified with row and column
// post: all possible 3+ letter words on the board with the given tile as the starting tile are
// in the answers vector, visited[][] is still false for all values
void Solver::recurse(char gameBoard[4][4], std::string word,
                     int row, int column, bool visited[4][4]){

    //checking if visited or in bounds
    if (visited[row][column] || column < 0 || column > 3 || row < 0 || row > 3){
        return;
    }
    if (dictionary.isPrefix(word)){

        char letter = gameBoard[row][column];

        word += letter;

        visited[row][column] = true;

        recurse(gameBoard, word, row + 1, column + 1, visited);
        recurse(gameBoard, word, row + 1, column, visited);
        recurse(gameBoard, word, row + 1, column - 1, visited);
        recurse(gameBoard, word, row, column + 1, visited);
        recurse(gameBoard, word, row, column - 1, visited);
        recurse(gameBoard, word, row - 1, column + 1, visited);
        recurse(gameBoard, word, row - 1, column, visited);
        recurse(gameBoard, word, row - 1, column - 1, visited);

        visited[row][column] = false;

        //there may be more than one way to create the same word
        //checkDuplicates checks for that in O(1) lookup speed
        if (dictionary.isWord(word) && !checkDuplicates[word]){
            checkDuplicates[word] = true;
            ++numWords;
            answers.push_back(word);
        }

    } else {
        return;
    }
}

//compare function defined for the sort algorithm
//Sorts be string length decreasing
bool compare(std::string &a, std::string &b){
    // return (a.size() > b.size());
    if (a.size() > b.size()) return true;
    if (b.size() > a.size()) return false;

    if (b > a) return true;
    if (a > b) return false;

    return false;
}

// Sorts the answers by word length decreasing
// pre: answers are unsorted
// post: answers are sorted
void Solver::sortArray(){
    std::sort(answers.begin(), answers.end(), compare);
}

// Prints out the answers, resets the answers
// pre: n/a
// post: answers are printed, answers are reset
void Solver::print(){
    std::cout << "There are " << numWords << " possible words.\n\n";

    size_t maxScore = 0;
    for (size_t i = 0; i < numWords; ++i){
        std::cout << answers[i] << " " << lenToPoints[answers[i].length()] << std::endl;
        maxScore += lenToPoints[answers[i].length()];
    }

    std::cout << "The max possible score is " << maxScore << " points." << std::endl;

    checkDuplicates.clear();
    answers.clear();
    numWords = 0;
}