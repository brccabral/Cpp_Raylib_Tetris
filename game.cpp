#include "game.h"
#include <ctime>

Game::Game()
{
    SetRandomSeed(static_cast<unsigned int>(time(nullptr)));
    blocks = GetAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
}

Block Game::getRandomBlock()
{
    // loop through all blocks before repeating
    if (blocks.empty())
    {
        blocks = GetAllBlocks();
    }
    const int randomIndex = GetRandomValue(0, 6) % static_cast<int>(blocks.size());
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::GetAllBlocks()
{
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw();
}

void Game::handleInput()
{
    switch (GetKeyPressed())
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
        default:
        {
            break;
        }
    }
}

void Game::moveBlockLeft()
{
    currentBlock.Move(0, -1);
    if (IsBlockOutside() || !BlockFits())
    {
        currentBlock.Move(0, 1);
    }
}

void Game::moveBlockRight()
{
    currentBlock.Move(0, 1);
    if (IsBlockOutside() || !BlockFits())
    {
        currentBlock.Move(0, -1);
    }
}

void Game::moveBlockDown()
{
    currentBlock.Move(1, 0);
    if (IsBlockOutside() || !BlockFits())
    {
        currentBlock.Move(-1, 0);
        LockBlock();
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
    // avoid rotate to invalid position
    if (IsBlockOutside() || !BlockFits())
    {
        currentBlock.UndoRotate();
    }
}

void Game::LockBlock()
{
    std::vector<Position> tiles = currentBlock.getCellPositions();
    for (const Position tile: tiles)
    {
        grid.grid[tile.row][tile.column] = currentBlock.id;
    }
    currentBlock = nextBlock;
    nextBlock = getRandomBlock();
}

bool Game::BlockFits()
{
    std::vector<Position> tiles = currentBlock.getCellPositions();
    for (const Position tile: tiles)
    {
        if (!grid.IsCellEmpty(tile.row, tile.column))
        {
            return false;
        }
    }
    return true;
}
