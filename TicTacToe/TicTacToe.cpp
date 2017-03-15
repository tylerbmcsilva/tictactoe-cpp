/*
 Title: TicTacToe Class
 Date: 03/11/17
 Descrition: Runs the game of TicTacToe, facilitates which
 player goes when, and prints who the winner is at the end
 of the game!
*/

#include <stdlib.h>
#include <iostream>
#include <string>
#include <ctype.h>
#include <cstring>
#include "TicTacToe.hpp"
#include "Board.hpp"

using namespace std;

/*
 Contructor
 Takes the charcter of the player who is going first (X or O)
*/

TicTacToe::TicTacToe(char player){
    PlayerTurn = toupper(player);
}

/*
 Play
 Starts the game, gets the input from the user, makes the move,
 and switches players. Function ends when the gamestate is
 different than "INPROGRESS", then returns the result of the game
*/

string TicTacToe::Play(){
    do {
        gameBoard.print();
        string input;
        cout << "Player " << PlayerTurn << ": Please enter your move. (FORMAT: \"row column\")" << endl;
        while(!input.length()){
            getline(cin, input);
        }
        int x = input[2] - '0';
        int y = input[0] - '0';
        bool move = gameBoard.makeMove(x, y, PlayerTurn);
        while(!move){
            cout << "Space taken, please enter another space:" << endl;
            getline(cin, input);
            x = input[2] - '0';
            y = input[0] - '0';
            move = gameBoard.makeMove(x, y, PlayerTurn);
        };
        if(PlayerTurn == 'X'){
            PlayerTurn = 'O';
        } else {
            PlayerTurn = 'X';
        }
        input = "";
    } while (gameBoard.gameState() == INPROGRESS);
    State end = gameBoard.gameState();
    gameBoard.print();
    switch(end){
        case XWON:
            return "Player 'X' won!";
            break;
        case OWON:
            return "Player 'O' won!";
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
    cout << "Who would like to go first? (X or O)" << endl;
    char in;
    cin >> in;
    TicTacToe game = TicTacToe(in);
    string result = game.Play();
    cout << result << endl;
    return 0;
}
