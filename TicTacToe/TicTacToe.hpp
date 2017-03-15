/*
 Title: TicTacToe Class
 Date: 03/11/17
 Descrition: Runs the game of TicTacToe, facilitates which
 player goes when, and prints who the winner is at the end
 of the game!
 */

#ifndef TicTacToe_hpp
#define TicTacToe_hpp

#include "./Board.hpp"

class TicTacToe {
private:
    Board gameBoard;
    char PlayerTurn;
public:
    TicTacToe(char);
    string Play();
};


#endif /* TicTacToe_hpp */
