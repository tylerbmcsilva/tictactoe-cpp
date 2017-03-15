/*
 Title: Board Class
 Date: 03/11/17
 Descrition: Board sets up the game board for tictactoe,
 also is able to print the gameboard and verify a move
*/

#ifndef Board_hpp
#define Board_hpp

#include <string>
#include <string.h>

using namespace std;

enum State{XWON, OWON, DRAW, INPROGRESS};

class Board {
private:
    char gameBoard[4][4];
    int totalMoves;
public:
    Board();
    bool makeMove(int,int,char);
    State gameState();
    void print();
};

#endif /* Board_hpp */
