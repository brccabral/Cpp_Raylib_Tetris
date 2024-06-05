#pragma once
#include <raylib.h>
#include <vector>

class Grid
{
public:

    Grid();

    void Draw();
    bool IsCellOutside(int row, int column);

    int grid[20][20] = {};

private:

    int numRows;
    int numCols;
    int cellSize;

    std::vector<Color> colors;
};
