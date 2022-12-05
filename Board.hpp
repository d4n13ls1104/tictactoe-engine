#include <vector>

#ifndef BOARD_H
#define BOARD_H

enum TileState {
    EMPTY = 0,
    WHITE = 1,
    BLACK = 2 
};

enum TerminalPosition {
    DRAW = 0,
    WHITE_WIN = 1,
    BLACK_WIN = -1
};

struct Move {
    int x;
    int y;
};

class Board {
    public:
        Board();
        ~Board();

        void draw();

        int checkWin();

        Move get_move_from_number(int n);

        void setPosition(int x, int y, int tileState) {
            _board[x][y] = tileState;
        }

        int getPosition(int x, int y) {
            return _board[x][y];
        }
        
    private:
        std::vector<std::vector<int>> _board
        {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
        };
};

#endif