#include <iostream>
#include "Board.hpp"
#include "Engine.hpp"

using namespace std;

Board _board;
Engine _engine;

void input_move() {
    int result = _board.checkWin();

    if(result == WHITE_WIN) {
        cout << endl << "Result: AI Won";
        return;
    }
    if(result == BLACK_WIN) {
        cout << endl << "Result: Human Won";
        return;
    }
    if(result == DRAW) {
        cout << endl << "Result: Draw";
        return;
    }

    int moveNumber;
    cout << "Please enter your move (1-9): ";
    cin >> moveNumber;

    Move move = _board.get_move_from_number(moveNumber);

    if(moveNumber > 9 || moveNumber <= 0 || _board.getPosition(move.x, move.y) != EMPTY) {
        cout << "Illegal move" << endl;
        input_move();
    }

    _board.setPosition(move.x, move.y, BLACK);
    _engine.move(_board, WHITE);

    input_move();

}

int main() {
    _engine.move(_board, WHITE);
    input_move();
    return 0;
}