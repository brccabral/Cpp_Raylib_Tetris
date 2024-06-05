#pragma once
#include <raylib.h>
#include <vector>

class Grid
{
public:

    Grid();

    void Draw();

    int grid[20][20] = {};

private:

    int numRows;
    int numCols;
    int cellSize;

    std::vector<Color> colors;
};
