#include "grid.h"
#include "colors.h"

Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    colors = getCellColors();
}

void Grid::Draw() const
{
    for (int row = 0; row < numRows; ++row)
    {
        for (int column = 0; column < numCols; ++column)
        {
            const int cellValue = grid[row][column];

            DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

bool Grid::IsCellOutside(const int row, const int column) const
{
    if (row >= 0 && row < numRows && column >= 0 && column < numCols)
    {
        return false;
    }
    return true;
}
