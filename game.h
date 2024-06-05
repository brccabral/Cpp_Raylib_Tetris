#pragma once
#include "block.h"
#include "grid.h"

class Game
{
public:

    Game();
    [[nodiscard]] Block getRandomBlock();
    void Draw();
    void handleInput();
    void moveBlockDown();

    Grid grid;
    bool gameOver = false;
    int score = 0;

private:

    static std::vector<Block> GetAllBlocks();
    void moveBlockLeft();
    void moveBlockRight();
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void UpdateScore(int linesCleared, int moveDownPoints);

    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};
