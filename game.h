#pragma once
#include "block.h"
#include "grid.h"

class Game
{
public:

    Game();
    [[nodiscard]] Block getRandomBlock() const;
    void Draw();
    void handleInput();
    void moveBlockDown();
    Grid grid;

private:

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
