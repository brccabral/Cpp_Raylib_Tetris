#include "grid.h"
#include "colors.h"

Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    colors = getCellColors();
}

void Grid::Draw()
{
    for (int row = 0 ; row <  numRows; ++row)
    {
        for (int column = 0; column < numCols; ++column)
        {
            int cellValue = grid[row][column];

            DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}
