#include "game.h"
#include <ctime>

Game::Game()
{
    SetRandomSeed(static_cast<unsigned int>(time(nullptr)));
    Reset();
}

Block Game::getRandomBlock()
{
    // loop through all blocks before repeating
    if (blocks.empty())
    {
        blocks = GetAllBlocks();
    }
    const int randomIndex = GetRandomValue(0, 7) % static_cast<int>(blocks.size());
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
    currentBlock.Draw(11, 11);
    switch (nextBlock.id)
    {
        case 3:
        {
            nextBlock.Draw(255, 290);
            break;
        }
        case 4:
        {
            nextBlock.Draw(255, 280);
            break;
        }
        default:
        {
            nextBlock.Draw(270, 270);
            break;
        }
    }
}

void Game::handleInput()
{
    const int keyPressed = GetKeyPressed();
    if (gameOver && keyPressed != 0)
    {
        gameOver = false;
        Reset();
    }
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
            UpdateScore(0, 1);
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
    if (gameOver)
    {
        return;
    }
    currentBlock.Move(0, -1);
    if (IsBlockOutside() || !BlockFits())
    {
        currentBlock.Move(0, 1);
    }
}

void Game::moveBlockRight()
{
    if (gameOver)
    {
        return;
    }
    currentBlock.Move(0, 1);
    if (IsBlockOutside() || !BlockFits())
    {
        currentBlock.Move(0, -1);
    }
}

void Game::moveBlockDown()
{
    if (gameOver)
    {
        return;
    }
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
    if (gameOver)
    {
        return;
    }
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
    if (!BlockFits())
    {
        gameOver = true;
    }
    nextBlock = getRandomBlock();
    const int rowsCleared = grid.ClearFullRows();
    UpdateScore(rowsCleared, 0);
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

void Game::Reset()
{
    grid.Initialize();
    blocks = GetAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
    score = 0;
}

void Game::UpdateScore(const int linesCleared, const int moveDownPoints)
{
    switch (linesCleared)
    {
        case 1:
        {
            score += 100;
            break;
        }
        case 2:
        {
            score += 300;
            break;
        }
        case 3:
        {
            score += 500;
            break;
        }
        default:
        {
            break;
        }
    }

    score += moveDownPoints;
}
