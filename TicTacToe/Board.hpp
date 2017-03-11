//
//  Board.hpp
//  TicTacToe
//
//  Created by Tyler Silva on 3/11/17.
//  Copyright © 2017 Tyler McSilva. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <string>

using namespace std;

class Board {
private:
    enum State{XWON, OWON, DRAW, INPROGRESS};
    char gameBoard[3][3];
public:
    Board();
    bool makeMove(int,int);
    string gameState();
    void printBoard();
};

#endif /* Board_hpp */
