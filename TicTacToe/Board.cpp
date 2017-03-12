//
//  Board.cpp
//  TicTacToe
//
//  Created by Tyler Silva on 3/11/17.
//  Copyright © 2017 Tyler McSilva. All rights reserved.
//

#include "Board.hpp"
#include <string>
#include <iostream>

using namespace std;

Board::Board(){
    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            gameBoard[y][x] = '.';
        }
    };
    totalMoves = 0;
};

bool Board::makeMove(int x, int y, char player){
    if(gameBoard[y][x] == '.'){
        gameBoard[y][x] = player;
        totalMoves += 1;
        return true;
    } else {
        return false;
    }
};

State Board::gameState(){
    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            if(gameBoard[y][x] == '.') {
                continue;
            }
            char base = gameBoard[y][x];
            if(gameBoard[y][x+1] == base){
                if(gameBoard[y][x+2] == base){
                    return base == 'x' ? XWON : OWON;
                }
            }else if(gameBoard[y+1][x+1] == base){
                if(gameBoard[y+2][x+2] == base){
                    return base == 'x' ? XWON : OWON;
                }
            }else if(gameBoard[y+1][x] == base){
                if(gameBoard[y+2][x] == base){
                    return base == 'x' ? XWON : OWON;
                }
            } else if(gameBoard[y+1][x-1] == base) {
                if(gameBoard[y+2][x-2] == base){
                    return base == 'x' ? XWON : OWON;
                }
            } else if(totalMoves == 9){
                return DRAW;
            }
        }
    };
    return INPROGRESS;
};


void Board::print(){
    cout << " \t0\t1\t2" << endl;
    for(int y = 0; y < 3; y++){
        cout << y;
        for(int x = 0; x < 3; x++){
            cout << "\t" << gameBoard[y][x];
        };
        cout << endl;
    };
};


