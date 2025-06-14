#ifndef BOARD_HPP
#define BOARD_HPP

#include "Piece.hpp"
#include<iostream>
#include<map>
using namespace  std;

class Board{
    public:
    vector<vector<Piece*>> chessBoard;
    static Board* getInstance();
    void updateBoard(int,int,int,int,string&);
    void printBoard();
    private:
    static Board* instance;
    Board();
};

#endif