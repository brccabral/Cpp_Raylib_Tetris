#pragma once
#include "block.h"
#include "grid.h"

class Game
{
public:

    Game();
    ~Game();
    void Draw();
    void handleInput();
    void moveBlockDown();

    bool gameOver = false;
    int score = 0;
    Music music;

private:

    [[nodiscard]] Block getRandomBlock();
    static std::vector<Block> GetAllBlocks();
    void moveBlockLeft();
    void moveBlockRight();
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void UpdateScore(int linesCleared, int moveDownPoints);

    Grid grid;
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};
