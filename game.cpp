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

Block Game::getRandomBlock()
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
