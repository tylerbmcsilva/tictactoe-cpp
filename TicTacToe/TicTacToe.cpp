//
//  TicTacToe.cpp
//  TicTacToe
//
//  Created by Tyler Silva on 3/11/17.
//  Copyright © 2017 Tyler McSilva. All rights reserved.
//
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>
#include "TicTacToe.hpp"
#include "Board.hpp"

using namespace std;

TicTacToe::TicTacToe(char player){
    PlayerTurn = player;
}

string TicTacToe::Play(){
    do {
        gameBoard.print();
        string input;
        cout << "Player " << PlayerTurn << "'s turn to go:" << endl;
        while(!input.length()){
            getline(cin, input);
        }
        int x = input[0] - '0';
        int y = input[2] - '0';
        bool move = gameBoard.makeMove(x, y, PlayerTurn);
        while(!move){
            cout << "Space taken, please enter another space:" << endl;
            getline(cin, input);
            x = input[0] - '0';
            y = input[2] - '0';
            move = gameBoard.makeMove(x, y, PlayerTurn);
        };
        if(PlayerTurn == 'x'){
            PlayerTurn = 'o';
        } else {
            PlayerTurn = 'x';
        }
        input = "";
    } while (gameBoard.gameState() == INPROGRESS);
    State end = gameBoard.gameState();
    gameBoard.print();
    switch(end){
        case XWON:
            return "Player 'x' won!";
            break;
        case OWON:
            return "Player 'o' won!";
            break;
        case DRAW:
            return "The game is a draw";
            break;
        default:
            return "ERROR: SOMETHING WENT WRONG";
    }
};

int main(){
    cout << "TIC TAC TOE!" << endl;
    cout << "Who would like to go first? (x or o)" << endl;
    char in;
    cin >> in;
    TicTacToe game = TicTacToe(in);
    string result = game.Play();
    cout << result << endl;
    return 0;
}
