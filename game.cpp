#include "game.h"

#include <ctime>
#include <random>

Game::Game()
{
    std::srand((unsigned int) time(0));
    blocks = {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
}

Block Game::getRandomBlock() const
{
    const int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    return block;
}

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw();
}

void Game::handleInput()
{
    int keyPressed = GetKeyPressed();
    switch (keyPressed)
    {
        case KEY_LEFT:
        {
            moveBlockLeft();
            break;
        }
        case KEY_RIGHT:
        {
            moveBlockRight();
            break;
        }
        case KEY_DOWN:
        {
            moveBlockDown();
            break;
        }
        case KEY_UP:
        {
            RotateBlock();
            break;
        }
    }
}

void Game::moveBlockLeft()
{
    currentBlock.Move(0, -1);
    if (IsBlockOutside())
    {
        currentBlock.Move(0, 1);
    }
}

void Game::moveBlockRight()
{
    currentBlock.Move(0, 1);
    if (IsBlockOutside())
    {
        currentBlock.Move(0, -1);
    }
}

void Game::moveBlockDown()
{
    currentBlock.Move(1, 0);
    if (IsBlockOutside())
    {
        currentBlock.Move(-1, 0);
    }
}

bool Game::IsBlockOutside()
{
    std::vector<Position> tiles = currentBlock.getCellPositions();
    for (const auto tile: tiles)
    {
        if (grid.IsCellOutside(tile.row, tile.column))
        {
            return true;
        }
    }
    return false;
}

void Game::RotateBlock()
{
    currentBlock.Rotate();
}
