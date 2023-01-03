// File name: main.cpp
// Author: Abhay Khanna
// Email: abhay.khanna@vanderbilt.edu
// Description: This program is the driver for the Word Hunt Solver
// Last Changed: 12/22/2022

#include "Solver.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

int main() {
    Solver WordHuntSolver;
    std::cout << "Welcome to the Word Hunt solver.\n" << std::endl;
    std::string yesOrNo;

    do
    {
        char gameBoard[4][4];
        WordHuntSolver.rowOne(gameBoard);
        WordHuntSolver.rowTwo(gameBoard);
        WordHuntSolver.rowThree(gameBoard);
        WordHuntSolver.rowFour(gameBoard);

        WordHuntSolver.printBoard(gameBoard);

        std::string word = "";
        bool visited[4][4];
        // Keeps track of visited letters, since no tile on the board can be
        // used twice for the same word

        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                visited[i][j] = false;

        //calling solver on each tile
        for (int row = 0; row < 4; ++row){
            for (int column = 0; column < 4; ++column){
                WordHuntSolver.recurse(gameBoard, word, row, column, visited);
            }
        }

        WordHuntSolver.sortArray();
        WordHuntSolver.print();

        std::cout << "Do you want to do it again? (Y|N)\n" << std::endl;
        std::cin >> yesOrNo;

    }while(yesOrNo.at(0)=='Y' || yesOrNo.at(0)=='y');

    return 0;
}
