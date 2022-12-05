#include "Board.hpp"

#ifndef ENGINE_H
#define ENGINE_H

struct EngineMove {
    int x;
    int y;
    int score;
};

class Engine {
    public:
        Engine();
        ~Engine();

        void move(Board& board, int player);
        int getNodes() {
            return _nodes;
        }
        void setNodes(int n) {
            _nodes = n;
        }
    
    private:
        EngineMove _generateMove(Board& board, int player, int depth);
        int _nodes;
};

#endif