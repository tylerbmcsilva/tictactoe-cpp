//
//  TicTacToe.hpp
//  TicTacToe
//
//  Created by Tyler Silva on 3/11/17.
//  Copyright © 2017 Tyler McSilva. All rights reserved.
//

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
