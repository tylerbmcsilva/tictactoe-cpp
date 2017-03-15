/*
 Title: Board Class
 Date: 03/11/17
 Descrition: Board sets up the game board for tictactoe,
 also is able to print the gameboard and verify a move
 */

#include "Board.hpp"
#include <string>
#include <iostream>

using namespace std;

/*
 Contructor
 Assigns the 2D array to have all '.' characters which act
 as empty spaces
*/

Board::Board(){
    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            gameBoard[y][x] = '.';
        }
    };
    totalMoves = 0;
};

/*
 makeMove
 Verifies the space is available, then sets the space based
 on the player that is passed. Returns bool of result
*/

bool Board::makeMove(int x, int y, char player){
    if(gameBoard[y][x] == '.'){
        gameBoard[y][x] = player;
        totalMoves += 1;
        return true;
    } else {
        return false;
    }
};

/*
 gameState
 Scans the entire 2D array to check for any results. Returns
 the enum of the state of hthe game
*/

State Board::gameState(){
    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            if(gameBoard[y][x] == '.') {
                continue;
            }
            char base = gameBoard[y][x];
            if(gameBoard[y][x+1] == base){
                if(gameBoard[y][x+2] == base){
                    return base == 'X' ? XWON : OWON;
                }
            }else if(gameBoard[y+1][x+1] == base){
                if(gameBoard[y+2][x+2] == base){
                    return base == 'X' ? XWON : OWON;
                }
            }else if(gameBoard[y+1][x] == base){
                if(gameBoard[y+2][x] == base){
                    return base == 'X' ? XWON : OWON;
                }
            } else if(gameBoard[y+1][x-1] == base) {
                if(gameBoard[y+2][x-2] == base){
                    return base == 'X' ? XWON : OWON;
                }
            } else if(totalMoves == 9){
                return DRAW;
            }
        }
    };
    return INPROGRESS;
};

/*
 print
 Prints the board to the console.
 */

void Board::print(){
    cout << endl << " \t0\t1\t2" << endl;
    for(int y = 0; y < 3; y++){
        cout << y;
        for(int x = 0; x < 3; x++){
            cout << "\t" << gameBoard[y][x];
        };
        cout << endl;
    };
    cout << endl;
};


