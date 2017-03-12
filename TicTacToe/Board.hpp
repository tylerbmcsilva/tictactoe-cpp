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
