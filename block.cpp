#include "block.h"

Block::Block() : cellSize(30), rotationState(0), rowOffset(0), columnOffset(0)
{
    colors = getCellColors();
    Move(0, 3);
}

void Block::Draw()
{
    std::vector<Position> tiles = getCellPositions();

    for (const Position tile: tiles)
    {
        DrawRectangle(tile.column * cellSize + 1, tile.row * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
    }
}

void Block::Move(int rows, int columns)
{
    rowOffset += rows;
    columnOffset += columns;
}

std::vector<Position> Block::getCellPositions()
{
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;
    for (const Position tile: tiles)
    {
        Position newPos = Position(tile.row + rowOffset, tile.column + columnOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

void Block::Rotate()
{
    rotationState++;
    if (rotationState == cells.size())
    {
        rotationState = 0;
    }
}
