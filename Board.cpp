#include "Board.hpp"

Board* Board::instance=nullptr;

Board::Board(){
    chessBoard.resize(8, vector<Piece*> (8,nullptr));

    // create the board
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            ///blacks
            string color= i<4 ? "BLACK":"WHITE";
            if(i==1 || i==6) chessBoard[i][j]=new Pawn(color,i,j);
            if(i==0 || i==7){
                //rooks
                if(j==0 or j==7) chessBoard[i][j]=new Rook(color,i,j);
                //knight
                if(j==1 or j==6) chessBoard[i][j]=new Knight(color,i,j);
                //bishop
                if(j==2 or j==5) chessBoard[i][j]=new Bishop(color,i,j);
                //king
                if(j==3) chessBoard[i][j]=new King(color,i,j);
                //queen
                if(j==4) chessBoard[i][j]=new Queen(color,i,j);
            }
            
        }
    }
}

Board* Board::getInstance(){
    if(instance==nullptr){
        instance=new Board();
    }

    return instance;
}

void Board::updateBoard(int initial_row,int initial_col,int end_row,int end_col,string& status){
    if(chessBoard[end_row][end_col]!=nullptr){
        if(chessBoard[end_row][end_col]->symbol=='E') {status= (chessBoard[end_row][end_col]->color=="WHITE" ? "BLACK" : "WHITE"); status+=" WON";}
        delete chessBoard[end_row][end_col];
    }
    chessBoard[end_row][end_col]=chessBoard[initial_row][initial_col];
    chessBoard[end_row][end_col]->updatePos(end_row,end_col);
    chessBoard[initial_row][initial_col]=nullptr;
}

void Board::printBoard(){
    map<string, string> pieceSymbols = {
    {"WHITE_E", "♔"}, {"BLACK_E", "♚"},
    {"WHITE_Q", "♕"}, {"BLACK_Q", "♛"},
    {"WHITE_R", "♖"}, {"BLACK_R", "♜"},
    {"WHITE_B", "♗"}, {"BLACK_B", "♝"},
    {"WHITE_K", "♘"}, {"BLACK_K", "♞"},
    {"WHITE_P", "♙"}, {"BLACK_P", "♟"}
};

    string white = "\033[1;37m";
    string black = "\033[1;30m";
    string reset = "\033[0m";


    cout<<"  ";
    for(int i=0;i<8;i++) cout<<i<<" ";
    cout<<endl;
    for(int i=0;i<8;i++){
        cout<<i<<" ";
        for(int j=0;j<8;j++){
            if(chessBoard[i][j]==nullptr) cout<<".";
            else{
                string temp=chessBoard[i][j]->color + "_";
                temp+=chessBoard[i][j]->symbol;
                string icon=pieceSymbols[temp];
                cout<<(chessBoard[i][j]->color == "WHITE" ? white : black)<<icon<<reset;
            }
            cout<<" ";
        }
        cout<<endl;
    }
}