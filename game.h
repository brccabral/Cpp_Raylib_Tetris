#pragma once
#include "block.h"
#include "grid.h"

class Game
{
public:

    Game();
    Block getRandomBlock() const;
    void Draw();
    void handleInput();
    void moveBlockLeft();
    void moveBlockRight();
    void moveBlockDown();
    Grid grid;

private:

    bool IsBlockOutside();

    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};
