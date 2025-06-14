#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include<iostream>
using namespace std;

class Game{
    public:
    Board* board;
    string status;
    string turn;

    Game();
    void start();
    void makeMove(string&);
    bool validPieceSelected(string,int,int);
};

#endif