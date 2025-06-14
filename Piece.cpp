#include "Piece.hpp"

Piece::Piece(string color,char symbol, int row, int col) : color(color),symbol(symbol), curr_row(row), curr_col(col) {}
void Piece::updatePos(int new_row,int new_col){
    curr_row=new_row;
    curr_col=new_col;
}

Pawn::Pawn(string color,int row,int col):Piece(color,'P',row,col){};
Rook::Rook(string color,int row,int col):Piece(color,'R',row,col){};
Bishop::Bishop(string color,int row,int col):Piece(color,'B',row,col){};
Knight::Knight(string color,int row,int col):Piece(color,'K',row,col){};
Queen::Queen(string color,int row,int col):Piece(color,'Q',row,col){};
King::King(string color,int row,int col):Piece(color,'E',row,col){};

bool Pawn::validateMove(int row,int col,vector<vector<Piece*>>& board){
    int direction= (color=="BLACK")? 1:-1;
    
    //move straight
    if(row==curr_row+direction && col==curr_col) return board[row][col]==nullptr;

    //moving oblique
    if(row==curr_row+direction && (col==curr_col+1 || col==curr_col-1)) return board[row][col]!=nullptr && color!=board[row][col]->color;

    return false;
}

bool Rook::validateMove(int row,int col,vector<vector<Piece*>>& board){
    if(row!=curr_row && col!=curr_col) return false;
    if(board[row][col]!=nullptr && board[row][col]->color==color) return false;

    int dir_x= row>curr_row? 1:-1;
    if(row==curr_row) dir_x=0;
    int dir_y=col>curr_col? 1:-1;
    if(col==curr_col) dir_y=0;

    for(int i=curr_row+dir_x,j=curr_col+dir_y;i!=row || j!=col;i+=dir_x,j+=dir_y){
        if(board[i][j]!=nullptr) return false;
    }
    return true;
}

bool Bishop::validateMove(int row,int col,vector<vector<Piece*>>& board){
    if(abs(row-curr_row)!=abs(col-curr_col)) return false;
    if(board[row][col]!=nullptr && board[row][col]->color==color) return false;

    int dir_x= row>curr_row? 1:-1;
    if(row==curr_row) dir_x=0;
    int dir_y=col>curr_col? 1:-1;
    if(col==curr_col) dir_y=0;

    for(int i=curr_row+dir_x,j=curr_col+dir_y;i!=row || j!=col;i+=dir_x,j+=dir_y){
        if(board[i][j]!=nullptr) return false;
    }
    return true;
}

bool Knight::validateMove(int row,int col,vector<vector<Piece*>>& board){
    if(row==curr_row || col==curr_col || abs(row-curr_row)+abs(col-curr_col)!=3) return false;
    if(board[row][col]!=nullptr && board[row][col]->color==color) return false;

    return true;
}

bool Queen::validateMove(int row,int col,vector<vector<Piece*>>& board){
    if(row!=curr_row && col!=curr_col && abs(row-curr_row)!=abs(col-curr_col)) return false;
    if(board[row][col]!=nullptr && board[row][col]->color==color) return false;

    int dir_x= row>curr_row? 1:-1;
    if(row==curr_row) dir_x=0;
    int dir_y=col>curr_col? 1:-1;
    if(col==curr_col) dir_y=0;

    for(int i=curr_row+dir_x,j=curr_col+dir_y;i!=row || j!=col;i+=dir_x,j+=dir_y){
        if(board[i][j]!=nullptr) return false;
    }
    return true;
}

bool King::validateMove(int row,int col,vector<vector<Piece*>>& board){
    if(row!=curr_row && col!=curr_col && abs(row-curr_row)!=abs(col-curr_col)) return false;
    if(abs(row-curr_row)>1 || abs(col-curr_col)>1) return false;
    if(board[row][col]!=nullptr && board[row][col]->color==color) return false;

    int dir_x= row>curr_row? 1:-1;
    if(row==curr_row) dir_x=0;
    int dir_y=col>curr_col? 1:-1;
    if(col==curr_col) dir_y=0;

    for(int i=curr_row+dir_x,j=curr_col+dir_y;i!=row || j!=col;i+=dir_x,j+=dir_y){
        if(board[i][j]!=nullptr) return false;
    }
    return true;
}