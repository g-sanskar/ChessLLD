#include "Game.hpp"

Game::Game(){
    board=Board::getInstance();
    status="GAME CREATED";
}

bool Game::validPieceSelected(string turn,int row,int col){
    return board->chessBoard[row][col]!=nullptr && board->chessBoard[row][col]->color==turn;
}

void Game::makeMove(string& status){
    cout<<turn<<" "<<"turn to play"<<endl;

    while(1){
        cout<<"input piece position you want to move e.g. 1 2"<<endl;
        int piece_row,piece_col;
        cin>>piece_row>>piece_col;
        if(!validPieceSelected(turn,piece_row,piece_col)) {cout<<"Invalid Piece Selection"<<endl; continue;}

        bool deselect=0;
        while(1){
            cout<<"input position you want to move to e.g 1 2"<<endl;
            int target_row,target_col;
            cin>>target_row>>target_col;
            if(target_col==piece_col and target_row==piece_row) {deselect=1; break;}
            if(!board->chessBoard[piece_row][piece_col]->validateMove(target_row,target_col,board->chessBoard)) {cout<<"Invalid Move"<<endl; continue;}

            board->updateBoard(piece_row,piece_col,target_row,target_col,status);
            break;
        }
        
        if(deselect) continue;
        break;
    }
}

void Game::start(){
    status="ONGOING";
    turn="WHITE";

    while(status=="ONGOING"){
        board->printBoard();
        makeMove(status);
        turn= turn=="WHITE"? "BLACK":"WHITE";
    }

    cout<<status<<endl;
}