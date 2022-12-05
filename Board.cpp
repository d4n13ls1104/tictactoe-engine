#include <iostream>
#include "Board.hpp"

Board::Board() {};
Board::~Board() {};

void Board::draw() {
    system("cls");
    for(int x = 0; x < 3; x++) {
        for(int y = 0; y < 3; y++) {
            switch(getPosition(x, y)) {
                case EMPTY:
                    std::cout << "#";
                    break;
                case WHITE: 
                    std::cout << "X";
                    break;
                case BLACK:
                    std::cout << "O";
                    break;
            }
        }
        std::cout << std::endl;
    }
}

int Board::checkWin() {
    if(
        (getPosition(0, 0) == WHITE && getPosition(0, 1) == WHITE && getPosition(0, 2) == WHITE) ||
        (getPosition(1, 0) == WHITE && getPosition(1, 1) == WHITE && getPosition(1, 2) == WHITE) ||
        (getPosition(2, 0) == WHITE && getPosition(2, 1) == WHITE && getPosition(2, 2) == WHITE) ||
        (getPosition(0, 0) == WHITE && getPosition(1, 0) == WHITE && getPosition(2, 0) == WHITE) ||
        (getPosition(0, 1) == WHITE && getPosition(1, 1) == WHITE && getPosition(2, 1) == WHITE) ||
        (getPosition(0, 2) == WHITE && getPosition(1, 2) == WHITE && getPosition(2, 2) == WHITE) ||
        (getPosition(0, 0) == WHITE && getPosition(1, 1) == WHITE && getPosition(2, 2) == WHITE) ||
        (getPosition(0, 2) == WHITE && getPosition(1, 1) == WHITE && getPosition(2, 0) == WHITE) 
    ) return WHITE_WIN;

    if(
        (getPosition(0, 0) == BLACK && getPosition(0, 1) == BLACK && getPosition(0, 2) == BLACK) ||
        (getPosition(1, 0) == BLACK && getPosition(1, 1) == BLACK && getPosition(1, 2) == BLACK) ||
        (getPosition(2, 0) == BLACK && getPosition(2, 1) == BLACK && getPosition(2, 2) == BLACK) ||
        (getPosition(0, 0) == BLACK && getPosition(1, 0) == BLACK && getPosition(2, 0) == BLACK) ||
        (getPosition(0, 1) == BLACK && getPosition(1, 1) == BLACK && getPosition(2, 1) == BLACK) ||
        (getPosition(0, 2) == BLACK && getPosition(1, 2) == BLACK && getPosition(2, 2) == BLACK) ||
        (getPosition(0, 0) == BLACK && getPosition(1, 1) == BLACK && getPosition(2, 2) == BLACK) ||
        (getPosition(0, 2) == BLACK && getPosition(1, 1) == BLACK && getPosition(2, 0) == BLACK)
    ) {
        return BLACK_WIN;
    }

    for(int x = 0; x < 3; x++) { 
        for(int y = 0; y < 3; y++) {
            if(getPosition(x, y) == EMPTY) return -2;
        }
    }
    
    return DRAW;
}

Move Board::get_move_from_number(int n) {
    Move move;
    if(n < 4) {
        move.x = 0;
        move.y = n - 1;
    }
    if(n > 3 && n < 7) {
        move.x = 1;
        move.y = n - 4;
    }
    if(n > 6 && n < 10) {
        move.x = 2;
        move.y = n - 7;
    }
    return move;
}