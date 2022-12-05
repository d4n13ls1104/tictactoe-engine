#include "Engine.hpp"
#include <iostream>

Engine::Engine() {}
Engine::~Engine() {}

void Engine::move(Board& board, int player) {
    EngineMove bestMove = _generateMove(board, player, 1);
    board.setPosition(bestMove.x, bestMove.y, player);
    board.draw();
    std::cout << std::endl << "Nodes: " << getNodes() << std::endl;
    setNodes(0);
}

EngineMove Engine::_generateMove(Board& board, int player, int depth) {
    setNodes(getNodes()+1);
    int result = board.checkWin();
    if(result == WHITE_WIN) {
        EngineMove move;
        move.score = 10;
        return move;
    } else if (result == BLACK_WIN) {
        EngineMove move;
        move.score = -10;
        return move;
    } else if (result == DRAW) {
        EngineMove move;
        move.score = 0;
        return move;
    }

    std::vector<EngineMove> moves;

    for(int x = 0; x < 3; x++) {
        for(int y = 0; y < 3; y++) {
            if(board.getPosition(x, y) == EMPTY) {
                EngineMove move;
                move.x = x;
                move.y = y;

                board.setPosition(x, y, player);
                if(player == WHITE) {
                    move.score = _generateMove(board, BLACK, depth + 1).score;
                } else {
                    move.score = _generateMove(board, WHITE, depth + 1).score;
                }

                moves.push_back(move);
                board.setPosition(x, y, EMPTY);
            }
        }
    }

    int bestMove = 0;
    if(player == WHITE) {
        int bestScore = -1000000;
        for(int i = 0; i < moves.size(); i++) {
            if(moves[i].score > bestScore) {
                bestMove = i;
                bestScore = moves[i].score;
            }
        }
    } else {
        int bestScore = 1000000;
        for(int i = 0; i < moves.size(); i++) {
            if(moves[i].score < bestScore) {
                bestMove = i;
                bestScore = moves[i].score;
            }
        }
    }
    return moves[bestMove];
}