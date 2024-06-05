#pragma once
#include "block.h"
#include "grid.h"

class Game
{
public:

    Game();
    Block getRandomBlock();
    void Draw();
    Grid grid;

private:

    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};
