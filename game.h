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

private:

    static std::vector<Block> GetAllBlocks();
    void moveBlockLeft();
    void moveBlockRight();
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();

    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};
