#ifndef PIECE_HPP
#define PIECE_HPP

#include <iostream>
using namespace std;

class Piece{
    
    public:
        string color;
        char symbol;
        int curr_row,curr_col;
        Piece(string,char,int,int);
        virtual bool validateMove(int,int,vector<vector<Piece*>>&)=0;
        void updatePos(int,int);
        virtual ~Piece(){};
};

class Pawn: public Piece{
    public:
        Pawn(string,int,int);
        bool validateMove(int,int,vector<vector<Piece*>>&);

};

class Rook: public Piece{
    public:
        Rook(string,int,int);
        bool validateMove(int,int,vector<vector<Piece*>>&);

};

class Bishop: public Piece{
    public:
        Bishop(string,int,int);
        bool validateMove(int,int,vector<vector<Piece*>>&);

};

class Knight: public Piece{
    public:
        Knight(string,int,int);
        bool validateMove(int,int,vector<vector<Piece*>>&);

};

class Queen: public Piece{
    public:
        Queen(string,int,int);
        bool validateMove(int,int,vector<vector<Piece*>>&);

};

class King: public Piece{
    public:
        King(string,int,int);
        bool validateMove(int,int,vector<vector<Piece*>>&);

};

#endif